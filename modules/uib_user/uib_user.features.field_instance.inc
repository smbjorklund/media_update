<?php
/**
 * @file
 * uib_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function uib_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_uib_first_name'
  $field_instances['user-user-field_uib_first_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_first_name',
    'label' => 'First name',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -9,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_last_name'
  $field_instances['user-user-field_uib_last_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_last_name',
    'label' => 'Last name',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -6,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_phone'
  $field_instances['user-user-field_uib_phone'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'phone',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'phone',
        'weight' => 31,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_phone',
    'label' => 'Phone',
    'required' => 0,
    'settings' => array(
      'ca_phone_parentheses' => 1,
      'ca_phone_separator' => '-',
      'entity_translation_sync' => FALSE,
      'phone_country_code' => 0,
      'phone_default_country_code' => 47,
      'phone_int_max_length' => 15,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'phone',
      'settings' => array(),
      'type' => 'phone_textfield',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_position'
  $field_instances['user-user-field_uib_position'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_position',
    'label' => 'Position',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_position_category'
  $field_instances['user-user-field_uib_position_category'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 'faculty',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_position_category',
    'label' => 'Position category',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => -8,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_position_code'
  $field_instances['user-user-field_uib_position_code'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_position_code',
    'label' => 'Position code',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => -7,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_slug'
  $field_instances['user-user-field_uib_slug'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_slug',
    'label' => 'Slug',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_sort_name'
  $field_instances['user-user-field_uib_sort_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_sort_name',
    'label' => 'Sort name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -9,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_alt_address'
  $field_instances['user-user-field_uib_user_alt_address'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'element_key' => 'user|user|field_uib_user_alt_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'postal_code' => '',
        'locality' => '',
        'country' => 'NO',
      ),
    ),
    'deleted' => 0,
    'description' => 'A visiting address other than the address of your institution. This will override the institution address on your profile.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_alt_address',
    'label' => 'Visiting address override',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_alt_firstname'
  $field_instances['user-user-field_uib_user_alt_firstname'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you want a first name displayed on your user page - different from your name in SEBRA, put it here. This will override the first name(s) from SEBRA.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_alt_firstname',
    'label' => 'First name override',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -8,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_alt_lastname'
  $field_instances['user-user-field_uib_user_alt_lastname'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you want a last name displayed on your user page - different from your name in SEBRA, put it here. This will override the last name(s) from SEBRA.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_alt_lastname',
    'label' => 'Last name override',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_alt_position'
  $field_instances['user-user-field_uib_user_alt_position'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a more specific title (position) here, if you consider the one from SEBRA to be too general.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_alt_position',
    'label' => 'Position detail',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_communication'
  $field_instances['user-user-field_uib_user_communication'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_communication',
    'label' => 'Communication',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_competence'
  $field_instances['user-user-field_uib_user_competence'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 8,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_competence',
    'label' => 'Fields of competence',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_cv'
  $field_instances['user-user-field_uib_user_cv'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => 'Upload a Curriculum Vitae document to be available for download from your user profile.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'file_default',
        'weight' => 38,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_cv',
    'label' => 'CV',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'txt pdf doc docx odt fodt',
      'max_filesize' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_docs'
  $field_instances['user-user-field_uib_user_docs'] = array(
    'bundle' => 'user',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'file_default',
        'weight' => 11,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_docs',
    'label' => 'Relevant documents',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt pdf doc docx odt fodt',
      'max_filesize' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 'document',
          'image' => 0,
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_domain'
  $field_instances['user-user-field_uib_user_domain'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 'local',
      ),
    ),
    'deleted' => 0,
    'description' => 'The domain this username is allocated from.  Currently we just assume that the domains we operate with do not overlap.

The domain \'local\' is for local users.  The domain \'uib\' is for used for usernames allocated by Sebra. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_domain',
    'label' => 'User Domain',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_feed'
  $field_instances['user-user-field_uib_user_feed'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'link_default',
        'weight' => 14,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_feed',
    'label' => 'RSS feed',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => 0,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_field'
  $field_instances['user-user-field_uib_user_field'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_field',
    'label' => 'Research / work',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 0,
          'plain_text' => 'plain_text',
          'restricted_html' => 0,
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_opt_content'
  $field_instances['user-user-field_uib_user_opt_content'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 30,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_opt_content',
    'label' => 'Optional tab content',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_opt_title'
  $field_instances['user-user-field_uib_user_opt_title'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Title for the optional tab',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 29,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_opt_title',
    'label' => 'Title for optional tab',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_ou'
  $field_instances['user-user-field_uib_user_ou'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'links' => 0,
          'view_mode' => 'short_teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 30,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_ou',
    'label' => 'Organisational unit',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_projects'
  $field_instances['user-user-field_uib_user_projects'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_projects',
    'label' => 'Current projects',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_publications'
  $field_instances['user-user-field_uib_user_publications'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Publications additional to what wil be merged from CRISTIN. These will appear below CRISTIN publications.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_publications',
    'label' => 'Publications',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_room'
  $field_instances['user-user-field_uib_user_room'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your room number',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_room',
    'label' => 'Room',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_social_media'
  $field_instances['user-user-field_uib_user_social_media'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add ids for the social media links that are desired.  Use strings like twitter:uib, youtube:unibergen, facebook:universitetetibergen, vimeo:uib and flickr:unibergen. Replace "uib" with the desired account. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'uib_field',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'socialmedia_formatter',
        'weight' => 32,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_social_media',
    'label' => 'Follow me',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
            'restricted_html' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_teaching'
  $field_instances['user-user-field_uib_user_teaching'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_teaching',
    'label' => 'Teaching',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'restricted_html' => 'restricted_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -48,
            ),
            'full_html' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -49,
            ),
            'restricted_html' => array(
              'weight' => -50,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_user_url'
  $field_instances['user-user-field_uib_user_url'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your homepage link',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'link_separate',
        'weight' => 33,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_user_url',
    'label' => 'Url',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => 0,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_uib_w2_id'
  $field_instances['user-user-field_uib_w2_id'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'uib_user_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_uib_w2_id',
    'label' => 'ID w2',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -6,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A visiting address other than the address of your institution. This will override the institution address on your profile.');
  t('Add a more specific title (position) here, if you consider the one from SEBRA to be too general.');
  t('Add ids for the social media links that are desired.  Use strings like twitter:uib, youtube:unibergen, facebook:universitetetibergen, vimeo:uib and flickr:unibergen. Replace "uib" with the desired account. ');
  t('CV');
  t('Communication');
  t('Current projects');
  t('Fields of competence');
  t('First name');
  t('First name override');
  t('Follow me');
  t('ID w2');
  t('If you want a first name displayed on your user page - different from your name in SEBRA, put it here. This will override the first name(s) from SEBRA.');
  t('If you want a last name displayed on your user page - different from your name in SEBRA, put it here. This will override the last name(s) from SEBRA.');
  t('Last name');
  t('Last name override');
  t('Optional tab content');
  t('Organisational unit');
  t('Phone');
  t('Position');
  t('Position category');
  t('Position code');
  t('Position detail');
  t('Publications');
  t('Publications additional to what wil be merged from CRISTIN. These will appear below CRISTIN publications.');
  t('RSS feed');
  t('Relevant documents');
  t('Research / work');
  t('Room');
  t('Slug');
  t('Sort name');
  t('Teaching');
  t('The domain this username is allocated from.  Currently we just assume that the domains we operate with do not overlap.

The domain \'local\' is for local users.  The domain \'uib\' is for used for usernames allocated by Sebra. ');
  t('Title for optional tab');
  t('Title for the optional tab');
  t('Upload a Curriculum Vitae document to be available for download from your user profile.');
  t('Url');
  t('User Domain');
  t('Visiting address override');
  t('Your homepage link');
  t('Your room number');

  return $field_instances;
}
