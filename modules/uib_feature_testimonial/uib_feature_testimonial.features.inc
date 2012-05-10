<?php
/**
 * @file
 * uib_feature_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_testimonial_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function uib_feature_testimonial_node_info() {
  $items = array(
    'uib_testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
