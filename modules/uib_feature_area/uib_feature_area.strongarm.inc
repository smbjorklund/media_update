<?php
/**
 * @file
 * uib_feature_area.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uib_feature_area_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_uib_ou';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_uib_ou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_uib_ou';
  $strongarm->value = '1';
  $export['node_preview_uib_ou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_uib_ou';
  $strongarm->value = 0;
  $export['node_submitted_uib_ou'] = $strongarm;

  return $export;
}
