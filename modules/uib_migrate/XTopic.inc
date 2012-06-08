<?php

class XTopic extends stdClass {
  public static $w2_server;
  public static function url() {
    if (is_null(self::$w2_server)) {
      self::$w2_server = variable_get('uib_w2_server', 'testbool.uib.no');
    }
    return "http://" . self::$w2_server . "/topicmap/@@xtopic";
  }

  public function __construct($id, $shallow=FALSE, $reason=NULL) {
    $url = XTopic::url() . "?id=$id";
    $this->id = $id;
    if (function_exists('drush_log')) {
      $log_msg = 'GET ' . $url;
      if ($reason) {
        $log_msg .= ' (' . $reason . ')';
      }
      drush_log($log_msg);
    }
    $xml = simplexml_load_file($url);
    $topic = $xml->topic;
    if (empty($topic)) {
      throw new Exception("Topic $id not found");
    }
    $this->title = (string)$topic->title;
    $this->state = (string)$topic['state'];
    $this->path = substr($topic['path'], 1);
    $this->slug = basename($this->path);
    $this->type = (string)$topic->type['name'];

    $site = (string)$topic->site['no_site'] or $site = (string)$topic->site['ref'];
    $this->is_site = $site == $id;
    if (!$this->is_site) {
      $this->site = $site;
    }
    $this->site_lang = $topic->site['lang'];
    if ($this->site_lang == 'no') {
      $this->site_lang = 'nb'; // Drupal uses nb/nn (bokmål/nynorsk)
    }

    foreach ($topic->profiletext as $profiletext){
      $this->profiletext .= (string)$profiletext;
      if($profiletext["image_ref"] && $profiletext["href"] ){
        $this->profiletext .= sprintf ("<a href='%s'><img src='%s'></a>",$profiletext['href'], $profiletext['image_ref']);
        $this->profileimages[] = (string)$profiletext["image_ref"];
      }
      else if($profiletext["image_ref"]){
        $this->profiletext .= sprintf ("<img src='%s'>", $profiletext['image_ref']);
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

    if ($this->is_site and !$shallow and $topic->site['lang'] == 'no' and $topic->site['en_site']) {
      $en_topic = new XTopic($topic->site['en_site'], TRUE, 'english site');
      if (isset($en_topic->text))
        $this->text_en = $en_topic->text;
      if (isset($en_topic->profiletext))
        $this->profiletext_en = $en_topic->profiletext;
    }

    if ($this->is_site and !$shallow and $topic->site['lang'] == 'no' and $topic->site['en_site']) {
      $en_topic = new XTopic($topic->site['en_site'], TRUE, 'english site');
      if (isset($en_topic->fullkampanjetittel))
        $this->fullkampanjetittel_en = $en_topic->fullkampanjetittel;
    }

    $xlink = array();
    foreach ($topic->xlink as $x) {
      $xlink[(string)$x['name']][] = (string)$x['ref'];
    }

    if(!empty($xlink['subordinate/hierarchical-relation/superordinate'])) {
      $this->nav_parent_id = $xlink['subordinate/hierarchical-relation/superordinate'][0];
      if (!$shallow) {
        $parent = new XTopic($this->nav_parent_id, TRUE, 'parent of ' . $id);
        //$this->parent = $parent;
        $menu_order = $parent->menuorder;
        $menu_order = drupal_json_decode($menu_order);
        $this->nav_weight = array_search($this->id, $menu_order);
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
      foreach ($topic->{'workflow-transition'} as $transition){
        if ($transition['action'] == 'publish') {
          if ($transition['user']) {
            $this->author =  $transition['user'];
          }
        }
      }
    }

    if (!empty($xlink['decorated/stort_hovedtekstbilde/decoration'])) { // Main image for article
      $this->main_media = $xlink['decorated/stort_hovedtekstbilde/decoration'][0];
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

    if(!empty($xlink['omtaler/omtale/omtalt'])){
      $relatedprogrammes = array();

      foreach ($xlink['omtaler/omtale/omtalt'] as $programme) {
        $omtalt = new XTopic($programme, TRUE, 'omtalt');
        if ($omtalt->type == 'studieprogram') {
          $relatedprogrammes[] = $omtalt->studieprogramkode;
        }
        else {
          drush_log("Relation (omtalt) to $omtalt->type dropped", 'error');
        }
      }

      $this->related_programmes = $relatedprogrammes;
    }
  }

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
      'text_en' => t('The english main text of an area; raw HTML'),
      'profiletext' => t('The norwegian profile text area; raw HTML'),
      'profiletext_en' => t('The english profile text area; raw HTML'),
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
      'fullkampanjetittel_en' => t('English main title for Areas'),
      'menypunkttittel' => t('Menu title for infopages and navpages'),

      # Testimonial
      'name' => t('Name for testimonial'),
      'position' =>t('Position for testimonial'),
      'education' =>t('Education for testimonial'),
      'exchange_place' =>t('Exchange place for testimonial'),
      'exchange_text' =>t('Exchange text for testimonial'),
      'quote' =>t('Quote for testimonial'),
      'organization' =>t('Organization for testimonial'),
      'related_programmes' =>t('Related studyprogrammes'),

      # User fields
      'uib-id' => t('Username at UiB'),
      'epost' => t('E-mail address'),
      'fornavn' => t('First name'),
      'etternavn' => t('Last name'),
      'stilling' => t('Position at UiB'),
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

class XTopicListSource extends MigrateSource {
  private $type;
  private $listUrl;
  private $count;
  private $offset;
  private $ids;

  public function __construct($type) {
    parent::__construct();
    $this->type = $type;
    $this->listUrl = XTopic::url() . "?type=$type";
    if ($type == 'area' || $type == 'event') {
      $this->listUrl .= '&allinstances';
    }
  }

  public function __toString() {
    return $this->listUrl;
  }

  public function fields() {
    return XTopic::fields();
  }

  private function moreIds() {
    // Force a limited set of source stuff to be available to
    // speed up debugging during developemnt
    if (1) {
      if (function_exists('drush_get_option')) {
        $serial = drush_get_option('serial');
        if ($serial) {
          $this->ids = explode(',', $serial);
          $this->count = count($this->ids);
          $this->offset += $this->count;
          return;
        }
      }
      // Look for xtopic CSV files as alternative indexes
      $csv_file = dirname(__FILE__) . '/'
        . variable_get('uib_test_dir', 'test-jur') . '/'
        . $this->type . '.csv';
      $fh = @fopen($csv_file, 'r');
      if ($fh) {
        $this->ids = array();
        while ($data = fgetcsv($fh)) {
          $id = $data[1];
          if ($id == 'id') { continue; }  // skip header line
          $this->ids[] = $id;
        }
        fclose($fh);

        $this->count = count($this->ids);
        $this->offset += $this->count;
        return;
      }
    }

    $url = $this->listUrl . "&limit=50&&offset=$this->offset";
    if (function_exists('drush_log')) {
      drush_log('GET ' . $url);
    }
    $xml = simplexml_load_file($url);
    if ($this->offset == 0) {
      $range = explode('/', $xml['range']);
      $this->count = $range[1];
    }

    $ids = array();
    foreach ($xml->topic as $t) {
      $ids[] = (string)$t['id'];
    }
    $this->ids = $ids;
    $this->offset += count($ids);
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

  public function getNextRow() {
    if (!$this->ids && $this->offset < $this->count) {
      $this->moreIds();
    }
    if ($this->ids) {
      return new XTopic(array_shift($this->ids));
    }
    return NULL;
  }

}
