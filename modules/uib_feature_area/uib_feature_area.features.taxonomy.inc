<?php
/**
 * @file
 * uib_feature_area.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_feature_area_taxonomy_default_vocabularies() {
  return array(
    'area_type' => array(
      'name' => 'Area Type',
      'machine_name' => 'area_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
