<?php
/**
 * @file
 * @return [type] [description]
 */
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
  return $items;
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

  // dump the fields
  $arr = array_keys((array)$node);
  sort($arr);
  foreach ($arr as $key) {
    if (substr($key, 0, 6) == 'field_') {
      $languages = $node->$key;
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
