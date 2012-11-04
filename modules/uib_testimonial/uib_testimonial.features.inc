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
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Testimonials from former students collects quotes about how UiB changed the life of thousands for the better.  Testimonials also demonstrate the wonderful career that former UiB is destined to have.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
  );
  return $items;
}
