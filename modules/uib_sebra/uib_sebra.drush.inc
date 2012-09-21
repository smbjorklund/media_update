<?php
/**
 * @file
 * @return [type] [description]
 */
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
  $items['uib-sebra-user'] = array(
    'description' => 'Syncronize the given user from Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'user' => 'The username',
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

function drush_uib_sebra_places() {
  $limit = (int)drush_get_option('limit', 0);
  uib_sebra__sync_places($limit);
}

function drush_uib_sebra_uib_dump_place($place_id) {
  $place = new SebraPlace($place_id);
  print_r($place);
}

function drush_uib_sebra_areas() {
  uib_sebra__sync_areas();
}

function drush_uib_sebra_user($user) {
  uib_sebra__sync_user($user);
}

function drush_uib_sebra_users() {
  $limit = (int)drush_get_option('limit', 5);
  uib_sebra__sync_users($limit);
}
