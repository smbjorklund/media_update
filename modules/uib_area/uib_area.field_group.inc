<?php
/**
 * @file
 * uib_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_area_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_two_column|node|area|default';
  $field_group->group_name = 'group_two_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'two_column',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_profiled_testimonial',
      1 => 'field_uib_tertiary_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_two_column|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_two_column|node|area|form';
  $field_group->group_name = 'group_two_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Two column',
    'weight' => '18',
    'children' => array(
      0 => 'field_uib_profiled_testimonial',
      1 => 'field_uib_secondary_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_two_column|node|area|form'] = $field_group;

  return $export;
}
