<?php

$w2_id = array();

$result = db_query("SELECT uid FROM {users} WHERE name like 'User stub %'");
foreach ($result as $row) {
  $stub = user_load($row->uid);
  $w2_id[$stub->uid] = $stub->field_uib_w2_id['und'][0]['value'];
}

foreach ($w2_id as $stub_uid => $w2_id) {
  $other_uids = array();
  $result = db_query(
    "SELECT entity_id FROM {field_data_field_uib_w2_id} WHERE field_uib_w2_id_value = ? AND entity_id != ?",
    array($w2_id, $stub_uid)
  );
  foreach ($result as $row) {
    $other_uids[] = $row->entity_id;
  }
  if (empty($other_uids)) {
    print " - no other user found\n";
  }
  elseif (count($other_uids) > 1) {
    print " - " . count($other_uids) . " other users found\n";
  }
  else {
    fix_stub_user($stub_uid, $other_uids[0]);
  }
}

function fix_stub_user($stub_uid, $real_uid) {
  $stub = user_load($stub_uid);
  $user = user_load($real_uid);
  print "$stub->name ($stub_uid) --> $user->name ($real_uid)\n";
  if ($stub->status) {
    $stub->status = 0;
    user_save($stub);
    print " - stub user unpublished\n";
  }

  // Find authors, bylines and contacts where this stub user is used
  $ref = array();

  $result = db_query(
    "SELECT nid FROM {node} WHERE uid = ?",
    array($stub_uid)
  );
  foreach ($result as $row) {
    $ref[$row->nid][] = 'author';
  }

  $result = db_query(
    "SELECT entity_id FROM {field_data_field_uib_byline} WHERE field_uib_byline_target_id = ?",
    array($stub_uid)
  );
  foreach ($result as $row) {
    $ref[$row->entity_id][] = 'byline';
  }

  $result = db_query(
    "SELECT entity_id FROM {field_data_field_uib_contacts} WHERE field_uib_contacts_target_id = ?",
    array($stub_uid)
  );
  foreach ($result as $row) {
    $ref[$row->entity_id][] = 'contact';
  }

  if (!empty($ref)) {
    foreach ($ref as $nid => $roles) {
      print " node/$nid: " . implode(', ', $roles) . "\n";
    }
  }

  # Start updating
  db_update('node')
    ->fields(array('uid' => $real_uid))
    ->condition('uid', $stub_uid)
    ->execute();
  db_update('field_data_field_uib_byline')
    ->fields(array('field_uib_byline_target_id' => $real_uid))
    ->condition('field_uib_byline_target_id', $stub_uid)
    ->execute();
  db_update('field_data_field_uib_contacts')
    ->fields(array('field_uib_contacts_target_id' => $real_uid))
    ->condition('field_uib_contacts_target_id', $stub_uid)
    ->execute();
}
