<?php
/**
 * @file
 * uib_article.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function uib_article_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_uib_show_global_calendar'
  $field_bases['field_uib_show_global_calendar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_uib_show_global_calendar',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
