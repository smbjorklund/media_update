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
