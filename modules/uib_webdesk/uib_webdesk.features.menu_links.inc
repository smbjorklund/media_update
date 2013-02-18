<?php
/**
 * @file
 * uib_webdesk.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uib_webdesk_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management:webdesk
  $menu_links['management:webdesk'] = array(
    'menu_name' => 'management',
    'link_path' => 'webdesk',
    'router_path' => 'webdesk',
    'link_title' => 'Webdesk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-webdesk:node/add/area
  $menu_links['menu-webdesk:node/add/area'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/area',
    'router_path' => 'node/add/area',
    'link_title' => 'Add area',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you add area',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-webdesk:node/add/uib-article
  $menu_links['menu-webdesk:node/add/uib-article'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/uib-article',
    'router_path' => 'node/add/uib-article',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you add content',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-webdesk:node/add/uib-testimonial
  $menu_links['menu-webdesk:node/add/uib-testimonial'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/uib-testimonial',
    'router_path' => 'node/add/uib-testimonial',
    'link_title' => 'Add testimonial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-webdesk:webdesk/all-content
  $menu_links['menu-webdesk:webdesk/all-content'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'webdesk/all-content',
    'router_path' => 'webdesk/all-content',
    'link_title' => 'Find content',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you find all content',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add area');
  t('Add content');
  t('Add testimonial');
  t('Find content');
  t('Webdesk');


  return $menu_links;
}
