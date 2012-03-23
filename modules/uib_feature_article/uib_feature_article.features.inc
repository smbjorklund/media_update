<?php
/**
 * @file
 * uib_feature_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_article_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function uib_feature_article_node_info() {
  $items = array(
    'uib_article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
