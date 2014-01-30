<?php

# This script might be useful to test the study syncer.  It just finds a few
# victim studies and deletes them.  The 'drush uib-sync-fs' run should
# then be able to restore them.


$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->fieldCondition('field_uib_study_type', 'value', 'course')
  ->execute();

for ($i = 0; $i < 2; $i++) {
  $n = node_load(array_rand($result['node']));
  print "$n->title\n";
  node_delete($n->nid);
}

$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->fieldCondition('field_uib_study_type', 'value', 'program')
  ->execute();


$program = node_load(array_rand($result['node']));
print "Program: $program->nid $program->title\n";

$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->fieldCondition('field_uib_study_part_of', 'target_id', $program->nid)
  ->execute();

for ($i = 0; $i < 2; $i++) {
  $n = node_load(array_rand($result['node']));
  print "- $n->title\n";
  node_delete($n->nid);
}

node_delete($program->nid);
