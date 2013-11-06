<?php

$query = new EntityFieldQuery;
$query = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'area')
  ->propertyCondition('title', 'Utdanning');

$result = $query->execute();
if ($result) {
  $nids = array_keys($result['node']);
  if (count($nids) == 1)
    $edu_nid = $nids[0];
}

if ($edu_nid) {
  variable_set('uib_study_area_nid', $edu_nid);
  uibx_log("Found Utdanning area to use nid=$edu_nid; initialized uib_study_area_nid variable");
}
else {
  uibx_log("Can't Utdanning area", 'error');
}
