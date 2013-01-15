<?php
/**
 * @file
 * uib_area.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_area_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'area_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Area map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Area map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['id'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['field'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
[field_uib_visit_address]
';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_uib_geo']['id'] = 'field_uib_geo';
  $handler->display->display_options['fields']['field_uib_geo']['table'] = 'field_data_field_uib_geo';
  $handler->display->display_options['fields']['field_uib_geo']['field'] = 'field_uib_geo';
  $handler->display->display_options['fields']['field_uib_geo']['empty'] = 'No coordinates';
  $handler->display->display_options['fields']['field_uib_geo']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_uib_geo']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['field_uib_geo']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_zoom' => '8',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'standard',
    'geofield_map_pancontrol' => 1,
    'geofield_map_maptype' => 'map',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 0,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 0,
    'geofield_map_draggable' => 0,
    'geofield_map_streetview_show' => 0,
  );
  /* Field: Content: Visit Address */
  $handler->display->display_options['fields']['field_uib_visit_address']['id'] = 'field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['table'] = 'field_data_field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['field'] = 'field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_uib_visit_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
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
    'uib_ou' => 'uib_ou',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/map';
  $translatables['area_map'] = array(
    t('Master'),
    t('Area map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_uib_ou'),
    t('Title'),
    t('[title]
[field_uib_visit_address]
'),
    t('Location'),
    t('No coordinates'),
    t('Visit Address'),
    t('All'),
    t('Page'),
  );
  $export['area_map'] = $view;

  $view = new view();
  $view->name = 'area_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Area slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Area slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_uib_lead' => 0,
    'field_uib_main_media' => 0,
    'title' => 0,
    'field_uib_main_media_1' => 0,
    'nid' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'nid' => 'nid',
    'field_uib_lead' => 0,
    'field_uib_main_media' => 0,
    'title' => 0,
    'field_uib_main_media_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['id'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['field'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['required'] = TRUE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'full_width_image',
  );
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media_1']['id'] = 'field_uib_main_media_1';
  $handler->display->display_options['fields']['field_uib_main_media_1']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media_1']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_main_media_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media_1']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<span class="ciclepager"></span>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_uib_location']['id'] = 'field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['table'] = 'field_data_field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['field'] = 'field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['exclude'] = TRUE;
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div id="transparent"></div>
<div id="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
<div class="eventdata">
<p>[field_uib_event_type]</p>
<p>[field_uib_date]</p>
<p>[field_uib_location]</p>
</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Main media (field_uib_main_media:fid) */
  $handler->display->display_options['filters']['field_uib_main_media_fid']['id'] = 'field_uib_main_media_fid';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['field'] = 'field_uib_main_media_fid';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['operator'] = 'not empty';

  /* Display: Area slideshow block */
  $handler = $view->new_display('block', 'Area slideshow block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['area_slideshow'] = array(
    t('Master'),
    t('Area slideshow'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_uib_profiled_article'),
    t('<span class="ciclepager"></span>'),
    t('Location'),
    t('<div id="transparent"></div>
<div id="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
<div class="eventdata">
<p>[field_uib_event_type]</p>
<p>[field_uib_date]</p>
<p>[field_uib_location]</p>
</div>
</div>'),
    t('All'),
    t('Area slideshow block'),
  );
  $export['area_slideshow'] = $view;

  $view = new view();
  $view->name = 'areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['field_language'] = 'und';
  $handler->display->display_options['path'] = 'areas';
  $translatables['areas'] = array(
    t('Master'),
    t('Areas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['areas'] = $view;

  $view = new view();
  $view->name = 'courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Responsible (field_uib_ou) */
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['id'] = 'field_uib_ou_target_id';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['table'] = 'field_data_field_uib_ou';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['field'] = 'field_uib_ou_target_id';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['default_argument_options']['code'] = 'return uib_area__get_ou_nid();';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['validate_options']['code'] = '$handler->argument = uib_area__get_ou_nid();
return TRUE;';
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Courses */
  $handler = $view->new_display('page', 'Courses', 'courses');
  $handler->display->display_options['display_description'] = 'Listing courses belonging to area';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/courses';

  /* Display: Studyprogrammes */
  $handler = $view->new_display('page', 'Studyprogrammes', 'study_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Study programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/study-programmes';

  /* Display: Masterprogrammes */
  $handler = $view->new_display('page', 'Masterprogrammes', 'master_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'MA';
  $handler->display->display_options['path'] = 'node/%/master-programmes';

  /* Display: Bachelorprogrammes */
  $handler = $view->new_display('page', 'Bachelorprogrammes', 'bachelor_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bachelor programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'BA';
  $handler->display->display_options['path'] = 'node/%/bachelor-programmes';

  /* Display: One-year programmes */
  $handler = $view->new_display('page', 'One-year programmes', 'one_year_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'One-year programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'Å';
  $handler->display->display_options['path'] = 'node/%/one-year-programmes';
  $translatables['courses'] = array(
    t('Master'),
    t('Courses'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Listing courses belonging to area'),
    t('Studyprogrammes'),
    t('Study programmes'),
    t('Masterprogrammes'),
    t('Master programmes'),
    t('Bachelorprogrammes'),
    t('Bachelor programmes'),
    t('One-year programmes'),
  );
  $export['courses'] = $view;

  $view = new view();
  $view->name = 'faculties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faculties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'faculty' => 'faculty',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'faculties';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Faculties';
  $translatables['faculties'] = array(
    t('Master'),
    t('Faculties'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Block'),
  );
  $export['faculties'] = $view;

  $view = new view();
  $view->name = 'faculty_departments_kids';
  $view->description = 'This view is for facultys, and its lists all insitutes kids';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faculty departments kids';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Departments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_area_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_uib_area_type']['id'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['field'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_area_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_area_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['id'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['field'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
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
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'institute' => 'institute',
  );

  /* Display: Faculty deparments kids */
  $handler = $view->new_display('block', 'Faculty deparments kids', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['faculty_departments_kids'] = array(
    t('Master'),
    t('Departments'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Faculty deparments kids'),
  );
  $export['faculty_departments_kids'] = $view;

  $view = new view();
  $view->name = 'newslist';
  $view->description = 'A view that is used by the newslist field on areas';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Newslist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['label'] = '';
  $handler->display->display_options['fields']['field_uib_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_area']['settings'] = array(
    'link' => 0,
  );
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

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_uib_area' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['newslist'] = array(
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
    t('Entity Reference'),
  );
  $export['newslist'] = $view;

  $view = new view();
  $view->name = 'recent_news';
  $view->description = 'List the 5 most recent news';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent news';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'news' => 'news',
  );

  /* Display: Area recent news block */
  $handler = $view->new_display('block', 'Area recent news block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'News archive';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';

  /* Display: News archive */
  $handler = $view->new_display('page', 'News archive', 'newsarchive');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News archive';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'created',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'medium';
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([created_1])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['alter']['text'] = '<div class="recent-news-wrapper">
[field_uib_main_media]
[title]
[field_uib_lead]
</div>';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/news-archive';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['path'] = 'node/%/rss.xml';

  /* Display: Date and year selector */
  $handler = $view->new_display('block', 'Date and year selector', 'block_date_selector');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Select news by month and year';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['base_path'] = 'node/%/news-archive';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  $translatables['recent_news'] = array(
    t('Master'),
    t('Recent news'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Area recent news block'),
    t('News archive'),
    t('Post date'),
    t('[title] ([created_1])'),
    t('<div class="recent-news-wrapper">
[field_uib_main_media]
[title]
[field_uib_lead]
</div>'),
    t('Feed'),
    t('Date and year selector'),
    t('Select news by month and year'),
  );
  $export['recent_news'] = $view;

  return $export;
}
