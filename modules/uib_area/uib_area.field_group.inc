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
  $field_group->identifier = 'group_bottom_wrapper|node|area|default';
  $field_group->group_name = 'group_bottom_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom wrapper',
    'weight' => '7',
    'children' => array(
      0 => 'field_uib_bottom_media',
      1 => 'field_uib_bottom_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bottom wrapper',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bottom_wrapper|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_first|node|area|default';
  $field_group->group_name = 'group_column_first';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column first',
    'weight' => '11',
    'children' => array(
      0 => 'field_uib_link_section',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column first',
      'instance_settings' => array(
        'classes' => 'group-column-first field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_first|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_second|node|area|default';
  $field_group->group_name = 'group_column_second';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column second',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_profiled_testimonial',
      1 => 'field_uib_tertiary_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column second',
      'instance_settings' => array(
        'classes' => 'group-column-second field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_second|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_1|node|area|form';
  $field_group->group_name = 'group_level_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For level 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_sebra_id',
      1 => 'field_uib_area_parents',
      2 => 'field_uib_area_type',
      3 => 'field_uib_menu_style',
      4 => 'field_uib_w2_id',
      5 => 'field_uib_ou',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_level_1|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_management|node|area|form';
  $field_group->group_name = 'group_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Management',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_content_manager',
      1 => 'field_uib_logo',
      2 => 'field_uib_show_staff',
      3 => 'field_uib_staff',
      4 => 'field_uib_important_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_management|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_text|node|area|form';
  $field_group->group_name = 'group_profile_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'W2 profile text',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_text2',
      1 => 'field_uib_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_text|node|area|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_profiled_message',
      1 => 'group_column_second',
      2 => 'group_column_first',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'two_column',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_two_column|node|area|default'] = $field_group;

  return $export;
}
