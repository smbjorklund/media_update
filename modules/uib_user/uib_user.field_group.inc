<?php
/**
 * @file
 * uib_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_user_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_element|user|user|default';
  $field_group->group_name = 'group_media_element';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_first';
  $field_group->data = array(
    'label' => 'Media element',
    'weight' => '38',
    'children' => array(
      0 => 'group_user_media',
      1 => 'group_user_contact_wrapper',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media element',
      'instance_settings' => array(
        'classes' => 'group-media-element field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_media_element|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary|user|user|form';
  $field_group->group_name = 'group_primary';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main information',
    'weight' => '0',
    'children' => array(
      0 => 'field_uib_phone',
      1 => 'field_uib_user_alt_lastname',
      2 => 'field_uib_user_alt_position',
      3 => 'field_uib_user_communication',
      4 => 'field_uib_user_cv',
      5 => 'field_uib_user_publications',
      6 => 'field_uib_user_teaching',
      7 => 'field_uib_user_url',
      8 => 'field_uib_user_vcard',
      9 => 'field_uib_last_name',
      10 => 'field_uib_user_field',
      11 => 'field_uib_user_opt_title',
      12 => 'field_uib_user_room',
      13 => 'field_uib_user_social_media',
      14 => 'field_uib_first_name',
      15 => 'field_uib_user_alt_address',
      16 => 'field_uib_user_alt_firstname',
      17 => 'field_uib_position',
      18 => 'field_uib_user_opt_content',
      19 => 'picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
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
  $export['group_primary|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary|user|user|form';
  $field_group->group_name = 'group_secondary';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Secondary information',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_user_competence',
      1 => 'field_uib_user_projects',
      2 => 'field_uib_user_docs',
      3 => 'field_uib_user_feed',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Secondary information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
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
  $export['group_secondary|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_hidden|user|user|form';
  $field_group->group_name = 'group_uib_hidden';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden',
    'weight' => '33',
    'children' => array(
      0 => 'field_uib_position_category',
      1 => 'field_uib_w2_id',
      2 => 'field_uib_position_code',
      3 => 'field_uib_slug',
      4 => 'field_uib_user_domain',
      5 => 'field_uib_sort_name',
      6 => 'googleanalytics',
      7 => 'redirect',
      8 => 'account',
      9 => 'timezone',
      10 => 'locale',
      11 => 'wysiwyg',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hidden',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_uib_hidden|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact_wrapper|user|user|default';
  $field_group->group_name = 'group_user_contact_wrapper';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_media_element';
  $field_group->data = array(
    'label' => 'Contact wrapper',
    'weight' => '40',
    'children' => array(
      0 => 'group_user_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact wrapper',
      'instance_settings' => array(
        'classes' => 'group-user-contact-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_contact_wrapper|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact|user|user|default';
  $field_group->group_name = 'group_user_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_contact_wrapper';
  $field_group->data = array(
    'label' => 'Contact info',
    'weight' => '41',
    'children' => array(
      0 => 'field_uib_first_name',
      1 => 'field_uib_last_name',
      2 => 'field_uib_phone',
      3 => 'field_uib_position',
      4 => 'field_uib_user_cv',
      5 => 'field_uib_user_alt_address',
      6 => 'field_uib_user_alt_firstname',
      7 => 'field_uib_user_alt_lastname',
      8 => 'field_uib_user_alt_position',
      9 => 'field_uib_user_url',
      10 => 'field_uib_user_vcard',
      11 => 'field_uib_user_room',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact info',
      'instance_settings' => array(
        'classes' => 'group-user-contact field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_contact|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_first|user|user|default';
  $field_group->group_name = 'group_user_first';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First',
    'weight' => '0',
    'children' => array(
      0 => 'group_media_element',
      1 => 'group_user_work_1',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'First',
      'instance_settings' => array(
        'classes' => 'group-user-first field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_first|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_media|user|user|default';
  $field_group->group_name = 'group_user_media';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_media_element';
  $field_group->data = array(
    'label' => 'Personal media',
    'weight' => '39',
    'children' => array(
      0 => 'field_uib_user_social_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal media',
      'instance_settings' => array(
        'classes' => 'group-user-media field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_media|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_second|user|user|default';
  $field_group->group_name = 'group_user_second';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_user_competence',
      1 => 'field_uib_user_projects',
      2 => 'field_uib_user_docs',
      3 => 'field_uib_user_feed',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Second',
      'instance_settings' => array(
        'classes' => 'group-user-second field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_second|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_work_1|user|user|default';
  $field_group->group_name = 'group_user_work_1';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_first';
  $field_group->data = array(
    'label' => 'Work information',
    'weight' => '41',
    'children' => array(
      0 => 'field_uib_user_communication',
      1 => 'field_uib_user_field',
      2 => 'field_uib_user_opt_title',
      3 => 'field_uib_user_publications',
      4 => 'field_uib_user_teaching',
      5 => 'field_uib_user_opt_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Work information',
      'instance_settings' => array(
        'classes' => 'group-user-work-1 field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_work_1|user|user|default'] = $field_group;

  return $export;
}
