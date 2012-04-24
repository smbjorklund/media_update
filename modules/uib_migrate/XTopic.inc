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
      else {
        $this->$field['name'] = (string)$field;
      }
    }

    foreach ($topic->xlink as $xlink) {
      $this->xlink[(string)$xlink['name']][] = (string)$xlink['ref'];
    }

    if(!empty($this->xlink['subordinate/hierarchical-relation/superordinate'])) {
      $this->parent_id = $this->xlink['subordinate/hierarchical-relation/superordinate'][0];
      if (!$shallow) {
        $parent = new XTopic($this->parent_id, TRUE, 'parent of ' . $id);
        //$this->parent = $parent;
        $menu_order = $parent->menuorder;
        $menu_order = drupal_json_decode($menu_order);
        $this->weight = array_search($this->id, $menu_order);
      }
    }

    if (!empty($this->xlink['er_tilknyttet/tilknytning/har_tilknyttet'])) {
      $this->area_parent_ids =  $this->xlink['er_tilknyttet/tilknytning/har_tilknyttet'];
    }
    if (!empty($this->xlink['er_skrevet_av/forfatterskap/har_skrevet'])) {
      $this->author =  $this->xlink['er_skrevet_av/forfatterskap/har_skrevet'][0];
    }
    if (!empty($this->xlink['decorated/hovedtekstbilde/decoration'])) {
      $this->main_media = $this->xlink['decorated/hovedtekstbilde/decoration'][0]; //Todo: iterate and make sure we pick up all file recources.
    }
    if (!empty($this->xlink['has_attachment/vedlegg/attachment'])) {
      $attachments_id = $this->xlink['has_attachment/vedlegg/attachment'];
      $files = array();
      foreach ($attachments_id as $attachment) {
        $attachment = ($this->getAttachment($attachment));
        drush_log('Attachment found: ' . $attachment);
        $files[] = $attachment;
      }
      $this->attachment = $files;
    }
  }

  public function getAttachment(&$attachment_id) {
    $file_url = XTopic::url() . "?id=" . $attachment_id;
    $xml = simplexml_load_file($file_url);
    $topic = $xml->topic;
    return 'http://' .XTopic::$w2_server ."/". $topic->field[2];
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
      'parent_id' => t('The serial number of the parent topic (applies for InfoPages and NavPages)'),
      'weight' => t('Sort order among siblings'),
      'area_parent_ids' => t('The serial numbers of the area parents'),
      'author' => t('The author of the article (serial)'),
      'main_media_file' => t('Media file used in article'),
      'attachment' => t('Attachment(s) added to content'),

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
      $fh = @fopen(dirname(__FILE__) . '/' . $this->type . '.csv', 'r');
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
