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
    print "$url\n";
    $this->id = $id;
    $xml = simplexml_load_file($url);
    $topic = $xml->topic;
    $this->title = (string)$topic->title;
  }

  public static function fields() {
    return array(
      'id' => t('TopicID'),
      'title' => t('Title'),
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
    print "$url\n";
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

  public function rewind() {
    $this->offset = 0;
    $this->moreIds();
    $this->next();
  }

  public function computeCount() {
    if (is_null($this->count)) {
      $this->offset = 0;
      $this->moreIds();
    }
    return $this->count;
  }

  public function next() {
    if (!$this->ids && $this->offset < $this->count) {
      $this->moreIds();
    }
    if ($this->ids) {
      $row = $this->currentRow = new XTopic(array_shift($this->ids));
      $this->currentKey=array($row->id);
    }
    else {
      $this->currentRow = NULL;
      $this->currentKey = NULL;
    }
  }
}

abstract class XTopicToArticleMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('xtopic'));

    $this->source = new XTopicListSource($this->topic_type);
    $this->destination = new MigrateDestinationNode('uib_article');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
	'id' => array(
	  'type' => 'varchar',
	  'length' => 32,
	  'not null' => TRUE,
	),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('title', 'title');
  }
}

class InfoPageMigration extends XTopicToArticleMigration {
  public $topic_type = 'infopage';
}

class NewsItem extends XTopicToArticleMigration {
  public $topic_type = 'newsItem';
}
