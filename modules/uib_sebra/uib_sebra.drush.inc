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
  return $items;
}

function drush_uib_sebra_places() {
  $places = simplexml_load_file('http://sebra.uib.no/sws/places?status=aktiv');
  $limit = (int)drush_get_option('limit', 0);

  foreach ($places->place as $place) {
    $place_id = (string)$place->code;

    $query = new EntityFieldQuery;
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->fieldCondition('field_uib_ou_id', 'value', $place_id, '=')
      ->range(0,1)
      ->execute();

    if (empty($result['node'])) {
      $nid = uib_sebra__create_uib_ou($place_id);
      drush_log("Created node $nid for place $place_id $place->name");
    }
    else {
      $nids = array_keys($result['node']);
      $nid = $nids[0];
      drush_log("Node $nid corresponds to $place_id $place->name");
    }

    if ($limit) {
      if (--$limit == 0)
        break;
    }
  }
}
