<?php
/**
 * @file
 * uib_feature_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_feature_article_taxonomy_default_vocabularies() {
  return array(
    'article_type' => array(
      'name' => 'Article Type',
      'machine_name' => 'article_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
