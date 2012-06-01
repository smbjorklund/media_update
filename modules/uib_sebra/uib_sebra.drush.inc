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

function drush_uib_sebra_users() {
  $limit = (int)drush_get_option('limit', 5);
  $users = array_merge(
    uib_sebra__get_persons('staff'),
    uib_sebra__get_persons('extern')
  );
  $users = array('adbho', 'gaa041', 'sbj051'); // debug with a smaller set
  foreach ($users as $username) {
    $u = new SebraPerson($username);
    print_r($u);

    if ($limit) {
      if (--$limit == 0)
        break;
    }
  }
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
