<?php
/**
 * @file
 * uib_feature_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_feature_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'anonymous user',
    ),
    'module' => 'user',
  );

  return $permissions;
}
