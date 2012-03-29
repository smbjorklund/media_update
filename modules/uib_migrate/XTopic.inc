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
      $this->$field['name'] = (string)$field;
    }
  }

  public static function fields() {
    return array(
      'id' => t('Topic serial number (and identifier)'),
      'title' => t('Title'),
      'state' => t('Publishing state; one of private, published, retracted'),
      'path' => t('The path of the topic in the database'),
      'type' => t('What kind of topic is this'),
      'created' => t('When was this topic created, ISO datetime'),
      'modified' => t('When was this topic last modified, ISO datetime'),
      'effectivedate' => t('Publishing date, ISO datetime'),
      'stikktittel' => t('Kicker'),
      'dc_description' => t('Summary of the article'),
      'text' => t('The main text of the article; raw HTML'),
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

    $this->source = new XTopicListSource('faculty');
    $this->destination = new MigrateDestinationTerm('area');

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'title');
    $this->addFieldMapping('description', 'text');
    $this->addFieldMapping('field_uib_area_type', 'type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('path', 'path');
  }
}
