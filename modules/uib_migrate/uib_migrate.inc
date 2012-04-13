<?php

abstract class XTopicToArticleMigration extends Migration {
  public $topic_type;   // to be overridden
  public $article_type; // to be overridden

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
    $this->addFieldMapping('field_uib_article_type')->defaultValue($this->article_type)->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('field_uib_kicker', 'stikktittel');
    $this->addFieldMapping('field_uib_lead', 'dc_description');
    $this->addFieldMapping('field_uib_text', 'text');
    $this->addFieldMapping('field_uib_w2_parent_id', 'parent_id');
  }

  public function prepare($node, $row) {
    // Locate the area this article belongs to
    //
    // The only connection we have is that the source path will be "under" the
    // path of the area, but we don't know the number of segments in the area
    // path, so we start searching for the longest path prefix that map to a
    // taxonomy term; and then just assume this will be the area.
    $tid = NULL;
    $segments = explode('/', $row->path);
    array_pop($segments); // no need to look for the topic itself
    while ($segments) {
      $term_path = drupal_get_normal_path(implode('/', $segments));
      if (substr($term_path, 0, 14) == 'taxonomy/term/') {
        $tid = substr($term_path, 14);
        $node->field_uib_area['und'][0]['tid'] = $tid;
        break;
      }
      array_pop($segments);
    }
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

class AreaMigration extends Migration {
  private $vid;

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('xtopic'));

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
    $this->addFieldMapping('description', 'text');
    $this->addFieldMapping('field_uib_area_type', 'type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_uib_sebra_id', 'omraadekode');
    $this->addFieldMapping('field_uib_area_parents', 'area_parent_ids')
      ->sourceMigration('Area')
      ->arguments(array('source_type' => 'tid'));
  }

  protected function createStub($migration, $source_id) {
    $term = new stdClass;
    $term->vid = $this->vid;
    $term->name = t('Stub for ') . $source_id[0];
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
