<?php
/**
 * @file
 *  Fix for putting views in menu
 */
//define('DRUPAL_ROOT', getcwd());
define('DRUPAL_ROOT', '/Users/sbe004/Sites/w3.uib.no/drupal');
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$query_faculty_en = new EntityFieldQuery;
$query_faculty_en = $query_faculty_en
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'en')
    ->fieldCondition('field_uib_area_type','value', 'faculty', '=')
    ->range(0, 100);

$result_fac = $query_faculty_en->execute();

foreach ($result_fac as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'en','faculty',$area->nid);
  }
}

$query_institute_en = new EntityFieldQuery;
$query_institute_en = $query_institute_en
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'en')
    ->fieldCondition('field_uib_area_type','value', 'institute', '=')
    ->range(0, 200);

$result_inst = $query_institute_en->execute();

foreach ($result_inst as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'en','institute',$area->nid);
  }
}

$query_researchgroups_en = new EntityFieldQuery;
$query_researchgroups_en = $query_researchgroups_en
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'en')
    ->fieldCondition('field_uib_area_type','value', 'researchgroups', '=')
    ->range(0, 200);

$result_rg = $query_researchgroups_en->execute();

foreach ($result_rg as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'en','researchgroups',$area->nid);
  }
}

$query_faculty_nb = new EntityFieldQuery;
$query_faculty_nb = $query_faculty_nb
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'nb')
    ->fieldCondition('field_uib_area_type','value', 'faculty', '=')
    ->range(0, 100);

$result_fac_nb = $query_faculty_nb->execute();

foreach ($result_fac_nb as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'nb','faculty',$area->nid);
  }
}

$query_institute_nb = new EntityFieldQuery;
$query_institute_nb = $query_institute_nb
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'nb')
    ->fieldCondition('field_uib_area_type','value', 'institute', '=')
    ->range(0, 200);

$result_inst_nb = $query_institute_nb->execute();

foreach ($result_inst_nb as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'nb','institute',$area->nid);
  }
}

$query_researchgroups_nb = new EntityFieldQuery;
$query_researchgroups_nb = $query_researchgroups_nb
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'area')
    ->propertyCondition('language', 'nb')
    ->fieldCondition('field_uib_area_type','value', 'researchgroups', '=')
    ->range(0, 200);

$result_rg_nb = $query_faculty->execute();

foreach ($result_rg_nb as $areas) {
  foreach ($areas as $area) {
    $menu_link = menu_link_get_preferred('node/' . $area->nid, 'area');
    add_views_to_menu($menu_link,'nb','researchgroups',$area->nid);
  }
}



function add_views_to_menu($menulink,$language,$areatype,$nid) {

    // get sub tree for area
    $subtree = menu_build_tree('area', array('expanded' => array($menulink['mlid']),'min_depth' => 2));
    $whitelist_mlinks = array('Research', 'Forskning', 'Utdanning', 'Education', 'Contact', 'Contact us', 'Kontakt', 'Kontakt oss');
    if ($areatype == "faculty") {
      if ($language == "en") {
        $views_list = array(
         'Contact' => array (
           'Faculty and staff' => 'persons',
            'Map' => 'map',
          ),
          'Education' => array (
            'Study programmes' => 'study-programmes',
            'Courses' => 'courses',
            'Bachelor programmes' => 'bachelor-programmes',
            'Master programmes' => 'master-programmes',
            'One year programmes' => 'one-year-programmes',
          ),
        );
      }
      else if ($language == "nb") {
        $views_list = array(
         'Kontakt' => array (
           'Ansattkatalog' => 'persons',
            'Kart' => 'map',
          ),
          'Utdanning' => array (
            'Studieprogram' => 'study-programmes',
            'Emner' => 'courses',
            'Bachelorprogram' => 'bachelor-programmes',
            'Masterprogram' => 'master-programmes',
            'Arstudium' => 'one-year-programmes',
          ),
        );
      }
    }
    else if ($areatype == "institute") {
      if ($language == "en") {
        $views_list = array(
         'Contact' => array (
           'Faculty and staff' => 'persons',
            'Map' => 'map',
          ),
          'Education' => array (
            'Study programmes' => 'study-programmes',
            'Courses' => 'courses',
            'Bachelor programmes' => 'bachelor-programmes',
            'Master programmes' => 'master-programmes',
            'One year programmes' => 'one-year-programmes',
          ),
        );
      }
      else if ($language == "nb") {
        $views_list = array(
         'Kontakt' => array (
           'Ansattkatalog' => 'persons',
            'Kart' => 'map',
          ),
          'Utdanning' => array (
            'Studieprogram' => 'study-programmes',
            'Emner' => 'courses',
            'Bachelorprogram' => 'bachelor-programmes',
            'Masterprogram' => 'master-programmes',
            'Arstudium' => 'one-year-programmes',
          ),
        );
      }
    }
    else if ($areatype == "researchgroups") {
      if ($language == "en") {
        $views_list = array(
         'Contact' => array(
           'Staff' => 'persons',
          ),
         'Utdanning' => array(
          
         ),
        );
      }
      else if ($language == "nb") {
        $views_list = array(
         'Kontakt' => array(
           'Ansattkatalog' => 'persons',
          ),
         'Education' => array(
         ),
        );
      }
    }
    else {
      return;
    }
    foreach ($subtree as $menuitem) {
      if (in_array($menuitem['link']['link_title'], $whitelist_mlinks)) {
        $subsubtree = menu_build_tree('area', array('expanded' => array($menuitem['link']['mlid']),'min_depth' => 3));
        $subsubitems = array();
        foreach ($subsubtree as $submenuitem ) {
            $subsubitems[] = $submenuitem['link']['link_title'];
        }
        if (($menuitem['link']['link_title'] == 'Contact us') || ($menuitem['link']['link_title'] == 'Contact')) {
          foreach ($views_list['Contact'] as $delta => $view) {
            if (!in_array($delta,$subsubitems)) {
              $menu_link = array(
               'menu_name' => 'area',
               'link_path' => 'node/' . $nid . '/' .  $view,
               'link_title' => $delta,
               'weight' => -50,
               'plid' => $menuitem['link']['mlid'],
              );
              menu_link_save($menu_link);
            }
          }
        }
        else if (($menuitem['link']['link_title'] == 'Kontakt oss') || ($menuitem['link']['link_title'] == 'Kontakt')) {
          foreach ($views_list['Kontakt'] as $delta => $view) {
            if (!in_array($delta,$subsubitems)) {
              $menu_link = array(
               'menu_name' => 'area',
               'link_path' => 'node/' . $nid . '/' .  $view,
               'link_title' => $delta,
               'weight' => -50,
               'plid' => $menuitem['link']['mlid'],
              );
              menu_link_save($menu_link);
            }
          }
        }
        else if ($menuitem['link']['link_title'] == 'Education') {
          if (isset($views_list['Education'])) {
            foreach ($views_list['Education'] as $delta => $view) {
              if (!in_array($delta,$subsubitems)) {
                $menu_link = array(
                 'menu_name' => 'area',
                 'link_path' => 'node/' . $nid . '/' .  $view,
                 'link_title' => $delta,
                 'weight' => -50,
                 'plid' => $menuitem['link']['mlid'],
                );
                menu_link_save($menu_link);
              }
            }  
          }
        }
        else if ($menuitem['link']['link_title'] == 'Utdanning') {
          if (isset($views_list['Utdanning'])) {
            foreach ($views_list['Utdanning'] as $delta => $view) {
              if (!in_array($delta,$subsubitems)) {
                $menu_link = array(
                 'menu_name' => 'area',
                 'link_path' => 'node/' . $nid . '/' .  $view,
                 'link_title' => $delta,
                 'weight' => -50,
                 'plid' => $menuitem['link']['mlid'],
                );
                menu_link_save($menu_link);
              }
            }  
          }
        }
        else if ($menuitem['link']['link_title'] == 'Research') {
        }
        else if ($menuitem['link']['link_title'] == 'Forskning') {
        }
      }
    }
  
}