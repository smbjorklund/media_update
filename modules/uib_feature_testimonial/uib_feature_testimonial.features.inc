<?php
/**
 * @file
 * uib_feature_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_testimonial_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uib_feature_testimonial_node_info() {
  $items = array(
    'uib_testimonial' => array(
      'name' => t('Vitnesbyrd'),
      'base' => 'node_content',
      'description' => t('Norsk beskrivelse manger her.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => t('Norsk beskrivelse manger her.'),
    ),
  );
  return $items;
}
