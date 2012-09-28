<?php
/**
 * @file
 * UIB w2 -> w3 migration code.
 */

function xtopic_cleanup($text) {
  return html_entity_decode($text, ENT_QUOTES, 'UTF-8');
}

/**
 * Returns the Drupal file object matching the given XTopic file object.
 *
 * @param $id
 *    XTopic $id.  The $id must reference an XTopic object of type 'file'.
 *
 * @returns
 *    A Drupal file object.  If the file has been seen before return the
 *    same Drupal object.  If not a new file object is created and stored
 *    in the Drupal database and then returned.
 */
function xtopic_file($id) {
  // Check if we already have a 'file' migrated from the same id, if so return it
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'file')
    ->fieldCondition('field_uib_w2_id', 'value', $id, '=')
    ->range(0, 1)
    ->execute();
  if (!empty($result['file'])) {
    $res = array_values($result['file']);
    return $res[0]; // will be a stdClass object with 'fid' set, which is good enough
  }

  // Fetch file meta info from w2
  $xtopic = new XTopic($id, FALSE, 'file');
  if ($xtopic->type == 'image') {
    $uri = $xtopic->original;
  }
  elseif ($xtopic->type == 'file') {
    $uri = $xtopic->file;
  }
  else {
    die("Unknown file type: " . $xtopic->type);
  }
  $uri = XTopic::url($uri);

  $file = new stdClass();

  $basename = drupal_basename($uri);
  $hash = strtolower(substr($basename, 0, 2));
  $dirname = 'public://w2/' . $hash;
  @drupal_mkdir($dirname, NULL, TRUE);
  $filename = "$dirname/$basename";
  $filename = file_destination($filename, FILE_EXISTS_RENAME);

  if (!@copy($uri, $filename)) {
    die("Could not copy file " . $uri . "\n");
  }

  if (isset($xtopic->photographer)) {
    $file->field_uib_owner['und'][]['value'] = $xtopic->photographer;
  }
  if (isset($xtopic->{1351138798041054899})) {
    $file->field_uib_copyright['und'][]['value'] = $xtopic->{1351138798041054899};
  }
  if (isset($xtopic->dc_description)) {
    $file->field_uib_description['und'][]['value'] = $xtopic->dc_description;
  }
  $file->field_uib_w2_id['und'][]['value'] = $id;
  $file->filename = $xtopic->title;
  $file->uri = $filename;
  $file->uid = 1;
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);
  if (!$file->fid) {
    die("Could not save file");
  }
  else {  //Touch timestamp to preserve timestamps from legacy system (w2).
    $file->timestamp = strtotime($xtopic->created);
    drupal_write_record('file_managed', $file, 'fid');
  }
  return $file;
}

/**
 * Base class for Article Migrations.
 */
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
    $this->addFieldMapping('field_uib_menu_title_w2', 'menypunkttittel');
    $this->addFieldMapping('field_uib_w2_path', 'path');
    $this->addFieldMapping('field_uib_article_type', 'article_type');
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
    $this->addFieldMapping('field_uib_nav_weight', 'nav_weight');
    $this->addFieldMapping('field_uib_area', 'site')
      ->sourceMigration('Area');
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_byline', 'byline')
      ->sourceMigration('User');
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    $row->article_type = $this->article_type;

    if (isset($row->text)) {
      $clean_text = xtopic_cleanup($row->text);
      $row->text = $clean_text;
    }
  }

  public function prepare($node, $row) {
    if (isset($row->main_media)) {
      $file = xtopic_file($row->main_media);
      $node->field_uib_main_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }

    if (!empty($row->media)) {
      foreach ($row->media as $file_id) {
        $file = xtopic_file($file_id);
        $node->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }

    if (!empty($row->attachments)) {
      foreach ($row->attachments as $file_id) {
        $file = xtopic_file($file_id);
        $node->field_uib_files['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }
  }
}

/**
 * Migrate w2 infopages to Articles.
 */
class InfoPageMigration extends XTopicToArticleMigration {
  public $topic_type = 'infopage';
  public $article_type = 'infopage';
}

/**
 * Migrate w2 naviation pages to Articles.
 *
 * We map them to 'infopages', so in w3 there isn't really a difference between
 * info pages and naviation pages.
 */
class NavPageMigration extends InfoPageMigration {
  public $topic_type = 'navigationpage';
  public $article_type = 'infopage';

  protected function createStub($migration, $source_id) {
    $node = new stdClass;
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->title = t('Navigation stub for') . $source_id[0];
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
        ->condition('link_path', 'node/' . $node->field_uib_area['und'][0]['target_id'])
        ->condition('depth', 1);
      foreach ($result->execute() as $item) {
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

/**
 * Migrate w2 newsItems to Articles of type news'.
 */
class NewsMigration extends XTopicToArticleMigration {
  public $topic_type = 'newsItem';
  public $article_type = 'news';
}

/**
 * Migrate w2 calendar entries to Articles.
 */
class EventMigration extends XTopicToArticleMigration {
  public $topic_type = 'event';
  public $article_type = 'event';

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->article_type = 'event';
  }

  public function prepare($node, $row) {
    parent::prepare($node, $row);
    $node->field_uib_date['und'][0]['value'] = $row->start_date;
    $node->field_uib_date['und'][0]['value2'] = $row->end_date;
    $node->field_uib_event_type['und'][0]['value'] = $row->article_type;
    //Prevent empty links instances
    if (!empty($row->hjemmeside)) {
          $node->field_uib_links['und'][0]['url'] = $row->hjemmeside;
          $node->field_uib_links['und'][0]['title'] = $row->lenketekst;
    }
  }
}

/**
 * Migrate w2 testimonials to w3
 *
 * (we have a separate testimonials type in w3 as
 * well).
 */
class TestimonialMigration extends Migration {

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('testimonial', array('area', 'user')));

    $this->source = new XTopicListSource('testimonial');
    $this->destination = new MigrateDestinationNode('uib_testimonial');

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('language', 'site_lang');
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('User');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_w2_path', 'path');
    $this->addFieldMapping('field_uib_lead', 'dc_description');
    $this->addFieldMapping('field_uib_text', 'text');
    $this->addFieldMapping('field_uib_position', 'stilling');
    $this->addFieldMapping('field_uib_education', 'utdanning');
    $this->addFieldMapping('field_uib_name', 'navn');
    $this->addFieldMapping('field_uib_quote', 'sitat');
    $this->addFieldMapping('field_uib_related_programmes', 'related_programmes');
    $this->addFieldMapping('field_uib_exchange_place', 'utvekslingssted');
    $this->addFieldMapping('field_uib_exchange_text', 'utvekslingsavsnitt');
    $this->addFieldMapping('field_uib_organization', 'organisation');
    $this->addFieldMapping('field_uib_area', 'site')
      ->sourceMigration('Area');

  }
  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }

    if (!empty($row->psi)) {
      if (strpos($row->psi[0], "WorkflowUtility_storeOldTopicVersion/autogeneratedsubjectidentifierbytmserial") !== FALSE) {
        return FALSE;
      }
    }
  }

  public function prepare($node, $row) {

    if (!empty($row->media)) {
      foreach ($row->media as $file_id) {
        $file = xtopic_file($file_id);
        $node->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }
  }

}

/**
 * Migrate w2 research topics to the research_topic taxonomy.
 *
 * Currently only deals with the Norwegian variant of these.
 */
class ResearchTopicMigration extends Migration {

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('tags'));

    $this->source = new XTopicListSource('forskningstema');
    $this->destination = new MigrateDestinationTerm('research_topic_no');
    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'title');

  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    // skip the letter range categories present in the old data
    if (preg_match('/^[a-z]-([a-z]|å)$/', $row->title)) {
      return FALSE;
    }
  }
}

/**
 * Migrate w2 areas to w3.
 */
class AreaMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('area'));

    $this->source = new XTopicListSource('area');

    $destination_machine_name = 'area';

    $this->destination = new MigrateDestinationNode($destination_machine_name);

    $this->map = new MigrateSQLMap($this->machineName,
      XTopic::getKeySchema(),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('language', 'site_lang');
    $this->addFieldMapping('description')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_uib_area_type', 'type');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_sebra_id', 'omraadekode');
    $this->addFieldMapping('field_uib_area_parents', 'area_parent_ids')
      ->sourceMigration('Area');
    $this->addFieldMapping('field_uib_ou'); // handled in 'prepare'
    //$this->addFieldMapping('field_uib_main_media', 'media'); // It's not main_media!
    $this->addFieldMapping('field_uib_text', 'text');
    $this->addFieldMapping('field_uib_text2', 'profiletext');
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass;
    $node->type = 'area';
    $node->title = t('Area stub for') . $source_id[0];
    $node->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    node_save($node);
    return array($node->nid);
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
  }

  public function prepare($term, $row) {
    if (isset($row->placeid)) {
      // Check if we already have a 'uib_ou' node with the given placeid
      $nid = uib_sebra__uib_ou_nid($row->placeid);
      if ($nid) {
        $term->field_uib_ou['und'][0]['target_id'] = $nid;
      }
      else {
        // Create a new 'uib_ou' node
        $node = uib_sebra__create_uib_ou($row->placeid);
        $term->field_uib_ou['und'][0]['target_id'] = $node->nid;
      }
    }

    if (isset($row->media)) {
      $file = xtopic_file($row->media[0]);
      $term->field_uib_main_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }

    if (isset($row->profileimages)) {
      foreach ($row->profileimages as $file_id) {
        $file = xtopic_file($file_id);
        $term->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }
    //print_r($term);
  }

  public function complete($node, $row) {
    // Set tnid; can't map it directly because we can't map to ourself
    $node->tnid = $row->no_site == $row->id ? $node->nid :
      $this->handleSourceMigration('Area', array($row->no_site), NULL, $this);
    unset($node->path);  // avoids setting the alias twice
    node_save($node);

    $weight = array_search($row->type, array(
      'fakultet', 'institutt', 'enhet',
      'section',
      'forskningsgruppe', 'forskerskole',
    ));
    if ($weight === FALSE) {
      $weight = 99;
    }

    $menu_link = array(
      'menu_name' => 'area',
      'link_path' => drupal_get_normal_path('node/' . $node->nid),
      'link_title' => $node->title . ' (mlink)',
      'weight' => $weight,
    );
    menu_link_save($menu_link);
  }
}

/**
 * Migrate users from w2.
 *
 * Users will be synced directly from Sebra, but this class make sure that we
 * preserve the connection between the other content objects and users.
 */
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
    $this->addFieldMapping('field_uib_user_domain')->defaultValue('uib'); // XXX look for sebra in PSI
    $this->addFieldMapping('field_uib_w2_id', 'id');
    $this->addFieldMapping('field_uib_first_name', 'fornavn');
    $this->addFieldMapping('field_uib_last_name', 'etternavn');
    $this->addFieldMapping('field_uib_position', 'stilling');
    $this->addFieldMapping('field_uib_slug', 'slug');
  }

  public function prepareRow($row) {
    $valid_psi_prefix = "http://sebra.fd.uib.no/person?uid=";
    foreach ($row->psi as $psi) {
      if (substr($psi, 0, strlen($valid_psi_prefix)) === $valid_psi_prefix)
        return TRUE;
    }
    uibx_log("Ignored user $row->id: Bad PSI", 'warning');
    return FALSE;
  }

  protected function createStub($migration, $source_id) {
    $user = new stdClass;
    $user->name = t('User stub for') . $source_id[0];
    $user->mail = 'nobody@uib.no';
    $user->status = 0;
    $user->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    user_save($user);
    return array($user->uid);
  }
}

/**
 * Migrate employee-pages from tempsite
 *
 */

// check if we can contact source db
global $_edb;
$_edb = FALSE;
$setup_file = '/var/www/lib/php/uib/drupal/setup.php';
if (file_exists($setup_file)) {

  require_once($setup_file);
  $other_database = array(
    'database' => 'ressider',
    'username' => 'ressider_admin',
    'password' => '',
    'host' => 'ressider.pg.uib.no',
    'driver' => 'pgsql',
  );
  uib_drupal_set_password($other_database);

  try {
    Database::addConnectionInfo('migrate_epages_db', 'default', $other_database);
    $_edb = Database::getConnection('default', 'migrate_epages_db');
  } catch(Exception $e) {
    uibx_log("err: ".$e->getMessage(), 'warning');
  }
}

if ($_edb === FALSE) {
  uibx_log("EPagesMigation can't connect to source database - skipping", 'warning');

} else {

  /**
   * Migrate employee-pages:menus from tempsite
   *
   */
  class EPagesMenuLinksMigration extends Migration {
    public function __construct() {
      parent::__construct(MigrateGroup::getInstance('epages', array('area')));
      global $_edb, $_top_menu_id, $_area_target_id;

      $query = $_edb->select('menu_links')
        ->fields('menu_links')
        ->condition('menu_name', 'menu-ansattsider')
        ->orderBy('depth', 'ASC');

      //uibx_log(dpm((string) $query));

      $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
      $this->destination = new MigrateDestinationMenuLinks();

      $this->map = new MigrateSQLMap($this->machineName,
                   MigrateDestinationMenuLinks::getKeySchema(),
                   MigrateDestinationMenuLinks::getKeySchema(),
                   'migrate_epages_db'
      );

      $this->addSimpleMappings(array('link_path', 'router_path', 'link_title', 'module', 'hidden', 'external', 'has_children', 'expanded', 'weight'));

      $this->addFieldMapping('menu_name')
        ->defaultValue('area');

      $this->addFieldMapping('plid', 'plid')
        ->sourceMigration('EPagesMenuLinks');

      $this->addUnmigratedDestinations(array('options'));

      // find destination parent area menu node (must already exist)
      $result = db_select('menu_links')
        ->fields('menu_links', array('mlid', 'link_path'))
        ->condition('menu_name', 'area')
        ->condition('link_title', 'Ansattsider');

      $this->_top_menu_id = '';
      $this->_area_target_id = '';
      foreach ($result->execute() as $item) {
        $this->_top_menu_id = $item->mlid;
        list($empty, $this->_area_target_id) = explode('node/', $item->link_path);
        break;
      }

      $_top_menu_id = $this->_top_menu_id;
      $_area_target_id = $this->_area_target_id;

      uibx_log("EPagesMenuLinks top-menu-id: $this->_top_menu_id target_id: $this->_area_target_id");
    }

    public function prepare($entity, $row) {
      // update plid (if 0) with top-menu-id
      if ($row->plid == 0)
        $entity->plid = $this->_top_menu_id;
    }

    public function complete($entity, $row) {
      global $_mem;

      // save source mlid
      list($empty, $nid) = explode('node/', $row->link_path);
      if (isset($nid)) {
        $_mem[$nid] = $entity->mlid;
      }
      uibx_log("Created menu link at depth $row->depth \"$row->link_title.\"");
    }
  }

  // Fetch file meta info from employee pages
  function employee_file($item) {
    $server = 'https://ansattsider.app.uib.no/sites/ansattsider.app.uib.no/';

    if ($item->deleted)
      return FALSE;

    if (strpos($item->filemime, 'image') !== FALSE) {
      $uri = 'files/field/image/';

    } elseif (strpos($item->filemime, 'pdf') !== FALSE) {
      $uri = 'files/attachments/';

    } else {
      die("Unknown file type: " . $item->filemime);
    }

    $basename = drupal_basename($item->uri);
    $uri = $server.$uri.$basename;

    $file = new stdClass();
    $dirname = 'public://ansattsider/';
    @drupal_mkdir($dirname, NULL, TRUE);
    $filename = "$dirname/$basename";
    $filename = file_destination($filename, FILE_EXISTS_RENAME);

    if (!@copy($uri, $filename)) {
      die("Could not copy file " . $uri . "\n");
    }

    //$file->field_uib_owner['und'][]['value'] = $xtopic->photographer;
    //$file->field_uib_copyright['und'][]['value'] = $xtopic->{1351138798041054899};
    $file->field_uib_description['und'][]['value'] = $item->field_uib_files_description;

    $file->filename = $item->filename;
    $file->uri = $filename;
    $file->uid = $item->uid;
    $file->status = FILE_STATUS_PERMANENT;

    file_save($file);
    if (!$file->fid) {
      die("Could not save file");
    }
    return $file;
  }

  /**
   * Migrate employee-pages:nodes from tempsite
   *
   */
  class EPagesNodesMigration extends Migration {
    public function __construct() {
      parent::__construct(MigrateGroup::getInstance('epages', array('area')));
      global $_edb;

      // Make sure this runs after EPagesMenuLinksMigration
      $this->dependencies = array('EPagesMenuLinks');

      // query all nodes. In prepareRow drop it if not part of 'menu-ansattsider'
      $query = $_edb->select('node', 'n')
        ->fields('n');
      $query->join('node_revision', 'nr', 'n.vid = nr.vid');
      $query->join('users', 'u', 'nr.uid = u.uid');
      $query->addField('u', 'name');
      $query->orderBy('n.changed');

      //uibx_log(dpm((string) $query));

      $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
      $this->destination = new MigrateDestinationNode('uib_article');

      $this->map = new MigrateSQLMap($this->machineName,
                   array(
                     'nid' => array(
                       'type' => 'int',
                       'unsigned' => TRUE,
                       'description' => 'ID of destination node',
                       'alias' => 'n',
                     )
                   ),
                   MigrateDestinationNode::getKeySchema(),
                   'migrate_epages_db'
      );

      // allow migration to be runned multiple times - not working - gives error
      //$this->highwaterField = array('name' => 'changed', 'alias' => 'n');

      // todo handle english translations

      $this->addFieldMapping('title', 'title');
      $this->addFieldMapping('field_uib_article_type')
        ->defaultValue('infopage');
      $this->addFieldMapping('language')
        ->defaultValue('nb');
      $this->addFieldMapping('created', 'created');
      $this->addFieldMapping('changed', 'changed');
      $this->addFieldMapping('field_uib_lead'); // handled in prepare
      $this->addFieldMapping('field_uib_text'); // handled in prepare
      $this->addFieldMapping('field_uib_area'); // handled in prepare
      $this->addFieldMapping('uid'); // handled in prepare

      $this->addUnmigratedDestinations(array('field_uib_w2_id',
          'field_uib_menu_title_w2',
          'field_uib_w2_path',
          'field_uib_date',
          'field_uib_links',
          'field_uib_kicker',
          'field_uib_w2_nav_parent_id',
          'field_uib_nav_weight',
          'field_uib_byline',
          'field_uib_location',
          'field_uib_contacts',
          'field_uib_text2',
        ));
    }

    public function prepareRow($row) {
      global $_edb;

      // check that source node is part of menu 'ansattsider'
      $result = $_edb->select('menu_links')
        ->fields('menu_links', array('mlid', 'link_path'))
        ->condition('menu_name', 'menu-ansattsider')
        ->condition('link_path', 'node/'.$row->nid);

      if (($item = $result->execute()) === FALSE)
        return FALSE;
    }

    public function prepare($entity, $row) {
      global $_edb, $_top_menu_id, $_area_target_id;

      // use area_target_id from destination 'ansattsider'
      $entity->field_uib_area['und'][0]['target_id'] = $_area_target_id;

      // find field_uib_lead
      $query = $_edb->select('field_data_field_uib_lead', 'l')
        ->fields('l', array('field_uib_lead_value'))
        ->condition('l.entity_id', $row->nid, '=');

      foreach ($query->execute() as $item) {
        $entity->field_uib_lead['und'][0]['value'] = $item->field_uib_lead_value;
        break;
      }

      // find field_uib_text
      $query = $_edb->select('field_data_field_uib_text', 't')
        ->fields('t', array('field_uib_text_value'))
        ->condition('t.entity_id', $row->nid, '=');

      foreach ($query->execute() as $item) {
        $entity->field_uib_text['und'][0]['value'] = $item->field_uib_text_value;
        break;
      }

      // find destination uid based on (user)name
      $user = user_load_by_name($row->name);
      if (!empty($user->uid))
        $entity->uid = $user->uid;

      uibx_log("Created node $row->nid uid:$user->uid. ($row->name) \"$entity->title\"");

      // copy any images and attachements (pfd) to the destination node
      $query = $_edb->select('field_data_field_uib_files', 'f')
        ->fields('f')
        ->condition('f.entity_id', $row->nid, '=');
      $query->join('file_managed', 'm', 'm.fid = f.field_uib_files_fid');
      $query->addField('m', 'uid');
      $query->addField('m', 'filename');
      $query->addField('m', 'uri');
      $query->addField('m', 'filemime');

      foreach ($query->execute() as $item) {
        $file = employee_file($item);
        $entity->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }

    public function complete($entity, $row) {
      global $_mem;

      // use mem[nid] to map to new menu - modify menu link_path
      if (isset($_mem[$row->nid])) {
        $new_mlid = $_mem[$row->nid];
        $menu_link = menu_link_load($new_mlid);
        $menu_link['link_path'] = drupal_get_normal_path('node/'.$entity->nid);
        menu_link_save($menu_link);
      }
    }
  }
}
