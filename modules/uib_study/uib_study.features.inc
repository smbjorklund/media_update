<?php
/**
 * @file
 * uib_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_study_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uib_study_node_info() {
  $items = array(
    'uib_study' => array(
      'name' => t('Study'),
      'base' => 'node_content',
      'description' => t('Used to represent both programs and the individual courses'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
