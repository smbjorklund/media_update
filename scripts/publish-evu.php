<?php

$admin = user_load(1);
$query = new EntityFieldQuery;
$query = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'uib_study')
  ->propertyCondition('status', 0)
  ->fieldCondition('field_uib_study_category', 'value', 'evu')
  ->addMetaData('account', $admin);

$result = $query->execute();
if (empty($result)) {
  print("No unpublished evu nodes\n");
}
else {
  $nodes = node_load_multiple(array_keys($result['node']));

  foreach ($nodes as $evu) {
    $evu->status = 1;
    node_save($evu);
    $code = $evu->field_uib_study_code['und'][0]['value'];
    echo "Published $code $evu->title\n";
  }
}
