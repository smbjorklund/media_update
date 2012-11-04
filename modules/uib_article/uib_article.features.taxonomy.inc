<?php
/**
 * @file
 * uib_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_article_taxonomy_default_vocabularies() {
  return array(
    'research_topic_no' => array(
      'name' => 'Research Topic',
      'machine_name' => 'research_topic_no',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
