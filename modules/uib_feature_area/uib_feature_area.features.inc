<?php
/**
 * @file
 * uib_feature_area.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_area_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function uib_feature_area_node_info() {
  $items = array(
    'uib_ou' => array(
      'name' => t('Organisational Unit'),
      'base' => 'node_content',
      'description' => t('This matches the places as defined by PAGA and Sebra.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
