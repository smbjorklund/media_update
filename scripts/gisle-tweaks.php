<?php

/**
 *  This tweaks the gaa041 user so that it can be used for testing.
 *  gaa041 is already a level2 user.
 */

$user = user_load_by_name('gaa041');
if (!$user) {
  print "Can't look up user\n";
  die;
}

$areas = array("hf", "grieg", "fag/digitalkultur");

// make the user content manager for the given areas (both 'nb' and 'en' version)
foreach ($areas as $area_path) {
  $norm_path = drupal_get_normal_path($area_path, 'nb');
  if (substr($norm_path, 0, 5) == 'node/') {
    $area = node_load(substr($norm_path, 5));
    foreach (translation_node_get_translations($area->tnid) as $n) {
      $a = node_load($n->nid);
      if (add_content_manager($a, $user)) {
        print "Added $user->name as content manager for $a->title\n";
        node_save($a);
      }
    }
  }
}

// make it possible to see the dpm() output
module_enable(array('devel'));
foreach (user_roles() as $rid => $role_name) {
  if (substr($role_name, 0, 5) == 'level') {
    user_role_grant_permissions($rid, array('access devel information'));
  }
}

cache_clear_all();

function add_content_manager($area, $user) {
  foreach ($area->field_uib_content_manager['und'] as $cm) {
    if ($cm['target_id'] == $user->uid)
      return FALSE; // already present
  }
  $area->field_uib_content_manager['und'][] = array( 'target_id' => $user->uid );
  return TRUE;
}
