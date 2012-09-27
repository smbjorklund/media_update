<?php
/**
 * @file
 * uib_webdesk.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_webdesk_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_content';
  $view->description = '';
  $view->tag = 'webdesk';
  $view->base_table = 'node';
  $view->human_name = 'My webdesk simple';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My content';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No content';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry sailor. Your search/site contain no content.';
  $handler->display->display_options['empty']['area']['format'] = 'html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['label'] = '';
  $handler->display->display_options['fields']['field_uib_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_area']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
    'uib_testimonial' => 'uib_testimonial',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: My simple content */
  $handler = $view->new_display('panel_pane', 'My simple content', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = 'webdesk/my';
  $translatables['my_content'] = array(
    t('Master'),
    t('My content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No content'),
    t('Sorry sailor. Your search/site contain no content.'),
    t('Content entity referenced from field_uib_area'),
    t('All'),
    t('My simple content'),
    t('View panes'),
  );
  $export['my_content'] = $view;

  $view = new view();
  $view->name = 'uib_webdesk';
  $view->description = '';
  $view->tag = 'webdesk';
  $view->base_table = 'node';
  $view->human_name = 'UIB webdesk';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'UIB webdesk';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No content';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry sailor. Your search/site contain no content.';
  $handler->display->display_options['empty']['area']['format'] = 'html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
    'uib_testimonial' => 'uib_testimonial',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['filters']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_event_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['operator_id'] = 'field_uib_event_type_value_op';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['label'] = 'Event type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['operator'] = 'field_uib_event_type_value_op';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['identifier'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
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
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_article_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['operator_id'] = 'field_uib_article_type_value_op';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['label'] = 'Article type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['operator'] = 'field_uib_article_type_value_op';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['identifier'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['description'] = ' Is greater than or equal to ';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '<=';
  $handler->display->display_options['filters']['changed']['group'] = 1;
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated date';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All content';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Content pane uid */
  $handler = $view->new_display('panel_pane', 'Content pane uid', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My content';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
    'uib_testimonial' => 'uib_testimonial',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['filters']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_event_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['operator_id'] = 'field_uib_event_type_value_op';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['label'] = 'Event type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['operator'] = 'field_uib_event_type_value_op';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['identifier'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
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
  $handler->display->display_options['filters']['field_uib_area_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_article_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['operator_id'] = 'field_uib_article_type_value_op';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['label'] = 'Article type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['operator'] = 'field_uib_article_type_value_op';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['identifier'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['description'] = ' Is greater than or equal to ';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '<=';
  $handler->display->display_options['filters']['changed']['group'] = 1;
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated date';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'token.current-user:uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['uib_webdesk'] = array(
    t('Master'),
    t('UIB webdesk'),
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
    t('No content'),
    t('Sorry sailor. Your search/site contain no content.'),
    t('Content entity referenced from field_uib_area'),
    t('Content'),
    t('Title'),
    t('Area'),
    t('Updated date'),
    t('All'),
    t('Published'),
    t('Author'),
    t('Event type'),
    t('Type'),
    t('Article type'),
    t('Post date'),
    t(' Is greater than or equal to '),
    t('Content pane'),
    t('All content'),
    t('View panes'),
    t('Content pane uid'),
    t('My content'),
  );
  $export['uib_webdesk'] = $view;

  $view = new view();
  $view->name = 'user_block';
  $view->description = 'Basic user account block. Used on main webdesk page.';
  $view->tag = 'webdesk, user';
  $view->base_table = 'users';
  $view->human_name = 'User Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = 'User image missing.';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_uib_first_name']['id'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['field'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_uib_first_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_uib_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_first_name']['element_wrapper_type'] = 'span';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name']['id'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_uib_last_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_uib_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_last_name']['element_wrapper_type'] = 'span';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Edit account';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]/edit';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $translatables['user_block'] = array(
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
    t('User image missing.'),
    t('Edit account'),
    t('All'),
  );
  $export['user_block'] = $view;

  return $export;
}
