<?php

/* This script lists all the areas in w2 with a '+' in front of the path of those not yet
 * migrated and a '-' in front of those have migrated.
 */

$ignore = array();
foreach (file("../modules/uib_migrate/not-to-be-migrated.txt", FILE_IGNORE_NEW_LINES|FILE_SKIP_EMPTY_LINES) as $line) {
  $line = trim($line);
  if (substr($line, 0, 1) == '#')
    continue;
  $ignore[$line] = 0;
}

$count_migrated = 0;
$count_tobe_migrated = 0;

$admin = user_load(1);
$seen = array();

$topiclist = simplexml_load_file("http://www.uib.no/topicmap/@@xtopic?type=area&allinstances&limit=0");
foreach ($topiclist->topic as $topic) {
  $w2_path = substr($topic['path'], 1);

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_w2_id', 'value', $topic['id'])
    ->addMetaData('account', $admin)
    ->execute();

  if (empty($result)) {
    if (isset($ignore[$w2_path])) {
      $ignore[$w2_path]++;
      print ";; $w2_path\n";
    }
    elseif (area_already_present($w2_path)) {
      print "-+ $w2_path\n";
    }
    else {
      print "++ $w2_path\n";
      $count_tobe_migrated++;
    }
  }
  else {
    assert(!isset($ignore[$w2_path]), "Migrated area $w2_path is to be ignored");
    $nids = array_keys($result['node']);
    foreach ($nids as $nid) {
      $w3_path = w3_path($nid);
      $seen[$w3_path] = 1;
      print((count($nids) > 1 ? "-!" : "--") . " $w2_path ➡︎ $w3_path\n");
    }
    $count_migrated++;
  }
}

foreach ($ignore as $path => $count) {
  if ($count == 1)
    continue;
  print "?? $path\n";
}

if ($count_tobe_migrated + $count_migrated > 0) {
  printf("### %.1f%% migrated\n", $count_migrated / ($count_migrated + $count_tobe_migrated) * 100);
}

# Report any areas present in w3
$query = new EntityFieldQuery;
$result = $query
->entityCondition('entity_type', 'node')
->entityCondition('bundle', 'area')
->addMetaData('account', $admin)
->execute();

foreach (array_keys($result['node']) as $nid) {
  $w3_path = w3_path($nid);
  if (empty($seen[$w3_path])) {
    print "<> $w3_path\n";
  }
}

function area_already_present($w2_path) {
  $lang = NULL;
  $path = $w2_path;
  if (substr($w2_path, -3) == '/en') {
    $path = substr($w2_path, 0, -3);
    $lang = 'en';
  }
  elseif (substr($w2_path, 0, 3) == 'fg/') {
    $lang = 'nb';
  }
  elseif (substr($w2_path, 0, 3) == 'rg/') {
    $lang = 'en';
  }
  $languages = $lang ? array($lang) : array('nb', 'en');
  foreach ($languages as $lang) {
    if (drupal_get_normal_path($path, $lang) != $path) {
      return TRUE;
    }
  }
  return FALSE;
}

function w3_path($nid) {
  $node_path = "node/$nid";
  foreach (array("nb", "en") as $lang) {
    $w3_path = drupal_get_path_alias($node_path, $lang);
    if ($w3_path != $node_path) {
      $w3_path = "$lang/$w3_path";
      return $w3_path;
    }
  }
  return $node_path;
}
