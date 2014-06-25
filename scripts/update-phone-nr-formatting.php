<?php

// Norwegian style format on phone and fax numbers (uib_ou)
$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'uib_ou')
  ->execute();
$ou_nodes = entity_load('node', array_keys($result['node']));
foreach ($ou_nodes as $nid => $node) {
  node_save($node);
}

// Norwegian style format on phone numbers (user)
$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'user')
  ->fieldCondition('field_uib_phone', 'value', '', '>')
  ->execute();
$users = entity_load('user', array_keys($result['user']));
foreach ($users as $uid => $user_entity) {
  user_save($user_entity);
}
