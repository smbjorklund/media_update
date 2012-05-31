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
  $it = new SebraPlace('221000');
  print_r($it);
  drush_log('nyi', 'error');
}
