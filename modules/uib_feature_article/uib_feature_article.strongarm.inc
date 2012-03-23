<?php
/**
 * @file
 * uib_feature_article.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uib_feature_article_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_uib_article';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_uib_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_uib_article';
  $strongarm->value = '1';
  $export['node_preview_uib_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_uib_article';
  $strongarm->value = 1;
  $export['node_submitted_uib_article'] = $strongarm;

  return $export;
}
