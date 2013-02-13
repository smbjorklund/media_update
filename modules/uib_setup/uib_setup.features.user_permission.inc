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

  // Exported permission: administer entity translation.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: toggle field translatability.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate any entity.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate file entities.
  $permissions['translate file entities'] = array(
    'name' => 'translate file entities',
    'roles' => array(
      0 => 'admin',
      1 => 'level 1',
      2 => 'level 2',
      3 => 'level 3',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: use bigmenu.
  $permissions['use bigmenu'] = array(
    'name' => 'use bigmenu',
    'roles' => array(
      0 => 'admin',
      1 => 'level 1',
      2 => 'level 2',
      3 => 'level 3',
    ),
    'module' => 'bigmenu',
  );

  return $permissions;
}
