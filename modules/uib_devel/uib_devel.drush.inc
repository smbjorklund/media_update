<?php

function uib_devel_drush_command() {
  $items = array();
  $items['node'] = array(
    'description' => 'Dump information about the given node',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'id' => 'Node id or path',
    ),
    'required-arguments' => TRUE,
    'options' => array(
      'dump' => 'Dump the raw node structure (with print_r)',
      'show-empty' => 'Show the empty fields as well',
    ),
  );
  $items['usr'] = array(
    'description' => 'Dump information about the given user',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'id' => 'Numeric user id or username',
    ),
    'required-arguments' => TRUE,
    'options' => array(
      'dump' => 'Dump the raw node structure (with print_r)',
      'show-empty' => 'Show the empty fields as well',
    ),
  );
  return $items;
}

function drush_uib_devel_usr($id) {
  $account = NULL;
  if (is_numeric($id)) {
    $account = user_load($id, TRUE);
  }
  else {
    $account = user_load_by_name($id);
  }
  if (!$account) {
    uibx_log("account $id does not exist", 'error');
    return;
  }
  if (drush_get_option('dump')) {
    print_r($account);
    return;
  }
  print "uid: $account->uid\n";
  print "name: $account->name\n";
  print "mail: $account->mail\n";

  // dump timestamps
  print "created: " . strftime('%Y-%m-%d %H:%M', $account->created) . "\n";
  print "access: " . strftime('%Y-%m-%d %H:%M', $account->access) . "\n";
  print "login: " . strftime('%Y-%m-%d %H:%M', $account->login) . "\n";

  uib_devel__dump_fields($account);
}

function drush_uib_devel_node($id) {
  $node = NULL;
  if (is_numeric($id)) {
    $node = node_load($id);
  }
  else {
    $lang = 'nb';
    if (in_array(substr($id, 0, 3), array('en/', 'nb/'))) {
      $lang = substr($id, 0, 2);
      $id = substr($id, 3);
    }
    $path = drupal_get_normal_path($id, $lang);
    if (substr($path, 0, 5) == 'node/')
      $node = node_load(substr($path, 5));
  }
  if (!$node) {
    uibx_log("Node $id does not exist", 'error');
    return;
  }
  if (drush_get_option('dump')) {
    print_r($node);
    return;
  }

  //print "nid: $node->nid\n";
  $path = 'node/' . $node->nid;
  print "path:";
  foreach (array('nb', 'en') as $lang) {
    $alias = drupal_get_path_alias($path, $lang);
    if ($alias != $path)
      print " $lang/$alias";
  }
  print " $path\n";
  print "uid: $node->uid ($node->name)\n";
  //print "vid: $node->vid\n";
  print "type: $node->type\n";
  if ($node->language != 'und')
    print "language: $node->language\n";
  print "title: $node->title\n";

  // dump timestamps
  print "created: " . strftime('%Y-%m-%d %H:%M', $node->created) . "\n";
  print "changed: " . strftime('%Y-%m-%d %H:%M', $node->changed) . "\n";

  uib_devel__dump_fields($node);
}


function uib_devel__dump_fields($entity) {
  $arr = array_keys((array)$entity);
  sort($arr);
  foreach ($arr as $key) {
    if (substr($key, 0, 6) == 'field_') {
      $languages = $entity->$key;
      if (empty($languages)) {
        if (drush_get_option('show-empty')) {
          print "$key: <empty>\n";
        }
      }
      else {
        foreach ($languages as $lang => $values) {
          print $key;
          if ($lang != 'und')
            print "[$lang]";
          print ": ";

          $printed = array();
          foreach ($values as $val) {
            if (isset($val['target_id'])) {
              $printed[] = $val['target_id'];
            }
            elseif (isset($val['fid'])) {
              $printed[] = 'fid:' . $val['fid'];
            }
            elseif (isset($val['value'])) {
              if (strlen($val['value']) < 60)
                $printed[] = $val['value'];
              else
                $printed[] = substr($val['value'], 0, 57) . "...";
            }
            elseif (isset($val['url'])) {
              $printed[] = '[' . $val['title'] . '](' . $val['url'] . ')';
            }
            elseif (isset($val['postal_code'])) {
              $printed[] = $val['thoroughfare'] . ', ' . $val['postal_code'] . ' ' . $val['locality'];
            }
            elseif (isset($val['wkt'])) {
              $printed[] = $val['wkt'];
            }
            else {
              $printed[] = '?';
            }
          }
          print implode(', ', $printed);
          print "\n";
        }
      }
    }
  }
}
