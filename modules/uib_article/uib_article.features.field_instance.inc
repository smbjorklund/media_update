<?php
/**
 * @file
 * uib_article.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function uib_article_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-uib_article-field_uib_show_global_calendar'
  $field_instances['node-uib_article-field_uib_show_global_calendar'] = array(
    'bundle' => 'uib_article',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'short_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_uib_show_global_calendar',
    'label' => 'Show in global calendar',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Show in global calendar');

  return $field_instances;
}
