<?php

/* This script lists all the areas in w2 with a '+' in front of the path of those not yet
 * migrated and a '-' in front of those have migrated.
 */

$topiclist = simplexml_load_file("http://www.uib.no/topicmap/@@xtopic?type=area&allinstances&limit=0");
foreach ($topiclist->topic as $topic) {
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_w2_id', 'value', $topic['id'])
    ->execute();
  print (empty($result) ? "+" : '-') . ' ' . substr($topic['path'], 1) . "\n";
}
