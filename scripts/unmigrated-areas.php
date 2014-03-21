<?php

/* This script lists all the areas in w2 with a '+' in front of the path of those not yet
 * migrated and a '-' in front of those have migrated.
 */

$topiclist = simplexml_load_file("http://www.uib.no/topicmap/@@xtopic?type=area&allinstances&limit=0");
foreach ($topiclist->topic as $topic) {
  $w2_path = substr($topic['path'], 1);

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_w2_id', 'value', $topic['id'])
    ->execute();

  if (empty($result)) {
    print "+ $w2_path\n";
  }
  else {
    $nids = array_keys($result['node']);
    assert(count($nids) == 1, "More than one node with w2_id of " . $topic['id']);
    $node_path = "node/$nids[0]";
    foreach (array("nb", "en") as $lang) {
      $w3_path = drupal_get_path_alias($node_path, $lang);
      if ($w3_path != $node_path) {
        $w3_path = "$lang/$w3_path";
        break;
      }
    }

    print "- $w2_path ➡︎ $w3_path\n";
  }
}
