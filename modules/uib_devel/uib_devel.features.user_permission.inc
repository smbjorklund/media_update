<?php
/**
 * @file
 * uib_devel.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_devel_user_default_permissions() {
  $permissions = array();

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      0 => 'admin',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'devel',
  );

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: migration information.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'migrate_ui',
  );

  // Exported permission: switch users.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      0 => 'admin',
      1 => 'level 1',
    ),
    'module' => 'devel',
  );

  return $permissions;
}
