<?php

// Moving geolocation data to a new field

// Moves existing long-lat geolocation data in uib_ou nodes
// from the field_uib_geo to the field_uib_geolocation

// Get nodes that have geolocation data
$query = new EntityFieldQuery;
$result = $query->entityCondition("entity_type", "node")
  ->propertyCondition("type", "uib_ou")
  ->fieldCondition("field_uib_geo", "lat", 0, ">")
  ->execute();

$ou_nodes = entity_load('node', array_keys($result['node']));
foreach ($ou_nodes as $nid => $ou) {
  if (!empty($ou->field_uib_geo)) {
    foreach ($ou->field_uib_geo['und'][0] as $key => $value) {
      $ou->field_uib_geolocation['und'][0][$key] = $value;
    }
    node_save($ou);
  }
}
