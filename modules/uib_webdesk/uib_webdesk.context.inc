<?php
/**
 * @file
 * uib_webdesk.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_webdesk_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'webdesk';
  $context->description = 'Drop regons based on context';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'webdesk' => 'webdesk',
        'webdesk/*' => 'webdesk/*',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'uib_zen' => array(
        'disable' => array(
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drop regons based on context');
  t('layout');
  $export['webdesk'] = $context;

  return $export;
}
