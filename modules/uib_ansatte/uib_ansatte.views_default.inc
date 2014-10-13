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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
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
      'field' => 'field_uib_sort_name',
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
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'uib_research_fields' => 'uib_research_fields',
    'uib_nus' => 0,
    'uib_study_labels' => 0,
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: token picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['picture']['ui_name'] = 'token picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span><img src="/sites/all/themes/uib/uib_zen/images/person.png"></span>';
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_thumbnail';
  /* Field: token field_uib_first_name */
  $handler->display->display_options['fields']['field_uib_first_name']['id'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['field'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_first_name']['ui_name'] = 'token field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['exclude'] = TRUE;
  /* Field: token field_uib_last_name */
  $handler->display->display_options['fields']['field_uib_last_name']['id'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_last_name']['ui_name'] = 'token field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_last_name']['alter']['text'] = '[field_uib_last_name]</br>';
  /* Field: token field_uib_position */
  $handler->display->display_options['fields']['field_uib_position']['id'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['table'] = 'field_data_field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['field'] = 'field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_position']['ui_name'] = 'token field_uib_position';
  $handler->display->display_options['fields']['field_uib_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_position']['alter']['text'] = '<p class="user-info-item user-position">[field_uib_position]</p>';
  $handler->display->display_options['fields']['field_uib_position']['hide_empty'] = TRUE;
  /* Field: User: Position detail */
  $handler->display->display_options['fields']['field_uib_user_alt_position']['id'] = 'field_uib_user_alt_position';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['table'] = 'field_data_field_uib_user_alt_position';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['field'] = 'field_uib_user_alt_position';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['label'] = '';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_alt_position']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_alt_position']['alter']['text'] = ', [field_uib_user_alt_position-value]';
  $handler->display->display_options['fields']['field_uib_user_alt_position']['element_label_colon'] = FALSE;
  /* Field: token mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['mail']['ui_name'] = 'token mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<p class="user-info-item user-email">[mail]</p>';
  $handler->display->display_options['fields']['mail']['alter']['path'] = 'mailto:[mail]';
  /* Field: token field_uib_phone */
  $handler->display->display_options['fields']['field_uib_phone']['id'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['table'] = 'field_data_field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['field'] = 'field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_phone']['ui_name'] = 'token field_uib_phone';
  $handler->display->display_options['fields']['field_uib_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['alter']['text'] = '[field_uib_phone]';
  $handler->display->display_options['fields']['field_uib_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_uib_phone']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_phone']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uib_phone']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_uib_phone']['separator'] = '';
  /* Field: Linked user name (token) */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['view_user']['ui_name'] = 'Linked user name (token)';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_uib_first_name] [field_uib_last_name]';
  $handler->display->display_options['fields']['view_user']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: User: Organisational unit */
  $handler->display->display_options['fields']['field_uib_user_ou']['id'] = 'field_uib_user_ou';
  $handler->display->display_options['fields']['field_uib_user_ou']['table'] = 'field_data_field_uib_user_ou';
  $handler->display->display_options['fields']['field_uib_user_ou']['field'] = 'field_uib_user_ou';
  $handler->display->display_options['fields']['field_uib_user_ou']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_user_ou']['label'] = '';
  $handler->display->display_options['fields']['field_uib_user_ou']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_ou']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_user_ou']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: The generated HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'The generated HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media">
 [picture]
  <div class="info">
    <h2>[view_user]</h2>
    <p class="user-position">[field_uib_position][field_uib_user_alt_position]</p>
    <p class="user-ou">[field_uib_user_ou]</p>
    <p class="user-mail">[mail]</p>
    [field_uib_phone]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: First letter of sort name */
  $handler->display->display_options['fields']['field_uib_sort_name']['id'] = 'field_uib_sort_name';
  $handler->display->display_options['fields']['field_uib_sort_name']['table'] = 'field_data_field_uib_sort_name';
  $handler->display->display_options['fields']['field_uib_sort_name']['field'] = 'field_uib_sort_name';
  $handler->display->display_options['fields']['field_uib_sort_name']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_sort_name']['ui_name'] = 'First letter of sort name';
  $handler->display->display_options['fields']['field_uib_sort_name']['label'] = '';
  $handler->display->display_options['fields']['field_uib_sort_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_sort_name']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_uib_sort_name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_uib_sort_name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_uib_sort_name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_sort_name']['element_label_colon'] = FALSE;
  /* Field: token field_uib_user_competence */
  $handler->display->display_options['fields']['field_uib_user_competence']['id'] = 'field_uib_user_competence';
  $handler->display->display_options['fields']['field_uib_user_competence']['table'] = 'field_data_field_uib_user_competence';
  $handler->display->display_options['fields']['field_uib_user_competence']['field'] = 'field_uib_user_competence';
  $handler->display->display_options['fields']['field_uib_user_competence']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['field_uib_user_competence']['ui_name'] = 'token field_uib_user_competence';
  $handler->display->display_options['fields']['field_uib_user_competence']['label'] = '';
  $handler->display->display_options['fields']['field_uib_user_competence']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_competence']['alter']['text'] = '[field_uib_user_competence]';
  $handler->display->display_options['fields']['field_uib_user_competence']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_competence']['alter']['path'] = 'persons?field_uib_user_competence_tid=[field_uib_user_competence-tid]';
  $handler->display->display_options['fields']['field_uib_user_competence']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_uib_user_competence']['element_class'] = 'user-competence';
  $handler->display->display_options['fields']['field_uib_user_competence']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_user_competence']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_user_competence']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_uib_user_competence']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_uib_user_competence']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_user_competence']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uib_user_competence']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_uib_user_competence']['separator'] = ' | ';
  /* Sort criterion: User: Sort name (field_uib_sort_name) */
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['id'] = 'field_uib_sort_name_value';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['table'] = 'field_data_field_uib_sort_name';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['field'] = 'field_uib_sort_name_value';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['relationship'] = 'field_uib_staff_target_id';
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

  /* Display: List of all persons */
  $handler = $view->new_display('page', 'List of all persons', 'page_1');
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
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
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

  /* Display: List of staff for area */
  $handler = $view->new_display('page', 'List of staff for area', 'page_2');
  $handler->display->display_options['display_description'] = 'Lists the all staff belonging to an area.  By adding "faculity" or "staff" to the URL limit to that kind.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
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
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate_options']['code'] = 'if ($argument == \'faculty\') {
  $handler->validated_title = t(\'Faculty\');
}
elseif ($argument == \'staff\') {
  $handler->validated_title = t(\'Administrative staff\');
}
else {
  return FALSE;
}
return TRUE;
';
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
    t('term'),
    t('Uid'),
    t('<span><img src="/sites/all/themes/uib/uib_zen/images/person.png"></span>'),
    t('First name'),
    t('Last name'),
    t('[field_uib_last_name]</br>'),
    t('Position'),
    t('<p class="user-info-item user-position">[field_uib_position]</p>'),
    t(', [field_uib_user_alt_position-value]'),
    t('E-mail'),
    t('<p class="user-info-item user-email">[mail]</p>'),
    t('Phone'),
    t('[field_uib_phone]'),
    t('[field_uib_first_name] [field_uib_last_name]'),
    t('Term ID'),
    t('.'),
    t(','),
    t('<div class="media">
 [picture]
  <div class="info">
    <h2>[view_user]</h2>
    <p class="user-position">[field_uib_position][field_uib_user_alt_position]</p>
    <p class="user-ou">[field_uib_user_ou]</p>
    <p class="user-mail">[mail]</p>
    [field_uib_phone]
  </div>
</div>'),
    t('[field_uib_user_competence]'),
    t('All'),
    t('Staff at %1'),
    t('%2 at %1'),
    t('List of all persons'),
    t('All staff'),
    t('List of staff for area'),
    t('Lists the all staff belonging to an area.  By adding "faculity" or "staff" to the URL limit to that kind.'),
    t('All employees at %1'),
    t('%1'),
  );
  $export['ansatte'] = $view;

  return $export;
}
