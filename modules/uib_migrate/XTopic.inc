<?php
/**
 * @file
 * Representation of a ZTM Topic from w2.
 *
 * The old www.uib.no server's data is based on the ZTM Topic map model.
 * The content objects are called topics, and the xtopic view is a way to
 * expose these as XML.  The XTopic class is a way to consume these documents
 * from PHP (in a way suitable for use by the Drupal migrate module).
 */

class XTopic extends stdClass {
  private static $w2_server;

  /**
   * Returns the URL of the server to read xtopic documents from.
   *
   * This defaults to 'teststring.uib.no', but you can override this by setting
   * the 'uib_w2_server' configuration variable.
   */
  public static function url($path='topicmap/@@xtopic') {
    if (is_null(self::$w2_server)) {
      self::$w2_server = variable_get('uib_w2_server', 'teststring.uib.no');
    }
    return 'http://' . self::$w2_server . '/' . $path;
  }
  private static function type_map($w2_type) {
    static $type_map = array(
      'fakultet' => 'faculty',
      'institutt' => 'institute',
      'avdeling' => 'unit',
      'forskningsgruppe' => 'research group',
      'forskerskole' => 'research school',
      'seksjon' => 'section',
    );
    if (isset($type_map[$w2_type]))
      return $type_map[$w2_type];
    return $w2_type;
  }

  /**
   * Creates a new XTopic object from the given $id.
   *
   * @param $id
   *   The topic id; usually a huge integer.  Also a called topic serial number.
   *   You might also provide a string on the form "username:$username" to look
   *   up users directly based on their UiB user name.
   *
   *  Will throw an exception if a topic with the given id can't be found.
   *  The exception will have a 'code' of 404 in that case.
   *
   * @param $shallow
   *   If TRUE don't fetch related topics
   *
   * @param $reason
   *   Using during logging to explain why this topic was instantiated.
   */

  public function __construct($id, $shallow=FALSE, $reason=NULL) {
    if (substr($id, 0, 9) == 'username:') {
      $url = XTopic::url() . "?username=" . substr($id, 9);
    }
    else {
      $url = XTopic::url() . "?id=$id";
    }

    $log_msg = 'GET ' . $url;
    if ($reason) {
      $log_msg .= ' (' . $reason . ')';
    }
    uibx_log($log_msg);

    $xml = simplexml_load_file($url);
    $topic = $xml->topic;
    if (empty($topic)) {
      throw new Exception("Topic $id not found", 404);
    }
    $this->id = (string)$topic['id'];
    $this->title = (string)$topic->title;
    $this->state = (string)$topic['state'];
    $this->path = substr($topic['path'], 1);
    $this->path = preg_replace('/\\/en($|\\/)/', '$1', $this->path);
    $this->url = substr($topic['url'], 1);
    $this->slug = basename($this->path);
    $this->type = XTopic::type_map((string)$topic->type['name']);

    $site = (string)$topic->site['ref'];
    $this->is_site = $site == $id;
    if ($this->is_site) {
      $this->no_site = (string)$topic->site['no_site'] or $this->no_site = $site;
    }
    else {
      $this->site = $site;
    }
    $this->site_lang = (string)$topic->site['lang'];
    if ($this->site_lang == 'no') {
      $this->site_lang = 'nb'; // Drupal uses nb/nn (bokmål/nynorsk)
    }

    foreach ($topic->profiletext as $profiletext) {
      $this->profiletext .= (string)$profiletext;
      if ($profiletext["image_ref"] && $profiletext["href"] ) {
        $this->profiletext .= sprintf("<a href='%s'><img src='%s'></a>", $profiletext['href'], $profiletext['image_ref']);
        $this->profileimages[] = (string)$profiletext["image_ref"];
      }
      elseif ($profiletext["image_ref"]) {
        $this->profiletext .= sprintf("<img src='%s'>", $profiletext['image_ref']);
        $this->profileimages[] = (string)$profiletext["image_ref"];
      }

    }
    foreach ($topic->field as $field) {
      if ($field['name'] == 'psi') {
        $value = (string)$field;
        $this->{$field['name']}[] = $value;
        $arr = explode('?omraadekode=', $value);
        if (count($arr) == 2) {
          $this->omraadekode = preg_replace('/_en$/', '', $arr[1]);
        }
      }
      elseif ($field['name'] == 'menuorder') {
        // We only care about the version of 'menuorder' that's scoped with
        // the current site.
        if ((string)$field['scope'] != (string)$topic->site['ref']) {
          continue;
        }
        $this->menuorder = (string)$field;
      }
      elseif ($field['name'] == 'original') {
        $start7 = substr($field, 0, 7);
        if ($start7 == 'http://' || $start7 == 'https:/')
          continue;
        $this->original = (string)$field;
      }
      else {
        $fname = $field['name'];
        if ($field['scope']) {
          $fname .= ':' . $field['scope'];
        }
        $this->$fname = (string)$field;
      }
    }

    $xlink = array();
    foreach ($topic->xlink as $x) {
      $xlink[(string)$x['name']][] = (string)$x['ref'];
    }

    if (!empty($xlink['subordinate/hierarchical-relation/superordinate'])) {
      $this->nav_parent_id = $xlink['subordinate/hierarchical-relation/superordinate'][0];
      if (!$shallow) {
        $parent = new XTopic($this->nav_parent_id, TRUE, 'parent of ' . $id);
        //$this->parent = $parent;
        if (isset($parent->menuorder)) {
          $menu_order = $parent->menuorder;
          $menu_order = drupal_json_decode($menu_order);
          $idx = array_search($this->id, $menu_order);
          if ($idx !== FALSE)
            $this->nav_weight = $idx;
        }
        if (!isset($this->nav_weight)) {
          uibx_log("Can't find $this->id in the menu of its parent $this->nav_parent_id", 'warning');
        }
      }
      if ($this->nav_parent_id == $topic->site['ref']) {
        unset($this->nav_parent_id);
        $this->menu_top_entry = TRUE;
      }
    }

    if (!empty($xlink['er_tilknyttet/tilknytning/har_tilknyttet'])) {
      $this->area_parent_ids =  $xlink['er_tilknyttet/tilknytning/har_tilknyttet'];
    }

    if (!empty($xlink['er_skrevet_av/forfatterskap/har_skrevet'])) {
      $this->byline =  $xlink['er_skrevet_av/forfatterskap/har_skrevet'];
    }

    if (isset($topic->{'workflow-transition'})) {
      foreach ($topic->{'workflow-transition'} as $transition) {
        if ($transition['action'] == 'publish') {
          if ($transition['user']) {
            $this->author =  (string)$transition['user'];
          }
        }
      }
    }

    if (!empty($xlink['decorated/stort_hovedtekstbilde/decoration'])) { // Main image for article
      $this->main_media = $xlink['decorated/stort_hovedtekstbilde/decoration'][0];
    }

    if (!empty($xlink['decorated/personbilde/decoration'])) { // Main image for users
      // Can reuse safely reuse main_media here
      $this->main_media = $xlink['decorated/personbilde/decoration'][0];
    }

    if (!empty($xlink['decorated/hovedtekstbilde/decoration'])) { // Inline images
      $this->media = $xlink['decorated/hovedtekstbilde/decoration'];
    }

    if (!empty($xlink['has_attachment/vedlegg/attachment'])) {
      $this->attachments = $xlink['has_attachment/vedlegg/attachment'];
    }

    if (!empty($xlink['har_kontaktperson/kontaktperson/er_kontaktperson_for'])) {
      $this->contacts = $xlink['har_kontaktperson/kontaktperson/er_kontaktperson_for'];
    }

    if (!empty($xlink['omtaler/omtale/omtalt'])) {
      $relatedprogrammes = array();

      foreach ($xlink['omtaler/omtale/omtalt'] as $programme) {
        $omtalt = new XTopic($programme, TRUE, 'omtalt');
        if ($omtalt->type == 'studieprogram') {
          $relatedprogrammes[] = $omtalt->studieprogramkode;
        }
        else {
          uibx_log("Relation (omtalt) to $omtalt->type dropped", 'warning');
        }
      }

      $this->related_programmes = $relatedprogrammes;
    }
  }

  /**
   * Listing of the fields that might be set for an XTopic object.
   *
   * @returns
   *   An array with the field identifiers as keys and a short documentation
   *   string as value.
   */
  public static function fields() {
    return array(
      'id' => t('Topic serial number (and identifier)'),
      'title' => t('Title'),
      'psi' => t('Public Subject Idendentifer'),
      'state' => t('Publishing state; one of private, published, retracted'),
      'path' => t('The path of the topic in the database'),
      'slug' => t('Last part of the path'),
      'type' => t('What kind of topic is this'),
      'site' => t('What site does this topic belong to (serial)'),
      'site_lang' => t('What\'s the the language of the site this topic belongs to'),
      'created' => t('When was this topic created, ISO datetime'),
      'modified' => t('When was this topic last modified, ISO datetime'),
      'effectivedate' => t('Publishing date, ISO datetime'),
      'stikktittel' => t('Kicker'),
      'dc_description' => t('Summary of the article'),
      'text' => t('The main text of the article or area; raw HTML'),
      'profiletext' => t('The norwegian profile text area; raw HTML'),
      'omraadekode' => t('Sebra Area ID'),
      'nav_parent_id' => t('The serial number of the parent topic (applies for InfoPages and NavPages)'),
      'nav_weight' => t('Sort order among siblings'),
      'area_parent_ids' => t('The serial numbers of the area parents'),
      'author' => t('The author of the article (serial)'),
      'main_media' => t('Media file used in article'),
      'attachment' => t('Attachment(s) added to content'),
      'media' => t('Media inline image(s)'),
      'contacts' => t('Contacts for events'),
      'location' => t('Location for events'),
      'fullkampanjetittel' => t('Norwegian main title for Areas'),
      'menypunkttittel' => t('Menu title for infopages and navpages'),

      # Testimonial
      'name' => t('Name for testimonial'),
      'position' => t('Position for testimonial'),
      'education' => t('Education for testimonial'),
      'exchange_place' => t('Exchange place for testimonial'),
      'exchange_text' => t('Exchange text for testimonial'),
      'quote' => t('Quote for testimonial'),
      'organization' => t('Organization for testimonial'),
      'related_programmes' => t('Related studyprogrammes'),

      # User fields
      'uib-id' => t('Username at UiB'),
      'epost' => t('E-mail address'),
      'fornavn' => t('First name'),
      'etternavn' => t('Last name'),
      'stilling' => t('Position at UiB'),
      'stillingskode' => t('Position code'),
      'stillingskategori' => t('Position category'),
    );
  }

  public static function getKeySchema() {
    return array(
      'id' => array(
        'type' => 'varchar',
        'length' => 32,
        'not null' => TRUE,
      ),
    );
  }
}

/**
 * Listing of topics of a given type.
 */
class XTopicListSource extends MigrateSource {
  private $type;
  private $listUrl;
  private $count;
  private $offset;
  private $ids;
  private $w2AreaSubset;

  /**
   * Create a new listing object.
   *
   * If the 'uib_test_dir' configuration variable is set, the listings will be
   * picked up from '$dir/$type.csv' files in the given directory.  This is
   * useful during development and debugging.  The variable currently defaults
   * to 'test-jur', so by default we will only migrate the objects set up
   * for this test case.
   *
   * @param $type
   *   What type of topics to list.  Is a string like 'navigationpage' or
   *   'infopage' or 'area'.
   */
  public function __construct($type) {
    parent::__construct();
    $this->type = $type;
    $this->listUrl = XTopic::url() . "?type=$type";
    if ($type == 'area' || $type == 'event') {
      $this->listUrl .= '&allinstances';
    }
    if (function_exists('drush_get_option')) {
      $area_subset_filename = drush_get_option('area_subset');
      if (!empty($area_subset_filename)) {
        // If supplied, read a file that contains an explicit list of areas which are to be migrated
        if ($this->w2AreaSubset = file(dirname(__FILE__) . DIRECTORY_SEPARATOR . $area_subset_filename)) {
          for ($i=count($this->w2AreaSubset)-1; $i>=0; $i--) {
            $this->w2AreaSubset[$i] = trim($this->w2AreaSubset[$i]); // strip line ends
            if (empty($this->w2AreaSubset[$i])) {
              array_splice($this->w2AreaSubset, $i, 1); // remove empty lines
            }
            elseif (substr($this->w2AreaSubset[$i], 0, 1)=='#') {
              array_splice($this->w2AreaSubset, $i, 1); // discard comment lines
            }
          }
        }
        else {
          uibx_log("Unable to read area list: \"$area_subset_filename\". Terminating!", 'error');
          exit;
        }
      }
    }
  }

  public function __toString() {
    return $this->listUrl;
  }

  public function fields() {
    return XTopic::fields();
  }

  private function moreIds() {
   if (1) {
      // Force a limited set of source stuff to be available to
      // speed up debugging during development

      // Check if a list of ids were specified on the command line with the option --serial
      if (function_exists('drush_get_option')) {
        $serial = drush_get_option('serial');
        if ($serial) {
          $this->ids = explode(',', $serial);
          $this->count = count($this->ids);
          $this->offset += $this->count;
          return;
        }
      }
      // Else, look for xtopic CSV files as alternative indexes
      // Used if the 'uib_test_dir' variable was set to a local subdirectory
      // Else, no limited set of ids will be used
      $csv_file = dirname(__FILE__) . '/'
        . variable_get('uib_test_dir', 'test-jur') . '/'
        . $this->type . '.csv';
      $fh = @fopen($csv_file, 'r');
      if ($fh) {
        $this->ids = array();
        while ($data = fgetcsv($fh)) {
          $id = $data[1];
          if ($id == 'id') { // skip header line
            continue;
          }
          $this->ids[] = $id;
        }
        fclose($fh);

        $this->count = count($this->ids);
        $this->offset += $this->count;
        return;
      }
    }

    // No limiting set of ids was found
    // Go get all ids in sets of 50
    $url = $this->listUrl . "&limit=50&offset=$this->offset";
    uibx_log('GET ' . $url);
    $xml = simplexml_load_file($url);
    if ($this->offset == 0) {
      $range = explode('/', $xml['range']);
      $this->count = $range[1];
    }

    // Get list of ids to ignore
    static $bad_apple;
    if (!isset($bad_apple)) {
      $bad_apple = array();
      foreach (file(dirname(__FILE__) . '/etc/bad-apples.txt') as $line) {
        $line = explode('#', $line, 2);  // ignore trailing comments
        $id = trim($line[0]);
        if ($id)
          $bad_apple[$id] = TRUE;
      }
    }

    $ids = array();
    $cntr = 0;
    foreach ($xml->topic as $t) {
      $cntr++;
      $id = (string)$t['id'];
      // Check if this id is to be ignored
      if (isset($bad_apple[$id])) {
        uibx_log("Bad apple $id, skipped", 'warning');
        continue;
      }
      // Check if there is a limiting set of areas
      // and if the current record is within this set.
      if (!empty($this->w2AreaSubset)) {
        $path = (string)$t['path'];
        $notInSubset = TRUE;
        foreach ($this->w2AreaSubset as $subsetArea) {
          $path = ltrim($path, "/");
          if (substr($path, 0, strlen($subsetArea)) == $subsetArea) {
            $notInSubset = FALSE;
            //uibx_log("$subsetArea found in " . substr($path, 0, 35) . "...", 'notice');
            break;
          }
        }
        if ($notInSubset) {
          continue;
        }
      }
      $ids[] = $id;
    }
    $this->ids = $ids;
    $this->offset += $cntr;
  }

  public function performRewind() {
    $this->offset = 0;
    $this->moreIds(); // need to set $count
  }

  public function computeCount() {
    if (is_null($this->count)) {
      $this->offset = 0;
      $this->moreIds();
    }
    return $this->count;
  }

  /**
   * Returns the next XTopic object.
   */
  public function getNextRow() {
    while (!$this->ids && $this->offset < $this->count) {
      $this->moreIds();
    }
    if ($this->ids) {
      return new XTopic(array_shift($this->ids));
    }
    return NULL;
  }

}
