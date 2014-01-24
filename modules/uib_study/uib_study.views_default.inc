<?php
/**
 * @file
 * uib_study.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_study_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uib_study_specialization';
  $view->description = 'List all specializations that belong to a study';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Specializations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Specializations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  /* Contextual filter: Content: Part of study (field_uib_study_part_of) */
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['id'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['table'] = 'field_data_field_uib_study_part_of';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['field'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary_options']['items_per_page'] = '25';
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
    'uib_study' => 'uib_study',
  );
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'specialization' => 'specialization',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Specializations';
  $translatables['uib_study_specialization'] = array(
    t('Master'),
    t('Specializations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[path]">[field_uib_study_title]</a>'),
    t('Alle'),
    t('Block'),
  );
  $export['uib_study_specialization'] = $view;

  $view = new view();
  $view->name = 'uib_taxonomy_term';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'UiB Taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $translatables['uib_taxonomy_term'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('%1'),
    t('Page'),
    t('Feed'),
  );
  $export['uib_taxonomy_term'] = $view;

  return $export;
}
