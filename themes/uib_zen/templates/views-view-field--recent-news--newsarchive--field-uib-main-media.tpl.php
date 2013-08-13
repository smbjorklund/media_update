<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

global $theme_path;
global $base_root;
$style_name = $field->view->field['field_uib_main_media']->options['settings']['file_view_mode'];
$node_alias = drupal_get_path_alias('node/' . $row->nid, $row->node_language);

if (!isset($row->field_field_uib_main_media[0]['raw']['uri'])) {
  $image = theme('image', array(
    'path' => $base_root . '/' . $theme_path . '/images/Recent_High.png',
    'style_name' => $style_name,
  ));
}
else {
  $image = $row->field_field_uib_main_media[0]['rendered']['file'];
}

$image = render($image);
$link = array(
  '#type' => 'link',
  '#title' => $image,
  '#href' => $node_alias,
  '#options' => array('html' => TRUE, ),
);
?>

<span class="field-content">
  <?php print render($link); ?>
</span>
