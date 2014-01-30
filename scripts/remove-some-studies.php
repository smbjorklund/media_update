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
  print "Deleted $n->title\n";
  node_delete($n->nid);
}

# Change some attributes on a few as well
for ($i = 0; $i < 2; $i++) {
  $n = node_load(array_rand($result['node']));
  print "Updated $n->title\n";
  $n->title = 'Kilroy was here!';
  $n->field_uib_study_category['und'][0]['value'] = 'foo';
  node_save($n);
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
