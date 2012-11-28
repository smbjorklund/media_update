<?php
/**
 * @file
 * uib_setup.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_setup_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'colofon';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~webdesk' => '~webdesk',
        '~webdesk/*' => '~webdesk/*',
        '~node/*/edit' => '~node/*/edit',
        '~node/*/delete' => '~node/*/delete',
        '~node/add/*' => '~node/add/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_area-colophon' => array(
          'module' => 'uib_area',
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
  t('block');
  $export['colofon'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faculties_navigation';
  $context->description = 'Temporary faculties navigation';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-faculties-block_1' => array(
          'module' => 'views',
          'delta' => 'faculties-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Temporary faculties navigation');
  t('block');
  $export['faculties_navigation'] = $context;

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
          'weight' => '-9',
        ),
        'menu_block-top-area-menu' => array(
          'module' => 'menu_block',
          'delta' => 'top-area-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'menu_block-page-area-menu' => array(
          'module' => 'menu_block',
          'delta' => 'page-area-menu',
          'region' => 'sidebar_second',
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
