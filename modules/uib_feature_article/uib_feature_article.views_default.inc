<?php
/**
 * @file
 * uib_feature_article.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_feature_article_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uib_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_uib_area' => 'field_uib_area',
    'created' => 'created',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uib_area' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_uib_article_type']['id'] = 'field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['field'] = 'field_uib_article_type';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Author';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Field: ID w2 */
  $handler->display->display_options['fields']['field_uib_w2_id']['id'] = 'field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['table'] = 'field_data_field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['field'] = 'field_uib_w2_id';
  $handler->display->display_options['fields']['field_uib_w2_id']['label'] = 'w2';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['text'] = 'xtopic';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['path'] = 'http://testbool.uib.no/topicmap/@@xtopic?id=[field_uib_w2_id]';
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['alt'] = '[field_uib_w2_id]';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Lang';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'uib_article' => 'uib_article',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'a';
  $translatables['uib_articles'] = array(
    t('Master'),
    t('Articles'),
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
    t('Area'),
    t('Type'),
    t('Author'),
    t('Date'),
    t('w2'),
    t('xtopic'),
    t('[field_uib_w2_id]'),
    t('Lang'),
    t('Page'),
  );
  $export['uib_articles'] = $view;

  return $export;
}
