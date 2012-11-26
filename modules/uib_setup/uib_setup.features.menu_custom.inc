<?php
/**
 * @file
 * uib_setup.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uib_setup_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-global-menu.
  $menus['menu-global-menu'] = array(
    'menu_name' => 'menu-global-menu',
    'title' => 'Global menu',
    'description' => '',
  );
  // Exported menu: menu-global-menu-no.
  $menus['menu-global-menu-no'] = array(
    'menu_name' => 'menu-global-menu-no',
    'title' => 'Global menu no',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Global menu');
  t('Global menu no');
  t('Management');
  t('The <em>Management</em> menu contains links for administrative tasks.');


  return $menus;
}
