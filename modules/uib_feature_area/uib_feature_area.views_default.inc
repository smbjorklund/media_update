<?php
/**
 * @file
 * uib_feature_area.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_feature_area_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'area_kids';
  $view->description = 'List all sub-areas';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'area_kids';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kids';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Contextual filter: Taxonomy term: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['id'] = 'field_uib_area_parents_tid';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['field'] = 'field_uib_area_parents_tid';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_uib_area_parents_tid']['not'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'area' => 'area',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'Area kids';
  $translatables['area_kids'] = array(
    t('Master'),
    t('Kids'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
    t('Area kids'),
  );
  $export['area_kids'] = $view;

  $view = new view;
  $view->name = 'uib_areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Areas';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Parents */
  $handler->display->display_options['fields']['field_uib_area_parents']['id'] = 'field_uib_area_parents';
  $handler->display->display_options['fields']['field_uib_area_parents']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['fields']['field_uib_area_parents']['field'] = 'field_uib_area_parents';
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_uib_area_parents']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uib_area_parents']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_uib_area_parents']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Place */
  $handler->display->display_options['fields']['field_uib_ou']['id'] = 'field_uib_ou';
  $handler->display->display_options['fields']['field_uib_ou']['table'] = 'field_data_field_uib_ou';
  $handler->display->display_options['fields']['field_uib_ou']['field'] = 'field_uib_ou';
  $handler->display->display_options['fields']['field_uib_ou']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_ou']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_ou']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_ou']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_ou']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_uib_ou']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Sebra ID */
  $handler->display->display_options['fields']['field_uib_sebra_id']['id'] = 'field_uib_sebra_id';
  $handler->display->display_options['fields']['field_uib_sebra_id']['table'] = 'field_data_field_uib_sebra_id';
  $handler->display->display_options['fields']['field_uib_sebra_id']['field'] = 'field_uib_sebra_id';
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_sebra_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_sebra_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_sebra_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_sebra_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_uib_sebra_id']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_uib_area_type']['id'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['field'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_area_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_area_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_area_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_area_type']['field_api_classes'] = 0;
  /* Field: Field: ID w2 */
  $handler->display->display_options['fields']['field_uib_w2_id']['id'] = 'field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['table'] = 'field_data_field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['field'] = 'field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['label'] = 'w2';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['text'] = 'xtopic';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['path'] = 'http://testbool.uib.no/topicmap/@@xtopic?id=[field_uib_w2_id]';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_w2_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_w2_id']['field_api_classes'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'area' => 'area',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'areas';
  $translatables['uib_areas'] = array(
    t('Master'),
    t('Areas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Parents'),
    t('Place'),
    t('Sebra ID'),
    t('Type'),
    t('w2'),
    t('xtopic'),
    t('http://testbool.uib.no/topicmap/@@xtopic?id=[field_uib_w2_id]'),
    t('Page'),
  );
  $export['uib_areas'] = $view;

  return $export;
}
