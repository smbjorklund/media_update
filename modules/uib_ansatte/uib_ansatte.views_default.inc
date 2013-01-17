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

  $view = new view();
  $view->name = 'ansatte';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Staff';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_last_name_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['id'] = 'field_uib_staff_target_id';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['table'] = 'field_data_field_uib_staff';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['field'] = 'field_uib_staff_target_id';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['hide_empty'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_uib_first_name']['id'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['field'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_first_name']['exclude'] = TRUE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name']['id'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['text'] = '[field_uib_last_name]</br>';
  /* Field: Field: Position */
  $handler->display->display_options['fields']['field_uib_position']['id'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['table'] = 'field_data_field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['field'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_position']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_position']['alter']['text'] = '[field_uib_position]</br>';
  $handler->display->display_options['fields']['field_uib_position']['hide_empty'] = TRUE;
  /* Field: User: Position (english) */
  $handler->display->display_options['fields']['field_uib_position_en']['id'] = 'field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['table'] = 'field_data_field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['field'] = 'field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_position_en']['exclude'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_uib_phone']['id'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['table'] = 'field_data_field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['field'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['alter']['text'] = '[field_uib_phone]<br>';
  $handler->display->display_options['fields']['field_uib_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['delta_offset'] = '0';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name_1']['id'] = 'field_uib_last_name_1';
  $handler->display->display_options['fields']['field_uib_last_name_1']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name_1']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name_1']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_last_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_last_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media">
 [picture]
  <div class="info">
    <h2>[field_uib_first_name] [field_uib_last_name]</h2>
    [field_uib_position]
    [field_uib_phone]
    [mail]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: User: Last name (field_uib_last_name) */
  $handler->display->display_options['sorts']['field_uib_last_name_value']['id'] = 'field_uib_last_name_value';
  $handler->display->display_options['sorts']['field_uib_last_name_value']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['sorts']['field_uib_last_name_value']['field'] = 'field_uib_last_name_value';
  $handler->display->display_options['sorts']['field_uib_last_name_value']['relationship'] = 'field_uib_staff_target_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $base_url;
    $node = drupal_get_normal_path($argument, $language = NULL);

    if ($argument == $node) {
      uibx_log(\'Node not found\');
    }

    if ($argument != $node) {
      uibx_log(\'node: \' . $node);
      $nid = substr(strrchr($node, "/"), 1);
    }

    return TRUE;
  ';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  /* Filter criterion: User: First name (field_uib_first_name) */
  $handler->display->display_options['filters']['field_uib_first_name_value']['id'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['filters']['field_uib_first_name_value']['field'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['filters']['field_uib_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['operator_id'] = 'field_uib_first_name_value_op';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['operator'] = 'field_uib_first_name_value_op';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['identifier'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: User: Last name (field_uib_last_name) */
  $handler->display->display_options['filters']['field_uib_last_name_value']['id'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['filters']['field_uib_last_name_value']['field'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['filters']['field_uib_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['operator_id'] = 'field_uib_last_name_value_op';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['operator'] = 'field_uib_last_name_value_op';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['identifier'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $base_url;
    $node = drupal_get_normal_path($argument, $language = NULL);

    if ($argument == $node) {
      uibx_log(\'Node not found\');
    }

    if ($argument != $node) {
      uibx_log(\'node: \' . $node);
      $nid = substr(strrchr($node, "/"), 1);
    }

    return TRUE;
  ';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title'] = 'All staff';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'persons';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'area';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: node page */
  $handler = $view->new_display('page', 'node page', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="user-picture"><img src="/sites/all/themes/uib/uib_zen/images/person.png"></span>';
  $handler->display->display_options['fields']['picture']['hide_empty'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_uib_first_name']['id'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['field'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_first_name']['exclude'] = TRUE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name']['id'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['text'] = '[field_uib_last_name]</br>';
  /* Field: Field: Position */
  $handler->display->display_options['fields']['field_uib_position']['id'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['table'] = 'field_data_field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['field'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_position']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_position']['alter']['text'] = '[field_uib_position]</br>';
  $handler->display->display_options['fields']['field_uib_position']['hide_empty'] = TRUE;
  /* Field: User: Position (english) */
  $handler->display->display_options['fields']['field_uib_position_en']['id'] = 'field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['table'] = 'field_data_field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['field'] = 'field_uib_position_en';
  $handler->display->display_options['fields']['field_uib_position_en']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_position_en']['exclude'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_uib_phone']['id'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['table'] = 'field_data_field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['field'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['alter']['text'] = '[field_uib_phone]<br>';
  $handler->display->display_options['fields']['field_uib_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['delta_offset'] = '0';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name_1']['id'] = 'field_uib_last_name_1';
  $handler->display->display_options['fields']['field_uib_last_name_1']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name_1']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name_1']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_last_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_last_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media">
 [picture]
  <div class="info">
    <h2>[field_uib_first_name] [field_uib_last_name]</h2>
    [field_uib_position]
    [field_uib_phone]
    [mail]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $base_url;
    $node = drupal_get_normal_path($argument, $language = NULL);

    if ($argument == $node) {
      uibx_log(\'Node not found\');
    }

    if ($argument != $node) {
      uibx_log(\'node: \' . $node);
      $nid = substr(strrchr($node, "/"), 1);
    }

    return TRUE;
  ';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title'] = 'All employees at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'node/%/persons';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'area';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['ansatte'] = array(
    t('Master'),
    t('Staff'),
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
    t('User entity referenced from field_uib_staff'),
    t('First name'),
    t('Last name'),
    t('[field_uib_last_name]</br>'),
    t('Position'),
    t('[field_uib_position]</br>'),
    t('Position (english)'),
    t('E-mail'),
    t('Phone'),
    t('[field_uib_phone]<br>'),
    t('<div class="media">
 [picture]
  <div class="info">
    <h2>[field_uib_first_name] [field_uib_last_name]</h2>
    [field_uib_position]
    [field_uib_phone]
    [mail]
  </div>
</div>'),
    t('All'),
    t('Staff at %1'),
    t('%2 at %1'),
    t('Page'),
    t('All staff'),
    t('node page'),
    t('<span class="user-picture"><img src="/sites/all/themes/uib/uib_zen/images/person.png"></span>'),
    t('All employees at %1'),
    t('%1'),
  );
  $export['ansatte'] = $view;

  return $export;
}
