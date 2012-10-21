<?php
/**
 * @file
 * uib_feature_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_feature_article_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uib_feature_article_node_info() {
  $items = array(
    'uib_article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Articles is the main content type.  We use it for news, events and pages.  Articles belong to areas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
