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
    //print_r($ou);
    $ou_id[$nid] = $ou->field_uib_ou_id['und'][0]['value'];
  }
  //print_r($ou_id);

  // let's process these then
  foreach ($ou_id as $nid => $oid) {
    $o1 = substr($oid, 0, 2);
    $o2 = substr($oid, 2, 2);
    $o3 = substr($oid, 4, 2);
    if ($o2 >= '20')
      continue;
    if ($o3 != '00')
      continue;  # not an institute

    // look for fag belonging to this ou
    $fspres_oid = implode('.', array('184', (int)$o1, (int)$o2));
    $fspres_url = "http://fs_pres.app.uib.no/sted/$fspres_oid/info.json";
    uibx_log('GET ' . $fspres_url);

    $res = drupal_http_request($fspres_url);
    if ($res->code == 200 && $res->headers['content-type'] == 'application/json') {
      $data = drupal_json_decode($res->data);
      foreach ($data['emner_fag'] as $emne) {
        uib_study__update_study('course', $emne, $nid);
      }
      foreach ($data['studieprogrammer_fag'] as $program) {
        uib_study__update_study('program', $program, $nid);
      }
    }
    else {
      uibx_log("GET $fspres_url: " . $res->code . ' ' . $res->status_message, 'warning');
    }
  }
}

function uib_study__update_study($type, $study, $nid) {
  //print_r(array($type, $study, $nid));
  $no_path_prefix = $type == 'course' ? 'emne' : 'studieprogram';
  $en_path_prefix = $type == 'course' ? $type : 'studyprogramme';

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_study_code', 'value', $study['id'])
    ->execute();
  if (empty($result)) {
    // Create a new one
    $node = new stdClass();
    $node->type = 'uib_study';
    $node->uid = 1;
    $node->status = 1;
    $node->revision = 0;
    $node->language = 'nb';
    $node->path = array(
      'alias' => $no_path_prefix . '/' . $study['id'],
      'language' => 'nb',
    );
    $node->title = $study['title_no'];
    $node->field_uib_study_code['und'][0]['value'] = $study['id'];
    $node->field_uib_ou['und'][0]['target_id'] = $nid;
    node_save($node);

    // set tnid
    $node->tnid = $node->nid;
    node_save($node);

    $en_node = new stdClass();
    $en_node->type = 'uib_study';
    $en_node->uid = 1;
    $en_node->status = 1;
    $en_node->revision = 0;
    $en_node->language = 'en';
    $en_node->tnid = $node->nid;
    $en_node->path = array(
      'alias' => $en_path_prefix . '/' . $study['id'],
      'language' => 'en',
    );
    $en_node->title = $study['title_en'];
    $en_node->field_uib_study_code['und'][0]['value'] = $study['id'];
    $en_node->field_uib_ou['und'][0]['target_id'] = $nid;
    node_save($en_node);
    uibx_log("Created $type " . $study['id'] . " as node " . $node->nid);
    return;
  }

  $nodes = node_load_multiple(array_keys($result['node']));
  foreach ($nodes as $node) {
    $edit = FALSE;
    $title = ($node->language == 'nb') ? $study['title_no'] : $study['title_en'];
    if ($node->title != $title) {
      $node->title = $title;
      $edit = TRUE;
    }
    if ($node->field_uib_ou['und'][0]['target_id'] != $nid) {
      $node->field_uib_ou['und'][0]['target_id'] = $nid;
      $edit = TRUE;
    }

    if ($edit) {
      node_save($node);
      uibx_log("$type " . $study['id'] . " updated");
    }
    else {
      uibx_log("$type " . $study['id'] . " unchanged");
    }
  }
}
