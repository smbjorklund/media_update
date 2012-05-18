<?php

  function uib_migrate_drush_command() {
    $items['uib-migrate-find-parents'] = array(
      'description' => 'Traverses articles of the type infopage and tries to find the parent node',
      'aliases' => array('uib-fp',),
      'examples' => array(
        'drush uib-fp' => 'Tries to find parents of existing nodes',
        ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
      'arguments' => array(),
      'options' => array(),
    );
    $items['uib-migrate-build-menu'] = array(
      'description' => 'Recursive traversal of node starting at top level menu item',
      'aliases' => array('uib-bm',),
      'examples' => array(
        'drush uib-fp' => 'Tries to recursive build menu',
        ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
      'arguments' => array(),
      'options' => array(),
    );
    return $items;
  }

  function drush_uib_migrate_find_parents() {
    $query = db_select('node', 'n');
    $query->join('field_data_field_uib_w2_nav_parent_id', 'p', 'n.nid=p.entity_id');
    $query->join('field_data_field_uib_article_type', 't', 'n.nid=t.entity_id');
    $query->join('taxonomy_term_data', 'term', 't.field_uib_article_type_tid=term.tid');
    $query->fields('p', array('field_uib_w2_nav_parent_id_value'))
      ->fields('n', array('nid'));
    $query->condition('term.name', 'infopage', '=');
    $result = $query->execute();

    foreach ($result as $r) {
      $query = db_select('node', 'n');
      $query->join('field_data_field_uib_w2_id','w2id', 'n.nid=w2id.entity_id');
      $query->fields('n', array('nid'));
      $query->condition('w2id.field_uib_w2_id_value', $r->field_uib_w2_nav_parent_id_value, '=');
      if($pid = $query->execute()->fetchAssoc()) {
        $id = db_insert('field_data_field_uib_nav_parent')
          ->fields(array(
            'entity_type' => 'node',
            'bundle' => 'uib_article',
            'deleted' => 0,
            'entity_id' => $r->nid,
            'delta' => 0,
            'field_uib_nav_parent_target_id' => $pid['nid'],
            ))
          ->execute();
        print('Parent found and inserted for node '.$id."\n");
      }
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
          $menu_link = array(
            'menu_name' => 'area',
            'link_path' => 'node/' . $kid_nid,
            'link_title' => $kid_node->title,
            'weight' => 0,
            'plid' => $mlid,
          );
          $kid_mlid = menu_link_save($menu_link);
          drush_log("Created menu link for node $kid_nid");
        }

        uib_migrate__build_menu_tree($kid_node, $kid_mlid, $depth+1);
      }
    }
  } 


