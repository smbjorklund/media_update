<?php

function uib_migrate_drush_command() {
  $items['uib-migrate-build-menu'] = array(
    'description' => 'Recursive traversal of node starting at top level menu item',
    'aliases' => array('uib-bm',),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-sync-w2-user'] = array(
    'description' => 'Syncronise user fields that are maintained in w2',
    'aliases' => array('uib-w2u'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'user' => 'The username',
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

function drush_uib_migrate_uib_sync_w2_user($username) {
  $account = user_load_by_name($username);
  if (!$account) {
    uibx_log('No user with the given username exist');
    return;
  }
  $w2u = new XTopic("username:$username");

  $edit = array();
  if ($account->field_uib_slug['und'][0]['value'] != $w2u->slug) {
    $edit['field_uib_slug']['und'][0]['value'] = $w2u->slug;
  }
  if ($account->field_uib_w2_id['und'][0]['value'] != $w2u->id) {
    $edit['field_uib_w2_id']['und'][0]['value'] = $w2u->id;
  }
  if (empty($edit)) {
    uibx_log("No change for $username <$account->mail>");
  }
  else {
    user_save($account, $edit);
    uibx_log("Updated fields for $username <$account->mail>");
  }

  // Update the path aliases if needed
  $source = 'user/' . $account->uid;
  $slug = $account->field_uib_slug['und'][0]['value'];
  foreach (array('nb' => 'personer', 'en' => 'persons') as $lang => $prefix) {
    $path_key = array(
      "source" => $source,
      "language" => $lang,
    );
    $alias = $prefix . '/' . $slug;
    $path = path_load($path_key);
    if (empty($path)) {
      $path = $path_key;
    }
    elseif ($path['alias'] == $alias) {
      continue; // no need up update the alias
    }
    $path['alias'] = $alias;
    path_save($path);
    uibx_log("Set $lang path alias for $username to $alias");
  }
}

function drush_uib_migrate_build_menu() {
 $result = db_select('menu_links')
      ->fields('menu_links', array('mlid', 'link_path'))
      ->condition('menu_name', 'area')
      ->condition('depth', 2)
      ->execute();

  foreach($result as $row) {
    list($empty, $nid) = explode('node/', $row->link_path);
    if (isset($nid)) {
      $node = node_load($nid);
      uib_migrate__build_menu_tree($node, $row->mlid, 1);
    }
  }
}

function uib_migrate__build_menu_tree($node, $mlid, $depth) {
  $w2id = $node->field_uib_w2_id['und'][0]['value'];
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_w2_nav_parent_id', 'value', $w2id, '=')
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
      foreach($result->execute() as $item) {
        $kid_mlid = $item->mlid;
      }

      if (!isset($kid_mlid)) {
        // Create menu link
        $link_title = $kid_node->field_uib_menu_title_w2['und'][0]['value'];
        if (!$link_title)
          $link_title = $kid_node->title;
        $menu_link = array(
          'menu_name' => 'area',
          'link_path' => 'node/' . $kid_nid,
          'link_title' => $link_title,
          'weight' => $kid_node->field_uib_nav_weight['und'][0]['value'],
          'plid' => $mlid,
        );
        $kid_mlid = menu_link_save($menu_link);
        drush_log("Created menu link at depth $depth for node $kid_nid \"$kid_node->title\"");
      }

      uib_migrate__build_menu_tree($kid_node, $kid_mlid, $depth+1);
    }
  }
}
