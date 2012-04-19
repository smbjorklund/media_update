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

  $view = new view;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_area']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_area']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_area']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_area']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_area']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_area']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_uib_article_type']['id'] = 'field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['field'] = 'field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_uib_article_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_uib_article_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_uib_article_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_uib_article_type']['field_api_classes'] = 0;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Author';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
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
  $handler->display->display_options['fields']['field_uib_w2_id']['alter']['alt'] = '[field_uib_w2_id]';
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
  /* Field: Content translation: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Lang';
  $handler->display->display_options['fields']['language']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['language']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['language']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['language']['alter']['external'] = 0;
  $handler->display->display_options['fields']['language']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['language']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['language']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['language']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['language']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['language']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['language']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['language']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['language']['alter']['html'] = 0;
  $handler->display->display_options['fields']['language']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['language']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['language']['hide_empty'] = 0;
  $handler->display->display_options['fields']['language']['empty_zero'] = 0;
  $handler->display->display_options['fields']['language']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['language']['link_to_node'] = 0;
  $handler->display->display_options['fields']['language']['native_language'] = 0;
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
    t('Area'),
    t('Type'),
    t('Author'),
    t('Date'),
    t('w2'),
    t('xtopic'),
    t('http://testbool.uib.no/topicmap/@@xtopic?id=[field_uib_w2_id]'),
    t('[field_uib_w2_id]'),
    t('Lang'),
    t('Page'),
  );
  $export['uib_articles'] = $view;

  return $export;
}
