<?php
/**
 * @file
 * UiB w2 -> w3 migration code.
 */

function xtopic_cleanup($text) {
  return html_entity_decode($text, ENT_QUOTES, 'UTF-8');
}

/**
 * Fixes urls in the format ala: '../../../../fof/..'
 *
 * @param $text
 *
 * @returns modified text
 *
 */
function xtopic_fixuri($text) {
  global $tot_count_uri;

  if (!isset($tot_count_uri))
    $tot_count_uri = 0;

  $host = 'www.uib.no';
	$search=array('/ href="(\.\.\/)+(.+)/i',     // match ' href=(../)+'
		      );
	$replace=array(" href=\"http://$host/\\2",   // prepend ' href="http://$host/'
		   );

	$res = preg_replace($search, $replace, $text, -1, $count);

  if ($count) {
    $tot_count_uri += $count;
    uibx_log("Fixed $tot_count_uri uris in text blocks");
  }
  return $res;
}

/**
 * Returns the Drupal file object matching the given XTopic file object.
 *
 * @param $id
 *   XTopic $id. The $id must reference an XTopic object of type 'file'.
 * @param $uid
 *   User id to the file entity.
 * @param $parent_lang
 *   File entity language and its translatable fields will get this set.
 *   Defaults to nb (Norwegian bokmål).
 *
 * @return
 *   A Drupal file object. Return existing file object if file exist.
 *   Non existing file object is created and stored (file_save) before
 *   returning the file object.
 */
function xtopic_file($id, $uid, $parent_lang = 'nb') {
  if (empty($parent_lang)) {
    $parent_lang = 'nb';
  }

  // Check if we already have a 'file' migrated from the same id
  // If so, load the file object properly to make it possible to update it below
  $file_exists = FALSE;
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'file')
    ->fieldCondition('field_uib_w2_id', 'value', $id, '=')
    ->range(0, 1)
    ->execute();
  if (!empty($result['file'])) {
    // File exists
    $file_exists = TRUE;
    $res = array_values($result['file']);
    // Check if we are forcing update of *field data* from w2.
    if (!drush_get_option('force')) {
      $file = new stdClass();
      $file->fid = $res[0]->fid;
      // Return an object with only fid set
      return $file;
    }
    else {
      // Load a full file object
      $file = file_load($res[0]->fid);
    }
    uibx_log('Forcing file metadata update from w2: fid=' . $file->fid, 'notice');
  }

  // Fetch file meta info from w2
  $xtopic = new XTopic($id, FALSE, 'file');
  if ($xtopic->type == 'image') {
    $uri = $xtopic->original;
  }
  elseif ($xtopic->type == 'file') {
    $uri = $xtopic->file;

    // In w2, 'file' can be document or audio (perhaps even video)
    // Attempt to divide w2 files of type "file" into Drupal file types
    $file_mime_type = file_get_mimetype($uri); // defaults to "application/octet-stream" for unknowns
    $tmp = explode('/', $file_mime_type);
    $media_content_type = trim($tmp[0]);
    if ($media_content_type == 'audio') {
      $xtopic->type = 'audio';
    }
    elseif ($media_content_type == 'video') {
      $xtopic->type = 'video';
    }
    else {
      $xtopic->type = 'document';
    }
  }
  else {
    die("Unknown file type: " . $xtopic->type);
  }

  if (!$file_exists) {
    // Create file object if new file
    $file = new stdClass();

    // setup file origin and destination paths for new file
    $uri = XTopic::url($uri); // origin
    $basename = drupal_basename($uri);
    if (function_exists('transliteration_clean_filename')) {
      $basename = transliteration_clean_filename($basename, 'nb');
    }
    $hash = strtolower(substr($basename, 0, 2));
    $dirname = 'public://w2/' . $hash;
    @drupal_mkdir($dirname, NULL, TRUE);
    $filename = "$dirname/$basename";
    $filename = file_destination($filename, FILE_EXISTS_RENAME);
    $file->uri = $filename; // destination
    // Fetch new file
    $opts = array(
      'http' => array(
        'timeout' => 20
        )
      );
    $context = stream_context_create($opts);
    if (!copy($uri, $filename, $context)) {
      print_r(error_get_last());
      die("Failed to copy file $uri to $filename\n");
    }
  }

  // Set or update field data attached to the file
  // Add field data to a NEW file -- or to an existing file when force option is in effect
  if (isset($xtopic->photographer)) {
    $file->field_uib_owner['und'][]['value'] = $xtopic->photographer;
  }
  if (isset($xtopic->{1351138798041054899})) {
    $file->field_uib_copyright['und'][]['value'] = $xtopic->{1351138798041054899};
  }
  if (isset($xtopic->dc_description)) {
    $file->field_uib_description[$parent_lang][]['value'] = $xtopic->dc_description;
    if (!empty($file->field_uib_description[$parent_lang][0]['value'])) {
      if ($xtopic->type == 'image') {
        // Populate image files title and ALT attribute with something useful.
        $file->field_file_image_title_text[$parent_lang][]['value'] = truncate_utf8($file->field_uib_description[$parent_lang][0]['value'], 200, TRUE, TRUE, 1);
        $file->field_file_image_alt_text['und'][]['value'] = truncate_utf8($file->field_uib_description[$parent_lang][0]['value'], 80, TRUE, TRUE, 1);
      }
    }
  }
  $file->field_uib_w2_id['und'][]['value'] = $id;
  $tmp_title = trim($xtopic->title);
  if (drupal_strlen($tmp_title) > 100) { // If the title is very long, treat it as description if possible
    if (empty($file->field_uib_description[$parent_lang])) { // but only if description is empty
      $file->field_uib_description[$parent_lang][]['value'] = $tmp_title;
      uibx_log('Long title of file copied to empty description: ' . $xtopic->title, 'warning');
    }
  }
  if (drupal_strlen($tmp_title) > 255) {
    $tmp_title = truncate_utf8($xtopic->title, 250, TRUE, TRUE, 1); // if title is > 255 it causes an error in postgresql
    uibx_log('Title of file right-truncated to 250 chars: ' . $xtopic->title, 'warning');
  }
  // set xtopic title as file 'filename'
  if (empty($tmp_title) OR $tmp_title == '.') {
    $tmp_title = $basename; // fix for stupid or empty titles
  }
  $file->filename = $tmp_title;
  $file->uid = $uid;
  $file->status = FILE_STATUS_PERMANENT;
  $file->type = $xtopic->type; // Set bundle

  // init entity translation
  if ($xtopic->type != 'document') {
    $et = entity_translation_get_handler('file', $file);
    $translation = array('language' => $parent_lang, 'status' => 1);
    $et->setTranslation($translation);
    $et->setOriginalLanguage($parent_lang); // set original language
    if ($file_exists) {
      uibx_log('Set original language for existing file: fid=' . $file->fid . ', entity lang=' . entity_language('file',$file), 'notice');
    }
  }

  file_save($file);
  if (!$file->fid) {
    die("Could not save file");
  }
  else {
    // Touch timestamp to preserve timestamps from legacy system (w2).
    // This is performed also for existing files when metadata update from w2 is performed.
    $file->timestamp = strtotime($xtopic->created);
    drupal_write_record('file_managed', $file, 'fid');
  }
  return $file;
}

function xtopic_vimeo($uri, $parent_lang = 'nb') {
  $file = new stdClass();
  $result = db_select('file_managed', 'fm')
    ->fields('fm', array('fid'))
    ->condition('uri', $uri, '=')
    ->execute()
    ->fetchAssoc();
  if (!empty($result)) {
    $file->fid = $result['fid'];
  }
  else {
    $file->uri = $uri;
    file_save($file);
    if (!$file->fid) {
      die('Could not save file');
    }
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
    $this->addFieldMapping('field_uib_text', 'text')
      ->arguments(array('format' => 'basic_html'));
    $this->addFieldMapping('field_uib_w2_nav_parent_id', 'nav_parent_id');
    $this->addFieldMapping('field_uib_nav_weight', 'nav_weight');
    $this->addFieldMapping('field_uib_area', 'site')
      ->sourceMigration('Area');
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_byline', 'byline')
      ->sourceMigration('User');
    $this->addFieldMapping('field_uib_fact_box', 'fact_box')
      ->arguments(array('format' => 'basic_html'));
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }
    $row->article_type = $this->article_type;

    if (isset($row->text)) {
      $clean_text = xtopic_cleanup($row->text);
      $row->text = $clean_text;

      $row->text = xtopic_fixuri($row->text);
    }

    $row->fact_box = '';
    if (!empty($row->faktabokstittel)) {
      $row->fact_box .= '<h3>' . $row->faktabokstittel . '</h3>';
    }
    $faktaboks = 'faktaboks-tekst';
    if (!empty($row->$faktaboks)) {
      $row->fact_box .= $row->$faktaboks;

      $clean_fact_box = xtopic_cleanup($row->fact_box);
      $row->fact_box = $clean_fact_box;

      $row->fact_box = xtopic_fixuri($row->fact_box);
    }
  }

  public function prepare($node, $row) {
    if (strstr($row->main_media, 'vimeo')) {
      $file = xtopic_vimeo($row->main_media);
      $node->field_uib_main_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }
    elseif (isset($row->main_media)) {
      $file = xtopic_file($row->main_media, $node->uid, $row->site_lang);
      $node->field_uib_main_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }

    if (!empty($row->media)) {
      foreach ($row->media as $file_id) {
        $file = xtopic_file($file_id, $node->uid, $row->site_lang);
        $node->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }

    if (!empty($row->attachments)) {
      foreach ($row->attachments as $file_id) {
        $file = xtopic_file($file_id, $node->uid, $row->site_lang);
        $node->field_uib_files['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
    }
  }

  public function complete($node, $row) {
    // Create redirect for w2 url and/or or path to the node that is being migrated
    $sources = array(
      trim($row->url),
      trim($row->path),
      );
    foreach ($sources as $source_path) {
      if (!empty($source_path)) {
        $redirect = new stdClass();
        redirect_object_prepare($redirect);
        $redirect->source = $source_path;
        $redirect->redirect = 'node/' . $node->nid;
        // Check if the redirect exists before saving.
        $hash = redirect_hash($redirect);
        if (!redirect_load_by_hash($hash)) {
          redirect_save($redirect);
          uibx_log('Redirect created for ' . $redirect->source . ' -> ' . $redirect->redirect);
        } else {
          uibx_log('Redirect ' . $redirect->source . ' -> ' . $redirect->redirect . ' already existed');
        }
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

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }

  public function prepare($node, $row) {
    parent::prepare($node, $row);
    if (drush_get_option('update')) {
      $node->menu = array(
        'enabled' => TRUE,
      );
    }
  }

  public function complete($node, $row) {
    parent::complete($node, $row);
  }
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
    $node->title = t('Navigation stub for @id', array('@id' => $source_id[0]));
    $node->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    node_save($node);
    return array($node->nid);
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // Do not import navigation pages that lack site (i.e. connection to area).
    // Navigation pages are treated as articles and those should be connected to areas.
    // Navigation pages without site info also cause database errors in postgres.
    if (empty($row->site)) {
      uibx_log("Rejected NavPage without site info: " . $row->title . ". XTopic id: " . $row->id, 'warning');
      return FALSE;
    }
  }

  public function complete($node, $row) {
    parent::complete($node, $row); // perform complete function of parent
    if (isset($row->menu_top_entry)) {
      if (!drush_get_option('update')) {
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
        if (empty($row->nav_weight)) {
          $row->nav_weight = 0; // Empty weights cause postgres errors/warnings
          uibx_log("Set empty menu link nav_weight to zero", 'notice');
        }
        if (!empty($node->field_uib_menu_title_w2['und'][0]['value'])) {
          $link_title = $node->field_uib_menu_title_w2['und'][0]['value'];
        }
        else {
          $link_title = $node->title;
        }
        $menu_link = array(
          'menu_name' => 'area',
          'link_path' => drupal_get_normal_path('node/' . $node->nid),
          'link_title' => $link_title,
          'weight' => $row->nav_weight,
          'plid' => $area_mlid,
        );
        menu_link_save($menu_link);
      }
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
  }

  private static function type_map($w2_type) {
    static $type_map = array(
      'arrangement' => 'event',
      'disputas' => 'disputation',
      'foredrag' => 'lecture',
      'frist' => 'deadline',
      'gjesteforelesning' => 'guest_lecturer',
      'konferanse' => 'conference',
      'konsert' => 'consert',
      'kurs' => 'course',
      'midler og stipend' => 'grant',
      'proveforelesning' => 'trial_lecture',
      'seminar' => 'seminar',
      'utstilling' => 'exhibition',
    );
    if (isset($type_map[$w2_type]))
      return $type_map[$w2_type];
    return $w2_type;
  }

  public function prepare($node, $row) {
    parent::prepare($node, $row);
    if (!empty($row->start_date)) {
      $node->field_uib_date['und'][0]['value'] = $row->start_date;
    }
    if (!empty($row->end_date)) {
      $node->field_uib_date['und'][0]['value2'] = $row->end_date;
    }
    $node->field_uib_event_type['und'][0]['value'] = self::type_map((string)$row->type);
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
    $this->addFieldMapping('field_uib_text', 'text')
      ->arguments(array('format' => 'basic_html'));
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
        $file = xtopic_file($file_id, $node->uid, $row->site_lang);
        $node->field_uib_media['und'][] = array(
          'fid' => $file->fid,
          'display' => 1,
        );
      }
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
    $this->addFieldMapping('field_uib_primary_text', 'text')
      ->arguments(array('format' => 'restricted_html'));
    $this->addFieldMapping('field_uib_text2', 'profiletext')
      ->arguments(array('format' => 'plain_text'));
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass;
    $node->type = 'area';
    $node->title = t('Area stub for @id', array('@id' => $source_id[0]));
    $node->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    node_save($node);
    return array($node->nid);
  }

  public function prepareRow($row) {
    if ($row->state != 'published') {
      return FALSE;
    }

    if (isset($row->profiletext)) {
      $row->profiletext = xtopic_fixuri($row->profiletext);
    }
    if (isset($row->text)) {
      $row->text = xtopic_fixuri($row->text);
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
      $file = xtopic_file($row->media[0], $term->uid, $row->site_lang);
      $term->field_uib_primary_media['und'][0] = array(
        'fid' => $file->fid,
        'display' => 1,
      );
    }

    if (drush_get_option('update')) {
      $term->menu['enabled'] = TRUE;
    }
  }

  public function complete($node, $row) {
     // Set tnid; can't map it directly because we can't map to ourself
    $node->tnid = $row->no_site == $row->id ? $node->nid :
      $this->handleSourceMigration('Area', array($row->no_site), NULL, $this);
    $node_alias = $node->path['alias']; // keep this
    unset($node->path);  // avoids setting the alias twice
    node_save($node);
    // Add project specific aliases for the node
    uib_area__create_area_aliases($node->nid, $node_alias, $node->language);

    $weight = array_search($row->type, array(
      'fakultet',
      'faculty',
      'institutt',
      'institute',
      'enhet',
      'section',
      'forskningsgruppe',
      'research group',
      'forskerskole',
      'research school',
    ));
    if ($weight === FALSE) {
      $weight = 99;
    }
    if (!is_integer($weight)) {
      $weight = 99;
    }
    if (!drush_get_option('update')) {
      $menu_link = array(
        'menu_name' => 'area',
        'link_path' => drupal_get_normal_path('node/' . $node->nid),
        'link_title' => $node->title,
        'weight' => $weight,
      );
      menu_link_save($menu_link);
    }
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
    $this->addFieldMapping('field_uib_position_code', 'stillingskode');
    $this->addFieldMapping('field_uib_position_category', 'stillingskategori');
  }

  public function prepareRow($row) {
    // Check if user already exists
    $result = db_select('users', 'f')
      ->fields('f', array('uid'))
      ->condition('name', $row->{'uib-id'}, '=')
      ->execute();
    if (isset($result)) {
      // -- the user was found
      $local_user = $result->fetchAssoc();
      if (!empty($local_user)) {
        uibx_log("The user " . $row->{'uib-id'} . "[" . $local_user['uid'] . "] $row->id was already present", 'warning');
        $existing_user = user_load($local_user['uid']);
        // update existing user with w2 id, to make sure it is there
        // The user may have been added by uib-sebra-users sync, and
        // in those cases w2 id will be lacking
        $existing_user->field_uib_w2_id['und'][0]['value'] = $row->id;
        user_save($existing_user);
        return FALSE;
      }
    }
    // Check if psi is valid
    $valid_psi_prefix = "http://sebra.fd.uib.no/person?uid=";
    foreach ($row->psi as $psi) {
      if (substr($psi, 0, strlen($valid_psi_prefix)) !== $valid_psi_prefix)
        uibx_log("Ignored user $row->id: Bad PSI", 'warning');
        return FALSE;
    }
  }

  protected function createStub($migration, $source_id) {
    $user = new stdClass;
    $user->name = t('User stub for @id', array('@id' => $source_id[0]));
    $user->mail = 'nobody@uib.no';
    $user->status = 0;
    $user->field_uib_w2_id['und'][0]['value'] = $source_id[0];
    user_save($user);
    return array($user->uid);
  }
}
