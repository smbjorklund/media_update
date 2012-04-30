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
    $this->type = (string)$topic->type['name'];

    $site = (string)$topic->site['no_site'] or $site = (string)$topic->site['ref'];
    if ($site != $id) {
      $this->site = $site;
    }
    $this->site_lang = $topic->site['lang'];
    if ($this->site_lang == 'no') {
      $this->site_lang = 'nb'; // Drupal uses nb/nn (bokmål/nynorsk)
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
        if ($field['datatype'] == 'anyUri') {
          $start7 = substr($field, 0, 7);
          if ($start7 == 'http://' || $start7 == 'https:/')
            continue;
        }
        $this->original = (string)$field;
      }
      else {
        $this->$field['name'] = (string)$field;
      }
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
    }

    if (!empty($xlink['er_tilknyttet/tilknytning/har_tilknyttet'])) {
      $this->area_parent_ids =  $xlink['er_tilknyttet/tilknytning/har_tilknyttet'];
    }

    if (!empty($xlink['er_skrevet_av/forfatterskap/har_skrevet'])) {
      $this->author =  $xlink['er_skrevet_av/forfatterskap/har_skrevet'][0];
    }

    if (!empty($xlink['decorated/stort_hovedtekstbilde/decoration'])) { // Main image for article
      $media_id = $xlink['decorated/stort_hovedtekstbilde/decoration'];
      $media_uri = array();
      foreach ($media_id as $id) {
        $media_uri[] = $this->getMedia($id);
      }
      $this->main_media = $media_uri;
    }

    if (!empty($xlink['decorated/hovedtekstbilde/decoration'])) { // Inline images
      $media_id = $xlink['decorated/hovedtekstbilde/decoration'];
      $media_uri = array();
      foreach ($media_id as $id) {
        $media_uri[] = $this->getMedia($id);
      }
      $this->media = $media_uri;
    }

    if (!empty($xlink['has_attachment/vedlegg/attachment'])) {
      $attachment_id = $xlink['has_attachment/vedlegg/attachment'];
      $attachment_uri = array();
      foreach ($attachment_id as $id) {
        $attachment_uri[] = ($this->getAttachment($id));
      }
      $this->attachment = $attachment_uri;
    }

    if (!empty($xlink['har_kontaktperson/kontaktperson/er_kontaktperson_for'])) {
      $this->contacts = $xlink['har_kontaktperson/kontaktperson/er_kontaktperson_for'];
    }
  }

  public function getMedia($id) {
    $topic = new XTopic($id, TRUE, 'media');
    $path = $topic->original;
    $media_uri = "http://" . XTopic::$w2_server . "/" . $path;
    //drush_log('getMedia() found: ' . $media_uri, $type='notice');
    return $media_uri;
  }

  public function getAttachment($id) {
    $topic = new XTopic($id, TRUE, 'attachment');
    $path = $topic->path;
    $attachment_uri = "http://" . XTopic::$w2_server . "/" . $path;
    //drush_log('Attachment found: ' . $attachment_uri, $type='notice');
    return $attachment_uri;
  }

  public function getMeta($id) {
    $topic = new XTopic($id, TRUE, 'meta');
    $title = $topic->title;
    $photographer = $topic->field['photographer'];
    drush_log($title . 'taken by: ' . $photographer, $type='notice');
    return;
  }

  public static function fields() {
    return array(
      'id' => t('Topic serial number (and identifier)'),
      'title' => t('Title'),
      'psi' => t('Public Subject Idendentifer'),
      'state' => t('Publishing state; one of private, published, retracted'),
      'path' => t('The path of the topic in the database'),
      'type' => t('What kind of topic is this'),
      'site' => t('What site does this topic belong to (serial)'),
      'site_lang' => t('What\'s the the language of the site this topic belongs to'),
      'created' => t('When was this topic created, ISO datetime'),
      'modified' => t('When was this topic last modified, ISO datetime'),
      'effectivedate' => t('Publishing date, ISO datetime'),
      'stikktittel' => t('Kicker'),
      'dc_description' => t('Summary of the article'),
      'text' => t('The main text of the article; raw HTML'),
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

    $url = $this->listUrl . "&offset=$this->offset";
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
