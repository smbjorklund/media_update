<?php
/**
 * @file
 * uib_area.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_area_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_blocks';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'area' => 'area',
        'uib_article' => 'uib_article',
        'uib_testimonial' => 'uib_testimonial',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-global-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-global-menu',
          'region' => 'header',
          'weight' => '-10',
        ),
        'uib_area-area_parents' => array(
          'module' => 'uib_area',
          'delta' => 'area_parents',
          'region' => 'sidebar_second',
          'weight' => '-22',
        ),
        'views-calendar-block_1' => array(
          'module' => 'views',
          'delta' => 'calendar-block_1',
          'region' => 'sidebar_second',
          'weight' => '-21',
        ),
        'views-calendar-block_4' => array(
          'module' => 'views',
          'delta' => 'calendar-block_4',
          'region' => 'sidebar_second',
          'weight' => '-20',
        ),
        'views-recent_news-block' => array(
          'module' => 'views',
          'delta' => 'recent_news-block',
          'region' => 'sidebar_second',
          'weight' => '-19',
        ),
        'uib_area-feed' => array(
          'module' => 'uib_area',
          'delta' => 'feed',
          'region' => 'sidebar_second',
          'weight' => '-18',
        ),
        'uib_area-jobbnorge' => array(
          'module' => 'uib_area',
          'delta' => 'jobbnorge',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['area_blocks'] = $context;

  return $export;
}
