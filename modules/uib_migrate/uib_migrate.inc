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
    $this->addFieldMapping('field_uib_links', 'hjemmeside'); // handled in 'prepare' for EventMigration
    $this->addFieldMapping('field_uib_location', 'sted');
    $this->addFieldMapping('field_uib_contacts', 'contacts')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_kicker', 'stikktittel');
    $this->addFieldMapping('field_uib_lead', 'dc_description');
    $this->addFieldMapping('field_uib_text', 'text');
    $this->addFieldMapping('field_uib_w2_nav_parent_id', 'nav_parent_id');
    $this->addFieldMapping('field_uib_nav_parent', 'nav_parent_id')
      ->sourceMigration('NavPage');
    $this->addFieldMapping('field_uib_nav_weight', 'nav_weight');
    $this->addFieldMapping('field_uib_area', 'site')
      ->sourceMigration('Area')
      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_main_media', 'main_media');
    $this->addFieldMapping('field_uib_media', 'media');
    $this->addFieldMapping('field_uib_main_media:filename')->defaultValue('foo title');
    $this->addFieldMapping('field_uib_files', 'attachment');
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    $row->article_type = $this->article_type;
  }
}

class InfoPageMigration extends XTopicToArticleMigration {
  public $topic_type = 'infopage';
  public $article_type = 'infopage';
}

class NavPageMigration extends InfoPageMigration {
  public $topic_type = 'navigationpage';
  public $article_type = 'infopage';

  protected function createStub($migration, $source_id) {
    $node = new stdClass;
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->title = t('Navigation stub for ') . $source_id[0];
    $node->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    node_save($node);
    return array($node->nid);
  }

  public function complete($node, $row) {
    if (isset($row->menu_top_entry)) {
      // Determine the menu_link of the corresponding area
      $result = db_select('menu_links')
        ->fields('menu_links', array('mlid', 'link_path'))
        ->condition('menu_name', 'area')
        ->condition('link_path', 'taxonomy/term/' . $node->field_uib_area['und'][0]['tid'])
        ->condition('depth', 1);
      foreach($result->execute() as $item) {
        $area_mlid = $item->mlid;
      }

      // Create top level area menu link
      $menu_link = array(
        'menu_name' => 'area',
        'link_path' => drupal_get_normal_path('node/' . $node->nid),
        'link_title' => $node->title,
        'weight' => $row->nav_weight,
        'plid' => $area_mlid,
      );
      menu_link_save($menu_link);
    }
  }
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
    //Prevent empty links instances
    if (!empty($row->hjemmeside)){
          $node->field_uib_links['und'][0]['url'] = $row->hjemmeside;
          $node->field_uib_links['und'][0]['title'] = $row->lenketekst;
    }
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
    $this->addFieldMapping('field_uib_area_type', 'type')->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_sebra_id', 'omraadekode');
    $this->addFieldMapping('field_uib_area_parents', 'area_parent_ids')
      ->sourceMigration('Area')
      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_uib_ou'); // handled in 'prepare'
    //$this->addFieldMapping('field_uib_main_media', 'media'); // It's not main_media!

    // Can't get this to work; so we just transfer the values in the prepare
    // callback instead.
    //
    //$this->addFieldMapping('field_uib_trans_text', 'text')
    //  ->arguments(array('language' => 'nb'));
    //$this->addFieldMapping('field_uib_trans_text', 'text_en')
    //  ->arguments(array('language' => 'en'));
  }

  protected function createStub($migration, $source_id) {
    $term = new stdClass;
    $term->vid = $this->vid;
    $term->name = t('Area stub for ') . $source_id[0];
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
    // Handle the translatable files here.  The field mapping can't deal with
    // multiple source values mapping to a single translatable field
    $term->field_uib_trans_text['nb'][0]['value'] = $row->text;
    $term->field_uib_trans_text['en'][0]['value'] = $row->text_en;

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

    if ($row->media) {
      $file = new stdClass();
      $filename = 'public://' . drupal_basename($row->media[0]);
      $filename = file_destination($filename, FILE_EXISTS_RENAME);
      if (!@copy($row->media[0], $filename)) {
        die("Could not copy file " . $row->media[0] . "\n");
      }
      $file->filename = drupal_basename($filename);
      $file->uri = $filename;
      $file->uid = 1;
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      if (!$file->fid) {
        die("Could not save file");
      }
      //print_r($file);
      $term->field_uib_main_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }

    //print_r($term);
  }

  public function complete($term, $row) {
    $menu_link = array(
      'menu_name' => 'area',
      'link_path' => drupal_get_normal_path('taxonomy/term/' . $term->tid),
      'link_title' => $term->name,
    );
    menu_link_save($menu_link);
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
    $user->name = t('User stub for ') . $source_id[0];
    $user->mail = 'nobody@uib.no';
    $user->status = 0;
    $user->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    user_save($user);
    return array($user->uid);
  }
}
