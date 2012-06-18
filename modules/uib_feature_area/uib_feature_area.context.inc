<?php
/**
 * @file
 * uib_feature_area.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_feature_area_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_menu';
  $context->description = 'Set up area menu to show in the side bar';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-area' => array(
          'module' => 'menu',
          'delta' => 'area',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set up area menu to show in the side bar');
  $export['area_menu'] = $context;

  return $export;
}
