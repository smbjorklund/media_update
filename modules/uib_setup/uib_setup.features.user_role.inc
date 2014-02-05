<?php
/**
 * @file
 * uib_setup.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function uib_setup_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 5,
    'machine_name' => 'admin',
  );

  // Exported role: level 1.
  $roles['level 1'] = array(
    'name' => 'level 1',
    'weight' => 4,
    'machine_name' => 'level_1',
  );

  // Exported role: level 2.
  $roles['level 2'] = array(
    'name' => 'level 2',
    'weight' => 3,
    'machine_name' => 'level_2',
  );

  // Exported role: level 3.
  $roles['level 3'] = array(
    'name' => 'level 3',
    'weight' => 2,
    'machine_name' => 'level_3',
  );

  return $roles;
}
