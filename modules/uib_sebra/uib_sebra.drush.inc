<?php

function uib_sebra_drush_command() {
  $items['uib-sebra-places'] = array(
    'description' => 'Syncronize places in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(
      'limit' => 'Only process this many places before terminating',
    ),
  );
  $items['uib-dump-place'] = array(
    'description' => 'Get a place object from Sebra and dump its attributes',
    'arguments' => array(
      'place-id' => 'The 6-digit place code of the place to dump',
    ),
    'required-arguments' => TRUE,
  );
  $items['uib-sebra-areas'] = array(
    'description' => 'Syncronize areas in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
  );
  $items['uib-sebra-users'] = array(
    'description' => 'Syncronize users in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(
      'limit' => 'Only process this many users before terminating',
    ),
  );
  return $items;
}

function drush_uib_sebra_places() {
  $places_url = "http://sebra.uib.no/sws/places?status=aktiv";
  drush_log("GET $places_url");
  $places = simplexml_load_file($places_url);
  $limit = (int)drush_get_option('limit', 0);

  foreach ($places->place as $place) {
    $place_id = (string)$place->code;
    $nid = uib_sebra__uib_ou_nid($place_id);
    if ($nid === NULL) {
      $node = uib_sebra__create_uib_ou($place_id);
      drush_log("Created node $node->nid for place $place_id $place->name");
    }
    else {
      drush_log("Node $nid corresponds to $place_id $place->name");
    }

    if ($limit) {
      if (--$limit == 0)
        break;
    }
  }
}

function drush_uib_sebra_uib_dump_place($place_id) {
  $place = new SebraPlace($place_id);
  print_r($place);
}

function drush_uib_sebra_areas() {
  // Fill this array with what areas each user belongs to
  $user_tid = array();

  $area_type = taxonomy_vocabulary_machine_name_load('area');
  $query = new EntityFieldQuery;
  $query = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', $area_type->vid)
    ;
  $result = $query->execute();

  $got_them_all = TRUE;

  foreach (array_keys($result['taxonomy_term']) as $tid) {
    $term = taxonomy_term_load($tid);
    $sebra_id = $term->field_uib_sebra_id['und'][0]['value'];
    if ($sebra_id) {
      $area_url = "http://sebra.uib.no/sws/omraader?omraadekode=$sebra_id";
      drush_log("GET $area_url");
      $area_doc = simplexml_load_file($area_url);
      if (empty($area_doc)) {
        drush_log("Can't get $area_url", 'error');
        $got_them_all = FALSE;
      }
      #print_r(array($tid, $sebra_id, $area_doc));
      foreach ($area_doc->omraade->visninger->uibid as $uname) {
        $user_tid[(string)$uname][]['target_id'] = $tid;
      }
    }
    else {
      drush_log("No sebra_id for /taxonomy/term/$tid", 'warning');
    }
  }

  if (!$got_them_all) {
    drush_log("Can't update staff_at since some areas failed to load", 'error');
    return;
  }

  $unchanged = 0;
  foreach (array_keys($user_tid) as $username) {
    $account = user_load_by_name($username);
    if (!$account)
      $account = uib_sebra__sync_user($username);
    if ($account->field_uib_staff_at['und'] != $user_tid[$username]) {
      user_save($account, array(
        'field_uib_staff_at' => array('und' => $user_tid[$username]),
      ));
      drush_log("Updated staff_at setting for $username /user/$account->uid");
    }
    else {
      $unchanged++;
    }
  }
  drush_log("staff_at unchanged for $unchanged users");
}

function drush_uib_sebra_users() {
  $limit = (int)drush_get_option('limit', 5);
  $users = array_merge(
    uib_sebra__get_persons('staff'),
    uib_sebra__get_persons('extern')
  );
  //$users = array('adbho', 'gaa041', 'sbj051'); // debug with a smaller set
  $users_count = count($users);
  if ($limit) {
    drush_log("Starting to process $limit of $users_count users");
  }
  else {
    drush_log("Processing $users_count users");
  }

  foreach ($users as $username) {
    uib_sebra__sync_user($username);
    if ($limit) {
      if (--$limit == 0)
        break;
    }
  }

  // look for users to block
  $users = array_flip($users); // make it easy to look them up by username

  $query = new EntityFieldQuery;
  $query = $query
    ->entityCondition('entity_type', 'user')
    ->fieldCondition('field_uib_user_domain', 'value', 'uib', '=');
  $result = $query->execute();
  $active_count = 0;
  foreach (array_keys($result['user']) as $uid) {
    $account = user_load($uid);
    if (isset($users[$account->name])) {
      if ($account->status == 0) {
        user_save($account, array(
          'status' => 1, // ACTIVE
        ));
        drush_log("$account->name unblocked");
      }
      else {
        $active_count++;
      }
    }
    elseif ($account->status != 0) {
      user_save($account, array(
        'status' => 0, // BLOCKED
      ));
      drush_log("$account->name blocked");
    }
    else {
      drush_log("$account->name is still blocked");
    }
  }
  drush_log("$active_count uib-accounts are still active");
}

function uib_sebra__get_persons($type) {
  $persons_url = 'http://sebra.uib.no/sws/persons';
  if ($type)
    $persons_url .= "?type=$type";
  drush_log("GET $persons_url");
  $persons = simplexml_load_file($persons_url);
  $uids = array();
  foreach ($persons->person as $p) {
    $uids[] = (string)$p->id;
  }
  return $uids;
}

function uib_sebra__sync_user($username) {
  $account = user_load_by_name($username);
  $u = new SebraPerson($username);
  if ($account) {
    $edit = array();
    if ($account->mail != $u->email)
      $edit['mail'] = $u->email;
    if ($account->status != 1)
      $edit['status'] = 1;
    if ($account->field_uib_first_name['und'][0]['value'] != $u->first_name)
      $edit['field_uib_first_name']['und'][0]['value'] = $u->first_name;
    if ($account->field_uib_last_name['und'][0]['value'] != $u->last_name)
      $edit['field_uib_last_name']['und'][0]['value'] = $u->last_name;
    if ($account->field_uib_position['nb'][0]['value'] != $u->position_name_no)
      $edit['field_uib_position']['nb'][0]['value'] = $u->position_name_no;
    if ($account->field_uib_position['en'][0]['value'] != $u->position_name_en)
      $edit['field_uib_position']['en'][0]['value'] = $u->position_name_en;

    if (empty($edit)) {
      drush_log("No change for $username <$account->mail>");
    }
    else {
      user_save($account, $edit);
      drush_log("Updated fields for $username <$account->mail>");
    }
  }
  else {
    $account = new stdClass();
    $account->is_new = 1;
    $account->name = $u->id;
    $account->mail = $u->email;
    $account->status = 1; // ACTIVE
    $account->field_uib_user_domain['und'][0]['value'] = 'uib';
    $account->field_uib_first_name['und'][0]['value'] = $u->first_name;
    $account->field_uib_last_name['und'][0]['value'] = $u->last_name;
    $account->field_uib_position['nb'][0]['value'] = $u->position_name_no;
    $account->field_uib_position['en'][0]['value'] = $u->position_name_en;
    user_save($account);
    drush_log("Created user $account->uid for $username <$u->email>");
  }
  return $account;
}
