<?php

# Script that tries to normalize the values in the uib_area_parent field of area
# nodes.  Pass in the option --force to make the script actually update the database.
#
# The --rearrange isn't effective yet, since the uib_area_node_presave works against
# us and messes up the improved ordering.  The order that the parents areas display
# is anyway random (see the implementation of the 'area_parents' block).
#
# See https://rts.uib.no/issues/5268

$DRY_RUN = !drush_get_option('force');
$DO_REARRANGE = drush_get_option('rearrange');

// Pick up all current areas
$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'area')
  //->propertyCondition('status', 1)
  ->execute();

if (empty($result['node'])) {
  print "No areas found\n";
  exit(1);
}

$areas = node_load_multiple(array_keys($result['node']));
// echo count($areas), " areas\n\n";

foreach ($areas as $nid => $area) {
  $anchestors = anchestors($area, $areas);

  // We sort achestors by depth so that more remote relatives are listed
  // later.
  stable_asort($anchestors);

  // Calculate the reference value as found on the node
  $v = array();
  foreach ($anchestors as $pnid => $depth) {
    $v[] = array('target_id' => $pnid);
  }

  // did anything change?
  if (!isset($area->field_uib_area_parents['und'])) {
    if (empty($v))
      continue;
  }
  elseif ($area->field_uib_area_parents['und'] == $v)
    continue;

  $is_rearrange = (count($v) == count($area->field_uib_area_parents['und']));
  if ($is_rearrange) {
    if ($DO_REARRANGE) {
      uibx_log("Rearraning parent area order for $area->nid $area->title");
    }
    else {
      uibx_log("Would rearrange parent area order for $area->nid $area->title");
      continue;
    }
  }
  if ($DRY_RUN) {
    uibx_log("Would update parents for $area->nid $area->title");
  }
  else {
    // Actually do the change
    uibx_log("Updating parents for $area->nid $area->title");
    $area->field_uib_area_parents['und'] = $v;
    node_save($area);
  }
}

function anchestors($area, &$areas, $depth=0) {
  $ret = array();
  if (empty($area->field_uib_area_parents))
    return $ret;
  foreach ($area->field_uib_area_parents['und'] as $ref) {
    $nid = $ref['target_id'];
    if (!isset($areas[$nid])) {
      uibx_log("parent $nid of $area->nid $area->title doesn't exit", 'warning');
      continue;
    }
    if (!isset($ret[$nid]) || $depth > $ret[$nid])
      $ret[$nid] = $depth;
    foreach (anchestors($areas[$nid], $areas, $depth+1) as $a_nid => $a_depth) {
      if (!isset($ret[$a_nid]) || $a_depth > $ret[$a_nid])
        $ret[$a_nid] = $a_depth;
    }
  }
  return $ret;
}

function stable_asort(&$array) {
  // I hate PHP!
  $tmp = array();
  $i = 0;
  foreach ($array as $key => $value) {
    $tmp[] = array($i, $key, $value);
    $i++;
  }
  uasort($tmp, function($a, $b) {
    $cmp1 = cmp($a[2], $b[2]);
    return $cmp1 == 0 ? cmp($a[0], $b[0]) : $cmp1;
  });
  $array = array();
  foreach ($tmp as $v) {
    $array[$v[1]] = $v[2];
  }
}

function cmp($a, $b)
{
  if ($a == $b)
    return 0;
  return ($a < $b) ? -1 : 1;
}
