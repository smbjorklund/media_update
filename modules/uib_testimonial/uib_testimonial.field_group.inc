<?php
/**
 * @file
 * uib_testimonial.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_testimonial_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_main|node|uib_testimonial|default';
  $field_group->group_name = 'group_article_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-main',
    'weight' => '0',
    'children' => array(
      0 => 'field_uib_lead',
      1 => 'field_uib_quote',
      2 => 'field_uib_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'article-main',
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
  $export['group_article_main|node|uib_testimonial|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_sidebar|node|uib_testimonial|default';
  $field_group->group_name = 'group_article_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-sidebar',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_area',
      1 => 'field_uib_birth_year',
      2 => 'field_uib_education',
      3 => 'field_uib_exchange_place',
      4 => 'field_uib_exchange_text',
      5 => 'field_uib_media',
      6 => 'field_uib_name',
      7 => 'field_uib_organization',
      8 => 'field_uib_position',
      9 => 'field_uib_related_programmes',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'article-sidebar',
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
  $export['group_article_sidebar|node|uib_testimonial|default'] = $field_group;

  return $export;
}
