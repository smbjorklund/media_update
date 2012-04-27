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
