<?php
/**
 * @file
 * uib_area.drush.inc
 * @return [type] [description]
 */
function uib_area_drush_command() {
  $items['uib-area-connect-ou'] = array(
    'description' => 'Traversal of areas to connect missing organisational units',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-area-split-menu'] = array(
    'description' => 'Splits the big area menu into separate menus for each area',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  return $items;
}

/**
 * Update area nodes that lack OU indication
 * with a relevant parental OU.
 *
 * It is possible to set an option --dry-run
 * If dry-run is set, nodes are checked and some output is given,
 * but nothing is changed. Note that you may want to combine the
 * dry-run option with --strict=0 --verbose.
 */
function drush_uib_area_connect_ou() {
  $dry_run = FALSE;
  if (drush_get_option('dry-run')) {
    $dry_run = TRUE;
  }
  // Find area nodes that lack OU.
  // Done in two steps as EntityFieldQuery lacks NotExists in D7.

  // Find all area nodes in which OU is set.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area')
    ->fieldCondition('field_uib_ou', 'target_id', 0, '>');
  $result = $query->execute();
  $with_ou = array();
  if ($result) {
    foreach($result['node'] as $node) {
      $with_ou[] = $node->nid;
    }
    // Get all the other area nodes, i.e. those that lack OU
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'area')
      ->entityCondition('entity_id', $with_ou, 'NOT IN');
    $result2 = $query->execute();
    if ($result2) {
      $nodes = entity_load('node', array_keys($result2['node']));
      foreach($nodes as $node) {
        if ($dry_run) {
          uibx_log("Checking OU of node $node->nid ...", "notice");
        }
        $ou_nid = uib_area__get_ou_nid($node);
        if (!empty($ou_nid)) {
          $node->field_uib_ou['und'][]['target_id'] = $ou_nid;
          if ($dry_run) {
            uibx_log("-- would update node=$node->nid with ou=$ou_nid", "notice");
          }
          else {
            field_attach_update('node', $node);
          }
        }
        else {
          if ($dry_run) {
            uibx_log("** found no OU for node $node->nid **", "warning");
          }
        }
      }
    }
  }
}

/**
 * Break apart the menu called "area" into one separate menu for each area
 *
 * The new menus get machine names in the form 'menu-area-' + nid. where nid is
 * the node id for the area.
 * The menu title is set to 'area_' + url node alias.
 * The menu description uses the node title.
 *
 * Intended to be executed only once, but it will avoìd trying to create menus that already exist
 */
function drush_uib_area_split_menu() {
  // Find all area nodes
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area');
  $result = $query->execute();
  if ($result) {
    $nodes = entity_load('node', array_keys($result['node']));
    $added_menus = array();
    foreach($nodes as $node) {
      $menu_machine_name = 'menu-area-' . $node->nid;
      $menu_title = 'area_' . str_replace('/', '_', drupal_get_path_alias("node/$node->nid", $node->language));
      if ($node->language == 'en') {
        // Set suffix for English menus since nb and en aliases for different nodes may be the same
        $menu_title .= '_en';
      }
      $menu_description = 'Menu for ' . $node->title;

      // Get menu link id for the area
      $node_mlink = menu_link_get_preferred('node/' . $node->nid, 'area');
      if (!empty($node_mlink)) {
        if (!menu_load($menu_machine_name)) {
          // Create new menu
          $menu = array(
            'menu_name' => $menu_machine_name,
            'title' => $menu_title,
            'description' => $menu_description,
            );
          menu_save($menu);
          $added_menus[] = $menu_machine_name;

          // Move the first level children
          $result = db_select('menu_links', 'n')
            ->fields('n', array('mlid'))
            ->condition('plid', $node_mlink['mlid'])
            ->condition('menu_name', 'area')
            ->execute()
            ->fetchCol();
          foreach ($result as $item) {
            $child = menu_link_load($item);
            if (empty($child['options'])) {
              $child_options = array('attributes' => array('title' => ''));
            }
            else {
              $child_options = $child['options'];
            }
            $new_child = array (
              'link_path' => $child['link_path'],
              'link_title' => $child['link_title'],
              'menu_name' => $menu_machine_name,
              'weight' => $child['weight'],
              'expanded' => 1,
              'options' => $child_options,
              'mlid' => $child['mlid'],
              'router_path' => $child['router_path'],
              );
            menu_link_save($new_child, $child);
          }
          // Then fix second level menu children for this menu
          //   they were automatically moved here when moving the first level
          //   menu children.
          $result = db_select('menu_links', 'n')
            ->fields('n', array('mlid'))
            ->condition('depth', 2)
            ->condition('menu_name', $menu_machine_name)
            ->execute()
            ->fetchCol();
          foreach ($result as $item) {
            $child = menu_link_load($item);
            if ($child['plid']==0) {
              print_r($child);
              echo PHP_EOL;
            }
            if (empty($child['options'])) {
              $child_options = array('attributes' => array('title' => ''));
            }
            else {
              $child_options = $child['options'];
            }
            $new_child = array (
              'link_path' => $child['link_path'],
              'link_title' => $child['link_title'],
              'menu_name' => $menu_machine_name,
              'weight' => $child['weight'],
              'expanded' => 0,
              'options' => $child_options,
              'mlid' => $child['mlid'],
              'plid' => $child['plid'],
              'router_path' => $child['router_path'],
              );
            menu_link_save($new_child, $child);
          }
        }
      }
    }
    if (!empty($added_menus)) {
      // add the menus to content (node) types uib_article and uib_testimonial
      $content_types = array('uib_article', 'uib_testimonial');
      foreach ($content_types as $content_type) {
        $menu_options = variable_get("menu_options_$content_type");
        if (empty($menu_options)) {
          $menu_options = array();
        }
        // remove the old area menu if it is still on the list
        $key = array_search('area', $menu_options);
        if ($key !== FALSE) {
          array_splice($menu_options, $key, 1);
        }
        $menu_options = array_merge($menu_options, $added_menus);
        variable_set("menu_options_$content_type", $menu_options);
      }
    }
  }
}
