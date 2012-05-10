<?php
/**
 * @file
 * uib_feature_testimonial.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uib_feature_testimonial_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_uib_testimonial';
  $strongarm->value = '0';
  $export['language_content_type_uib_testimonial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_uib_testimonial';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_uib_testimonial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_uib_testimonial';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_uib_testimonial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_uib_testimonial';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_uib_testimonial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_uib_testimonial';
  $strongarm->value = '1';
  $export['node_preview_uib_testimonial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_uib_testimonial';
  $strongarm->value = 1;
  $export['node_submitted_uib_testimonial'] = $strongarm;

  return $export;
}
