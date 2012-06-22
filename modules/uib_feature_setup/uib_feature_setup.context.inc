<?php
/**
 * @file
 * uib_feature_setup.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_feature_setup_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'navigation';
  $context->description = 'Basic navigation for the whole site';
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-faculties-block' => array(
          'module' => 'views',
          'delta' => 'faculties-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic navigation for the whole site');
  $export['navigation'] = $context;

  return $export;
}
