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

$path = array();

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
    if (isset($ignore[$w2_path]) ||
        startswith($w2_path, 'system/') ||
        startswith($w2_path, 'prototyper/') ||
        startswith($w2_path, 'ub/fagressurser/') ||
        startswith($w2_path, 'ub/resources/') ||
        FALSE)
    {
      if (empty($ignore[$w2_path]))
        $ignore[$w2_path] = 1;
      else
        $ignore[$w2_path]++;
      $paths['ignored'][$w2_path] = NULL;
    }
    elseif (area_already_present($w2_path)) {
      $paths['new2'][$w2_path] = NULL;
    }
    else {
      $paths['unmigrated'][$w2_path] = NULL;
      $count_tobe_migrated++;
    }
  }
  else {
    assert(!isset($ignore[$w2_path]), "Migrated area $w2_path is to be ignored");
    $nids = array_keys($result['node']);
    foreach ($nids as $nid) {
      $w3_path = w3_path($nid);
      $seen[$w3_path] = 1;
      $paths['migrated'][$w2_path] = $w3_path;
    }
    $count_migrated++;
  }
}

foreach ($ignore as $path => $count) {
  if ($count == 1)
    continue;
  $paths['badignore']['path'] = NULL;
}

# Determine areas only present in w3
$query = new EntityFieldQuery;
$result = $query
->entityCondition('entity_type', 'node')
->entityCondition('bundle', 'area')
->addMetaData('account', $admin)
->execute();

foreach (array_keys($result['node']) as $nid) {
  $w3_path = w3_path($nid);
  if (empty($seen[$w3_path])) {
    $paths['new3'][$w3_path] = NULL;
  }
}

# Generate report
print "# w3 migration status as of " . strftime("%F") . "\n";

if ($count_tobe_migrated + $count_migrated > 0) {
  printf("%.1f%% of the areas have been migrated from w2 to w3.\n", $count_migrated / ($count_migrated + $count_tobe_migrated) * 100);
}

$sections = array(
  array('unmigrated', 'Not yet migrated'),
  array('new2', 'Not migrated but created new in w3'),
  array('new3', 'New in w3'),
  array('migrated', 'Migrated'),
  array('ignored', 'Ignored'),
  array('badignore', 'Ignored (non existing paths)'),
);

foreach($sections as $section) {
  list($id, $title) = $section;
  if (!isset($paths[$id]))
    continue;
  $p = $paths[$id];
  unset($paths[$id]);
  print "\n## $title (" . count($p) . ")\n\n";
  ksort($p);
  foreach($p as $p1 => $p2) {
    print "    $p1";
    if ($p2) {
      print " => $p2";
    }
    print "\n";
  }
}

if (!empty($paths)) {
  print "\n";
  print_r($paths);
}

function area_already_present($w2_path) {
  $lang = NULL;
  $path = $w2_path;
  if (substr($w2_path, -3) == '/en') {
    $path = substr($w2_path, 0, -3);
    $lang = 'en';
  }
  elseif (substr($w2_path, 0, 3) == 'en/') {
    $path = substr($w2_path, 3);
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

function startswith($str, $prefix) {
  return substr($str, 0, strlen($prefix)) == $prefix;
}
