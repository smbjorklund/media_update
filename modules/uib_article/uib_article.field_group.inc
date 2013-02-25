<?php
/**
 * @file
 * uib_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_article_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|uib_article|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_menu_title_w2',
      1 => 'field_uib_w2_id',
      2 => 'field_uib_w2_nav_parent_id',
      3 => 'field_uib_w2_path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 0,
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
  $export['group_advanced|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_factbox|node|uib_article|default';
  $field_group->group_name = 'group_article_factbox';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-factbox',
    'weight' => '7',
    'children' => array(),
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
  $export['group_article_factbox|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_main|node|uib_article|default';
  $field_group->group_name = 'group_article_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-main',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_byline',
      1 => 'field_uib_lead',
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
  $export['group_article_main|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_sidebar|node|uib_article|default';
  $field_group->group_name = 'group_article_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-sidebar',
    'weight' => '4',
    'children' => array(
      0 => 'field_uib_contacts',
      1 => 'field_uib_date',
      2 => 'field_uib_event_type',
      3 => 'field_uib_fact_box',
      4 => 'field_uib_files',
      5 => 'field_uib_links',
      6 => 'field_uib_location',
      7 => 'field_uib_media',
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
  $export['group_article_sidebar|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|uib_article|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_specific_field';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_details|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_factbox|node|uib_article|form';
  $field_group->group_name = 'group_factbox';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Fact box',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_fact_box',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Fact box',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_factbox|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|uib_article|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_byline',
      1 => 'field_uib_article_type',
      2 => 'field_uib_event_type',
      3 => 'field_uib_kicker',
      4 => 'field_uib_lead',
      5 => 'field_uib_text',
      6 => 'field_uib_area',
      7 => 'field_uib_main_media',
      8 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Information',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_information|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|uib_article|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '10',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_media|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|uib_article|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '0',
    'children' => array(
      0 => 'field_uib_links',
      1 => 'field_uib_files',
      2 => 'field_uib_media',
      3 => 'group_factbox',
      4 => 'group_uib_dato',
      5 => 'group_uib_geo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_sidebar|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specific_field|node|uib_article|form';
  $field_group->group_name = 'group_specific_field';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Specific fields based on type',
    'weight' => '6',
    'children' => array(
      0 => 'group_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Specific fields based on type',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_specific_field|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_dato|node|uib_article|form';
  $field_group->group_name = 'group_uib_dato';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '11',
    'children' => array(
      0 => 'field_uib_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Dates',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_uib_dato|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_geo|node|uib_article|form';
  $field_group->group_name = 'group_uib_geo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'GEO and addresses',
    'weight' => '16',
    'children' => array(
      0 => 'field_uib_location',
      1 => 'field_uib_contacts',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'GEO and addresses',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_uib_geo|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_links|node|uib_article|form';
  $field_group->group_name = 'group_uib_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_uib_links|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_media|node|uib_article|form';
  $field_group->group_name = 'group_uib_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media and attachments',
    'weight' => '7',
    'children' => array(),
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
  $export['group_uib_media|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_meta|node|uib_article|form';
  $field_group->group_name = 'group_uib_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'W2 and meta data',
    'weight' => '8',
    'children' => array(),
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
  $export['group_uib_meta|node|uib_article|form'] = $field_group;

  return $export;
}
