<?php
/**
 * @file
 * uib_ansatte.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_ansatte_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'ansatte';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ansatte';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ansatte';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_uib_staff' => 'field_uib_staff',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_uib_staff' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Ansatte */
  $handler->display->display_options['fields']['field_uib_staff']['id'] = 'field_uib_staff';
  $handler->display->display_options['fields']['field_uib_staff']['table'] = 'field_data_field_uib_staff';
  $handler->display->display_options['fields']['field_uib_staff']['field'] = 'field_uib_staff';
  $handler->display->display_options['fields']['field_uib_staff']['label'] = '';
  $handler->display->display_options['fields']['field_uib_staff']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_staff']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_uib_staff']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_uib_staff']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uib_staff']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_uib_staff']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_uib_staff']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['nid']['title'] = 'Ansatte hos %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $base_url;
    $node = drupal_get_normal_path($argument, $language = NULL);

    if ($argument == $node) {
      dd (\'Node not found\');
    }

    if ($argument != $node) {
      dd (\'node: \' . $node);
      $nid = substr(strrchr($node, "/"), 1);
    }

    return TRUE;
  ';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_area_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['operator_id'] = 'field_uib_area_type_value_op';
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['operator'] = 'field_uib_area_type_value_op';
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['identifier'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'personer';
  $handler->display->display_options['menu']['title'] = 'fak';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['ansatte'] = array(
    t('Master'),
    t('Ansatte'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('Ansatte hos %1'),
    t('Type'),
    t('Page'),
  );
  $export['ansatte'] = $view;

  return $export;
}
