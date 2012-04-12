<?php

class XTopic extends stdClass {
  public static $w2_server;
  public static function url() {
    if (is_null(self::$w2_server)) {
      self::$w2_server = variable_get('uib_w2_server', 'testbool.uib.no');
    }
    return "http://" . self::$w2_server . "/topicmap/@@xtopic";
  }

  public function __construct($id) {
    $url = XTopic::url() . "?id=$id";
    $this->id = $id;
    $xml = simplexml_load_file($url);
    $topic = $xml->topic;
    if (empty($topic)) {
      throw new Exception("Topic $id not found");
    }
    $this->title = (string)$topic->title;
    $this->state = (string)$topic['state'];
    $this->path = substr($topic['path'], 1);
    $this->type = (string)$topic->type['name'];
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
  }

  public static function fields() {
    return array(
      'id' => t('Topic serial number (and identifier)'),
      'title' => t('Title'),
      'psi' => t('Public Subject Idendentifer'),
      'state' => t('Publishing state; one of private, published, retracted'),
      'path' => t('The path of the topic in the database'),
      'type' => t('What kind of topic is this'),
      'created' => t('When was this topic created, ISO datetime'),
      'modified' => t('When was this topic last modified, ISO datetime'),
      'effectivedate' => t('Publishing date, ISO datetime'),
      'stikktittel' => t('Kicker'),
      'dc_description' => t('Summary of the article'),
      'text' => t('The main text of the article; raw HTML'),
      'omraadekode' => t('Sebra Area ID'),
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
  private $listUrl;
  private $count;
  private $offset;
  private $ids;

  public function __construct($type) {
    parent::__construct();
    $this->listUrl = XTopic::url() . "?type=$type";
    if ($type == 'area') {
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
    $url = $this->listUrl . "&offset=$this->offset";
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

abstract class XTopicToArticleMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('xtopic'));

    $this->source = new XTopicListSource($this->topic_type);
    $this->destination = new MigrateDestinationNode('uib_article');

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_uib_w2_path', 'path');
    $this->addFieldMapping('field_uib_article_type')->defaultValue($this->topic_type)->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('field_uib_kicker', 'stikktittel');
    $this->addFieldMapping('field_uib_lead', 'dc_description');
    $this->addFieldMapping('field_uib_text', 'text');
  }
}

class InfoPageMigration extends XTopicToArticleMigration {
  public $topic_type = 'infopage';
}

class NewsItem extends XTopicToArticleMigration {
  public $topic_type = 'newsItem';
}

class AreaMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('xtopic'));

    $this->source = new XTopicListSource('area');
    $this->destination = new MigrateDestinationTerm('area');

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'title');
    $this->addFieldMapping('description', 'text');
    $this->addFieldMapping('field_uib_area_type', 'type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_uib_sebra_id', 'omraadekode');
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    if ($row->alpha2_code != 'no') {
      return FALSE;
    }
  }

  public function prepare($term, $row) {
    if ($row->placeid) {
      // Check if we already have a 'uib_ou' node with the given placeid
      $query = new EntityFieldQuery;
      $result = $query
        ->entityCondition('entity_type', 'node')
        ->fieldCondition('field_uib_ou_id', 'value', $row->placeid, '=')
        ->range(0,1)
        ->execute();
      if (!empty($result['node'])) {
        $nids = array_keys($result['node']);
        $term->field_uib_ou['und'][0]['target_id'] = $nids[0];
      }
      else {
        // Create a new 'oib_ou' node
        $place = new SebraPlace($row->placeid);
        $node = new stdClass();
        $node->type = 'uib_ou';
        $node->title = $place->name;
        $node->uid = 1;
        $node->status = 1;
        $node->revision = 0;
        $node->language = 'und';
        $node->field_uib_ou_id['und'][0]['value'] = $row->placeid;
        $node->field_uib_ou_shortname['und'][0]['value'] = $place->alias;

        $node->field_uib_postal_address['und'][0]['thoroughfare'] = 'Postboks ' . $place->postbox;
        $node->field_uib_postal_address['und'][0]['postal_code'] = $place->postcode;
        $node->field_uib_postal_address['und'][0]['locality'] = $place->postarea;
        $node->field_uib_postal_address['und'][0]['country'] = 'NO';

        $node->field_uib_visit_address['und'][0]['thoroughfare'] = $place->address;
        $node->field_uib_visit_address['und'][0]['postal_code'] = $place->postcode;
        $node->field_uib_visit_address['und'][0]['locality'] = $place->postarea;
        $node->field_uib_visit_address['und'][0]['country'] = 'NO';

        node_save($node);
        $term->field_uib_ou['und'][0]['target_id'] = $node->nid;
      }
    }
    //print_r($term);
  }
}
