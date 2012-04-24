<?php

abstract class XTopicToArticleMigration extends Migration {
  public $topic_type;   // to be overridden
  public $article_type; // to be overridden

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('article', array('area')));

    $this->source = new XTopicListSource($this->topic_type);
    $this->destination = new MigrateDestinationNode('uib_article');

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_uib_w2_path', 'path');
    $this->addFieldMapping('field_uib_article_type', 'article_type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('language', 'site_lang');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('field_uib_date', 'start_date'); // handled in 'prepare' for EventMigration
    $this->addFieldMapping('field_uib_kicker', 'stikktittel');
    $this->addFieldMapping('field_uib_lead', 'dc_description');
    $this->addFieldMapping('field_uib_text', 'text');
    $this->addFieldMapping('field_uib_w2_parent_id', 'parent_id');
    $this->addFieldMapping('field_uib_weight', 'weight');
    $this->addFieldMapping('field_uib_area', 'site')
      ->sourceMigration('Area')
      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_main_media', 'main_media_file');
    $this->addFieldMapping('field_uib_main_media:filename')->defaultValue('foo title');;
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    $row->article_type = $this->article_type;

    if ($row->main_media) {
      $media_file = $this->getMedia($row->main_media);
      drush_log('Media file found: ' . $media_file, $type='notice');
      $row->main_media_file = $media_file;
    }
  }

  public function getMedia(&$media) {
    $media_url = XTopic::url() . "?id=" . $media;
    drush_log('Media search, loading: ' .$media_url, $type='notice');
    $xml = simplexml_load_file($media_url);
    $topic = $xml->topic;
    $media_file = $topic->field[2];
    $title = $topic->title; // File title
    //drush_log('Media title: ' . $title, $type='notice');
    $media_file = 'http://' .XTopic::$w2_server ."/". $media_file;
    $foo = array (
      'media_uri' => $media_file,
      'title' => $title,
      );
    return $media_file;
  }
}

class InfoPageMigration extends XTopicToArticleMigration {
  public $topic_type = 'infopage';
  public $article_type = 'infopage';
}

class NavPageMigration extends InfoPageMigration {
  public $topic_type = 'navigationpage';
  public $article_type = 'infopage';
}

class NewsMigration extends XTopicToArticleMigration {
  public $topic_type = 'newsItem';
  public $article_type = 'news';
}

class EventMigration extends XTopicToArticleMigration{
  public $topic_type = 'event';
  public $article_type= 'event';

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->article_type = $row->type;

  }

  public function prepare($node, stdClass $row) {
    $node->field_uib_date['und'][0]['value'] = $row->start_date;
    $node->field_uib_date['und'][0]['value2'] = $row->end_date;
  }
}

class AreaMigration extends Migration {
  private $vid;

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('area'));

    $this->source = new XTopicListSource('area');

    $destination_machine_name = 'area';

    $this->destination = new MigrateDestinationTerm($destination_machine_name);

    // Get the $vid of the destination
    $vids = array_keys(taxonomy_vocabulary_load_multiple(
      array(),
      array('machine_name' => $destination_machine_name)
    ));
    $this->vid = $vids[0];

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'title');
    $this->addFieldMapping('description')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_uib_trans_text', 'text')
      ->arguments(array('language' => 'nb'));
    $this->addFieldMapping('field_uib_area_type', 'type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_sebra_id', 'omraadekode');
    $this->addFieldMapping('field_uib_area_parents', 'area_parent_ids')
      ->sourceMigration('Area')
      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_uib_ou'); // handled in 'prepare'
  }

  protected function createStub($migration, $source_id) {
    $term = new stdClass;
    $term->vid = $this->vid;
    $term->name = t('Stub for ') . $source_id[0];
    $term->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    taxonomy_term_save($term);
    return array($term->tid);
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

class UserMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('user', array('area')));

    $this->source = new XTopicListSource('person');
    $this->destination = new MigrateDestinationUser();

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationUser::getKeySchema()
    );

    $this->addFieldMapping('name', 'uib-id');
    $this->addFieldMapping('mail', 'epost');
    $this->addFieldMapping('status')->defaultValue(1);  // activated
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_first_name', 'fornavn');
    $this->addFieldMapping('field_uib_last_name', 'etternavn');
    $this->addFieldMapping('field_uib_position', 'stilling');
  }

  protected function createStub($migration, $source_id) {
    $user = new stdClass;
    $user->name = t('Stub for ') . $source_id[0];
    $user->mail = 'nobody@uib.no';
    $user->status = 0;
    $user->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    user_save($user);
    return array($user->uid);
  }
}
