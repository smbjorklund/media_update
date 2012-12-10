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
  $field_group->identifier = 'group_bottom_section|node|area|form';
  $field_group->group_name = 'group_bottom_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom section',
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_bottom_media',
      1 => 'field_uib_bottom_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bottom_section|node|area|form'] = $field_group;

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
      0 => 'field_uib_area_parents',
      1 => 'field_uib_area_type',
      2 => 'field_uib_ou',
      3 => 'field_uib_sebra_id',
      4 => 'field_uib_w2_id',
      5 => 'title',
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
      2 => 'field_uib_menu_style',
      3 => 'field_uib_show_staff',
      4 => 'field_uib_staff',
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
  $field_group->identifier = 'group_middle_section|node|area|form';
  $field_group->group_name = 'group_middle_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Middle section',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_link_section',
      1 => 'field_uib_profiled_testimonial',
      2 => 'field_uib_tertiary_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_middle_section|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|area|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '7',
    'children' => array(
      0 => 'field_uib_feed',
      1 => 'field_uib_profiled_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_other|node|area|form'] = $field_group;

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
      0 => 'field_uib_media',
      1 => 'field_uib_text2',
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
  $field_group->identifier = 'group_top_section|node|area|form';
  $field_group->group_name = 'group_top_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top section',
    'weight' => '4',
    'children' => array(
      0 => 'field_uib_primary_media',
      1 => 'field_uib_primary_text',
      2 => 'field_uib_profiled_article',
      3 => 'field_uib_secondary_text',
      4 => 'field_uib_social_media',
      5 => 'field_uib_important_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_top_section|node|area|form'] = $field_group;

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
      0 => 'field_uib_link_section',
      1 => 'field_uib_profiled_testimonial',
      2 => 'field_uib_tertiary_text',
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
    'weight' => '19',
    'children' => array(),
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
