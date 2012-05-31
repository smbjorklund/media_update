<?php

function uib_sebra_drush_command() {
  $items['uib-sebra-places'] = array(
    'description' => 'Syncronize places in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_uib_sebra_places() {
  $places = simplexml_load_file('http://sebra.uib.no/sws/places?status=aktiv');
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

  }
}

function uib_sebra__create_uib_ou($place_id) {
  $place = new SebraPlace($place_id);
  $node = new stdClass();
  $node->type = 'uib_ou';
  $node->title = $place->name;
  $node->uid = 1;
  $node->status = 1;
  $node->revision = 0;
  $node->language = 'und';
  $node->field_uib_ou_id['und'][0]['value'] = $place_id;
  $node->field_uib_ou_shortname['und'][0]['value'] = $place->alias;

  $node->field_uib_postal_address['und'][0]['thoroughfare'] = 'Postboks ' . $place->postbox;
  $node->field_uib_postal_address['und'][0]['postal_code'] = $place->postcode;
  $node->field_uib_postal_address['und'][0]['locality'] = $place->postarea;
  $node->field_uib_postal_address['und'][0]['country'] = 'NO';

  $node->field_uib_visit_address['und'][0]['thoroughfare'] = $place->address;
  $node->field_uib_visit_address['und'][0]['postal_code'] = $place->postcode;
  $node->field_uib_visit_address['und'][0]['locality'] = $place->postarea;
  $node->field_uib_visit_address['und'][0]['country'] = 'NO';

  node_save($node);
  return $node->nid;
}
