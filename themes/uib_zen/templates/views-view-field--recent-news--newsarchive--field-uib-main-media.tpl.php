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
?>
<?php
  global $base_root;
  if (isset($row->field_field_uib_main_media[0]['raw']['uri'])) {
    $alt = '';
    if (isset($row->field_field_uib_main_media[0]['raw']['field_file_image_alt_text']['und']))
      $alt = $row->field_field_uib_main_media[0]['raw']['field_file_image_alt_text']['und'][0]['safe_value'];
    $title = '';
    if (isset($row->field_field_uib_main_media[0]['raw']['field_file_image_title_text']['en']))
      $title = $row->field_field_uib_main_media[0]['raw']['field_file_image_title_text']['en'][0]['safe_value'];
    $image = theme('image_style', array(
      'style_name' => 'wide_thumbnail',
      'path' => $row->field_field_uib_main_media[0]['raw']['uri'],
      'alt' => $alt,
      'title' => $title,
      'attributes' => array(),
    ));
  }
  else {
    $image = theme('image', array(
      'path' => $base_root . '/sites/all/themes/uib/uib_zen/images/Recent_High.png',
    ));
  }
  $link = array(
    '#type' => 'link',
    '#title' => $image,
    '#href' => $field->last_tokens['[path]'],
    '#options' => array('html' => TRUE, ),
  );
?>
<span class="field-content">
  <?php print render($link); ?>
</span>
