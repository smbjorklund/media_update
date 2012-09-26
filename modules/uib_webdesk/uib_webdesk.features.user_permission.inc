<?php
/**
 * @file
 * uib_webdesk.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_webdesk_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer shortcuts.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      0 => 'level 1',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: customize shortcut links.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      0 => 'level 1',
      1 => 'level 2',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: switch shortcut sets.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      0 => 'level 1',
    ),
    'module' => 'shortcut',
  );

  return $permissions;
}
