<?php
/**
 * @file
 * uib_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'user',
  );

  return $permissions;
}
