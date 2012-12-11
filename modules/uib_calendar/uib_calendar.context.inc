<?php
/**
 * @file
 * uib_calendar.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_calendar_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'calendar:page_2' => 'calendar:page_2',
        'calendar:page_4' => 'calendar:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'calendar-block_2',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-calendar-block_3' => array(
          'module' => 'views',
          'delta' => 'calendar-block_3',
          'region' => 'content_top',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['calendar'] = $context;

  return $export;
}
