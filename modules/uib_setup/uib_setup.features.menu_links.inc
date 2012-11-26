<?php
/**
 * @file
 * uib_setup.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uib_setup_menu_default_menu_links() {
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
  // Exported menu link: menu-global-menu-no:http:///www.uib.no/om/kontakt/sentral-kontaktinformasjon
  $menu_links['menu-global-menu-no:http:///www.uib.no/om/kontakt/sentral-kontaktinformasjon'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http:///www.uib.no/om/kontakt/sentral-kontaktinformasjon',
    'router_path' => '',
    'link_title' => 'Kontakt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/aktuelt
  $menu_links['menu-global-menu-no:http://www.uib.no/aktuelt'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/aktuelt',
    'router_path' => '',
    'link_title' => 'Aktuelt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/forskning
  $menu_links['menu-global-menu-no:http://www.uib.no/forskning'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/forskning',
    'router_path' => '',
    'link_title' => 'Forskning',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/internasjonalt
  $menu_links['menu-global-menu-no:http://www.uib.no/internasjonalt'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/internasjonalt',
    'router_path' => '',
    'link_title' => 'Internasjonal',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/om
  $menu_links['menu-global-menu-no:http://www.uib.no/om'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/om',
    'router_path' => '',
    'link_title' => 'Om UiB',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/ub/
  $menu_links['menu-global-menu-no:http://www.uib.no/ub/'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/ub/',
    'router_path' => '',
    'link_title' => 'Bibliotek',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-global-menu-no:http://www.uib.no/utdanning
  $menu_links['menu-global-menu-no:http://www.uib.no/utdanning'] = array(
    'menu_name' => 'menu-global-menu-no',
    'link_path' => 'http://www.uib.no/utdanning',
    'router_path' => '',
    'link_title' => 'Utdanning',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-global-menu:http:///www.uib.no/about/contact-us/contact
  $menu_links['menu-global-menu:http:///www.uib.no/about/contact-us/contact'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http:///www.uib.no/about/contact-us/contact',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/about
  $menu_links['menu-global-menu:http://www.uib.no/about'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/about',
    'router_path' => '',
    'link_title' => 'About UiB',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/education
  $menu_links['menu-global-menu:http://www.uib.no/education'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/education',
    'router_path' => '',
    'link_title' => 'Education',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/international
  $menu_links['menu-global-menu:http://www.uib.no/international'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/international',
    'router_path' => '',
    'link_title' => 'International',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/news
  $menu_links['menu-global-menu:http://www.uib.no/news'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/news',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/research
  $menu_links['menu-global-menu:http://www.uib.no/research'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/research',
    'router_path' => '',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-global-menu:http://www.uib.no/ub/en
  $menu_links['menu-global-menu:http://www.uib.no/ub/en'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'http://www.uib.no/ub/en',
    'router_path' => '',
    'link_title' => 'Library',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About UiB');
  t('Aktuelt');
  t('Bibliotek');
  t('Contact');
  t('Education');
  t('Forskning');
  t('Internasjonal');
  t('International');
  t('Kontakt');
  t('Library');
  t('News');
  t('Om UiB');
  t('Research');
  t('Utdanning');
  t('Webdesk');


  return $menu_links;
}
