<?php
/**
 * @file
 * @return [type] [description]
 */
function uib_study_drush_command() {
  $items['uib-sync-fs'] = array(
    'description' => 'Syncronise with fs_pres.app.uib.no',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
  );
  return $items;
}

function drush_uib_study_uib_sync_fs() {
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'uib_ou')
    ->execute();

  //print_r($result);

  $ou_id = array();
  foreach (array_keys($result['node']) as $nid) {
    $ou = node_load($nid); // must be a better way than to load the full node here
    print_r($ou);
    $ou_id[$nid] = $ou->field_uib_ou_id['und'][0]['value'];
  }
  print_r($ou_id);

  // let's process these then
  foreach ($ou_id as $nid => $oid) {
    $o1 = substr($oid, 0, 2);
    $o2 = substr($oid, 2, 2);
    $o3 = substr($oid, 4, 2);
    if ($o2 >= '20')
      continue;
    if ($o3 != '00')
      continue;  # not an institute
    // XXX look for fag belonging to this ou
  }
}
