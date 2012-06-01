<?php
/**
 * @file
 * uib_feature_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_feature_area_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_contact|node|uib_ou|form';
  $field_group->group_name = 'group_uib_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_ou';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact info',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_fax',
      1 => 'field_uib_jobbnorge_id',
      2 => 'field_uib_mail_domain',
      3 => 'field_uib_phone',
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
  $export['group_uib_contact|node|uib_ou|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_geo|node|uib_ou|form';
  $field_group->group_name = 'group_uib_geo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_ou';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'GEO and addresses',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_geo',
      1 => 'field_uib_postal_address',
      2 => 'field_uib_visit_address',
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
  $export['group_uib_geo|node|uib_ou|form'] = $field_group;

  return $export;
}
