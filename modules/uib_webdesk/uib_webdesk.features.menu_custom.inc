<?php
/**
 * @file
 * uib_webdesk.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uib_webdesk_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-webdesk.
  $menus['menu-webdesk'] = array(
    'menu_name' => 'menu-webdesk',
    'title' => 'Webdesk',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Webdesk');


  return $menus;
}
