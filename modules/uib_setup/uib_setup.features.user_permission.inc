<?php
/**
 * @file
 * uib_setup.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_setup_user_default_permissions() {
  $permissions = array();

  // Exported permission: use bigmenu.
  $permissions['use bigmenu'] = array(
    'name' => 'use bigmenu',
    'roles' => array(
      0 => 'level 1',
      1 => 'level 2',
      2 => 'level 3',
    ),
    'module' => 'bigmenu',
  );

  return $permissions;
}
