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
  $context->tag = 'block';
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
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu_block-top-area-menu' => array(
          'module' => 'menu_block',
          'delta' => 'top-area-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'menu_block-page-area-menu' => array(
          'module' => 'menu_block',
          'delta' => 'page-area-menu',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-faculties-block_1' => array(
          'module' => 'views',
          'delta' => 'faculties-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'uib_feature_area-colophon' => array(
          'module' => 'uib_feature_area',
          'delta' => 'colophon',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic navigation for the whole site');
  t('block');
  $export['navigation'] = $context;

  return $export;
}
