<?php
/**
 * @file
 * @return [type] [description]
 */
function uib_migrate_drush_command() {
  $items['uib-migrate-build-menu'] = array(
    'description' => 'Recursive traversal of node starting at top level menu item',
    'aliases' => array('uib-bm', ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-sync-w2-user'] = array(
    'description' => 'Syncronise user fields that are maintained in w2',
    'aliases' => array('uib-w2u'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'user' => 'The username or count of users to sync',
    ),
    'required-arguments' => TRUE,
  );
  $items['uib-migrate-menu-clean-up'] = array(
    'description' => 'Removes items that are not area from depth 1 in menu_links',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-migrate-update-files'] = array(
    'description' => 'Updating all files from w2',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_uib_migrate_uib_sync_w2_user($limit_or_username) {
  module_load_include('inc', 'uib_migrate');
  if (is_numeric($limit_or_username)) {
    uib_migrate__sync_w2_users($limit_or_username);
  }
  else {
    uib_migrate__sync_w2_user($limit_or_username);
  }
}

function drush_uib_migrate_build_menu() {
 $result = db_select('menu_links')
      ->fields('menu_links', array('mlid', 'link_path'))
      ->condition('menu_name', 'area')
      ->condition('depth', 2)
      ->execute();

  foreach ($result as $row) {
    $result = explode('node/', $row->link_path);

    // link_path may contain 'http://#'
    if (count($result) > 1) {
      list($empty, $nid) = $result;
      if (!is_numeric($nid)) {
        $msg = 'Non numeric node id:' . $nid;
        $nid = intval($nid);
        $msg .= "... converting to $nid";
        uibx_log($msg, "warning");
      }
      $node = node_load($nid);
      if ($node) {
        uib_migrate__build_menu_tree($node, $row->mlid, 3);
      }
    }
  }
  menu_cache_clear_all();
}

function uib_migrate__build_menu_tree($node, $mlid, $depth) {
  $w2id = $node->field_uib_w2_id['und'][0]['value'];
  if (empty($w2id)) {
    drush_log('Skipping menu link not created in migration for node ' . $node->nid);
    return;
  }
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_w2_nav_parent_id', 'value', $w2id, 'CONTAINS')
    ->execute();
  if (!empty($result['node'])) {
    foreach (array_keys($result['node']) as $kid_nid) {

      $kid_node = node_load($kid_nid);

      // Determine the menu_link of the corresponding node
      $kid_mlid = NULL;
      $result = db_select('menu_links')
        ->fields('menu_links', array('mlid', 'link_path'))
        ->condition('menu_name', 'area')
        ->condition('plid', $mlid)
        ->condition('link_path', 'node/' . $kid_nid);
      foreach ($result->execute() as $item) {
        $kid_mlid = $item->mlid;
      }

      if (!empty($kid_node->field_uib_nav_weight['und'][0]['value'])) {
        $link_weight = $kid_node->field_uib_nav_weight['und'][0]['value'];
      }
      else {
        $link_weight = 0;
      }

      if (!empty($kid_node->field_uib_menu_title_w2['und'][0]['value'])) {
        $link_title = $kid_node->field_uib_menu_title_w2['und'][0]['value'];
      }
      else {
        $link_title = $kid_node->title;
      }

      $menu_link = array(
        'menu_name' => 'area',
        'link_path' => 'node/' . $kid_nid,
        'link_title' => $link_title,
        'weight' => $link_weight,
        'plid' => $mlid,
      );

      if (!isset($kid_mlid)) {
        // Create menu link
        $kid_mlid = menu_link_save($menu_link);
        drush_log("Created menu link at depth $depth for node $kid_nid \"$kid_node->title\"");
      }
      else {
        //update menu link
        $menu_link['mlid'] = $kid_mlid;
        $kid_mlid = menu_link_save($menu_link);
        drush_log("Updated menu link at depth $depth for node $kid_nid \"$kid_node->title\"");
      }

      uib_migrate__build_menu_tree($kid_node, $kid_mlid, $depth+1);
    }
  }
}

function drush_uib_migrate_menu_clean_up() {
  uib_migrate_menu_clean_up();
}

function uib_migrate_menu_clean_up($deleted=0, $first_run=TRUE, $last_run=0) {
  $result = db_select('menu_links', 'ml')
    ->fields('ml', array('mlid', 'link_path'))
    ->condition('menu_name', 'area')
    ->condition('depth', 1)
    ->execute();
  $this_run = 0;
  if ($last_run > 0 or $first_run) {
    foreach ($result as $item) {
      $nid = substr($item->link_path, 5);
      try {
        $node = node_load($nid);
        if ($node->type != 'area') {
          drush_log('Found menu item at depth 1 for node ' . $node->nid . ' of node type ' . $node->type);
          menu_link_delete($item->mlid);
          $this_run++;
          drush_log('Deleted menu_link for node ' . $node->nid);
        }
      }
      catch (Exception $e) {
        drush_log('Caught exception : ' . $e->getMessage());
        menu_link_delete($item->mlid);
        $this_run++;
        drush_log('Deleted menu_link for node ' . $node->nid);
      }
    }
    drush_log('This run deleted ' . $this_run . ' menu links');
    uib_migrate_menu_clean_up($deleted + $this_run, FALSE, $this_run);
  }
  else {
    menu_cache_clear_all();
    drush_log('This script has deleted ' . $deleted . ' menu links' );
  }
}

function drush_uib_migrate_update_files() {
  module_load_include('inc', 'uib_migrate');
  $bundles = array('uib_article', 'area', 'uib-testimonial');
  $fields = array('field_uib_media', 'field_uib_primary_media', 'field_uib_main_media');

  /**
   * Get all nodes using files.
   *
   * @return array of node ID (nid)
   */
  function get_nid__($bundle, $field) {
    $query = new EntityFieldQuery;
    $result =  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition($field, 'fid', FALSE, '!=')
      // ->range(0,4000)
      ->execute();

    if (isset($result['node'])) {
      return $items_nids = array_keys($result['node']);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Get all fid
   *
   * @return array of file information.
   */
  function file_info__($items) {
   $media_items = array();

    foreach ($items as $key => $files) {
      if (isset($files->field_uib_primary_media['und'])) {
        $primary_media = $files->field_uib_primary_media['und'];
        $result = file_set__($primary_media, $files->language);
        if ( $result)
          $media_items[] = $result;
      }
      if (isset($files->field_uib_media['und'])) {
        $media = $files->field_uib_media['und'];
        $result = file_set__($media, $files->language);
        if ( $result)
          $media_items[] = $result;
      }
      if (isset($files->field_uib_main_media['und'])) {
        $main_media = $files->field_uib_main_media['und'];
        $result = file_set__($main_media, $files->language);
        if ( $result)
          $media_items[] = $result;
      }
    }
    return $media_items;
  }

  /**
   * Populate file array with data if it have a w2id (have been migrated).
   * @param $media
   *   File entry to write.
   *
   * @param $language
   *  Language to populate file entry with.
   *
   * @return array of file entries or FALSE if no w2 ID was found.
   */
  function file_set__($media, $language) {
    $file = FALSE;
    foreach ($media as $media_item) {
      if (isset($media_item['field_uib_w2_id']['und'][0]['safe_value'])) {
          $file['fid'] = $media_item['fid'];
          $file['w2id'] = $media_item['field_uib_w2_id']['und'][0]['safe_value'];
          $file['language'] = $language;
          $file['uid'] = $media_item['uid'];
      }
    }
    return $file;
  }

  foreach ($bundles as $bundle) {
    foreach ($fields as $field) {
      $nid = get_nid__($bundle, $field);
      if (!$nid) {
        uibx_log($bundle . ' contained no files of the type ' . $field);
      }
      else {
        uibx_log('Found nodes, processing: ' . $bundle . ' ' . $field);
        $items = entity_load('node', $nid);
        $files = file_info__($items);
        if ($files) {
          foreach ($files as $key => $value) {
            uibx_log('w2 ID: ' . $value['w2id'] . ' uID: ' . $value['uid']  . ' fID: '  . $value['fid'] . ' LANG: ' . $value['language']);
            xtopic_file($value['w2id'], $value['uid'], $value['language']);
          }
        }
      }
    }
  }
  return TRUE;
}
