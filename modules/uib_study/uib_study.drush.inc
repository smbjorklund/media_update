<?php
/**
 * @file
 * @return [type] [description]
 */
function uib_study_drush_command() {
  $items['uib-sync-fs'] = array(
    'description' => 'Syncronise with fs-pres.app.uib.no',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
  );
  return $items;
}

function drush_uib_study_uib_sync_fs() {
  // Find out what study_codes are in use.
  $unused_codes = array();
  $result = db_select('field_data_field_uib_study_code', 'c')
    ->fields('c', array('entity_id', 'field_uib_study_code_value'))
    ->execute();
  foreach ($result as $row) {
    $unused_codes[$row->field_uib_study_code_value][] = $row->entity_id;
  }

  // Find what Organization Units we have
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'uib_ou')
    ->execute();

  $ou_id = array();
  foreach (array_keys($result['node']) as $nid) {
    $ou = node_load($nid); // Must be a better way than to load the full node here.
    $ou_id[$nid] = $ou->field_uib_ou_id['und'][0]['value'];
  }

  $err = 0;
  $not_found = 0;

  // let's process these then
  foreach ($ou_id as $nid => $oid) {
    $o1 = substr($oid, 0, 2);
    $o2 = substr($oid, 2, 2);
    $o3 = substr($oid, 4, 2);
    if ($o1 >= '20') # optimize; no need to look at adm/misc places
      continue;
    if ($o3 != '00')
      continue;  # not an institute

    // look for fag belonging to this ou
    $fspres_oid = implode('.', array('184', (int)$o1, (int)$o2));
    $fspres_url = "http://fs-pres.app.uib.no/sted/$fspres_oid/info.json";

    $res = drupal_http_request($fspres_url);
    if ($res->code == 200 && $res->headers['content-type'] == 'application/json') {
      uibx_log('GET ' . $fspres_url);
      $data = drupal_json_decode($res->data);
      if (isset($data['emner_fag'])) {
        foreach ($data['emner_fag'] as $emne) {
          uib_study__update_study('course', $emne, $nid);
          unset($unused_codes[$emne['id']]);
        }
      }
      if (isset($data['studieprogrammer_fag'])) {
        foreach ($data['studieprogrammer_fag'] as $program) {
          uib_study__update_study('program', $program, $nid);
          unset($unused_codes[$program['id']]);
        }
      }
    }
    else {
      uibx_log("GET $fspres_url: " . $res->code . ' ' . $res->status_message, ($res->code == 404 ? 'warning' : 'error'));
      if ($res->code == 404) {
        $not_found++;
      }
      else {
        $err++;
      }
    }
  }

  if ($err) {
    uibx_log("Will not delete studies when $err errors occured", 'warning');
  }
  else {
    $nodes_to_delete = array();
    foreach ($unused_codes as $code => $nids) {
      array_splice($nodes_to_delete, count($nodes_to_delete), 0, $nids);
      uibx_log("Deleting nodes for $code", 'warning');
    }
    $delete_limit = variable_get('uib_fs_delete_limit', 500);
    if (count($nodes_to_delete) <= $delete_limit) {
      if ($nodes_to_delete) {
        node_delete_multiple($nodes_to_delete);
        uibx_log('Deleted ' . count($nodes_to_delete) . ' study nodes', 'warning');
      }
    }
    else {
      uibx_log('Cowardly refused to delete ' . count($nodes_to_delete) . ' study nodes', 'error');
    }
  }
}

function uib_study__update_study($type, $study, $ou_nid) {
  $no_path_prefix = $type == 'course' ? 'emne' : 'studieprogram';
  $en_path_prefix = $type == 'course' ? $type : 'studyprogramme';

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_study_type', 'value', $type)
    ->fieldCondition('field_uib_study_code', 'value', $study['id'])
    ->execute();

  if (empty($result)) {
    // Create a new one.
    $study_node = entity_create('node', array(
      'type' => 'uib_study',
      'uid' => 1,
      'status' => 1,
      'revision' => 0,
      )
    );
    $metadata = entity_metadata_wrapper('node', $study_node);
    $handler = entity_translation_get_handler('node', $study_node, TRUE);
    $translation = array(
      'translate' => 0,
      'status' => 1,
      'language' => 'en',
      'source' => 'nb',
    );
    $handler->setTranslation($translation, $study_node);

    // Populate Norwegain version
    $metadata->language = 'nb';
    $metadata->title = $study['title_no'];
    if (!$metadata->title->value()) {
      $metadata->title = $study['id'];
    }
    $metadata->language('nb')->field_uib_study_title->set($study['title_no']);
    if (!$metadata->language('nb')->field_uib_study_title->value()) {
      $metadata->language('nb')->field_uib_study_title->set($study['id']);
    }
    $metadata->field_uib_study_code->set($study['id']);
    $metadata->field_uib_study_type->set($type);
    $metadata->field_uib_ou->set($ou_nid);
    if (isset($study['category'])) {
      $metadata->field_uib_study_category->set($study['category']);
    }

    // Populate English version
    $metadata->language('en')->field_uib_study_title->set($study['title_en']);
    if (!$metadata->language('en')->field_uib_study_title->value()) {
      $metadata->language('en')->field_uib_study_title->set($study['id']);
    }
    $metadata->save();

    // Define node path alias
    $path = array(
      'source' => 'node/' . $metadata->nid->value(),
      'alias' => $no_path_prefix . '/' . $study['id'],
      'language' => 'nb',
      );
    path_save($path);

    $path = array(
      'source' => 'node/' . $metadata->nid->value(),
      'alias' => $en_path_prefix . '/' . $study['id'],
      'language' => 'en',
      );
    path_save($path);

    uibx_log("Created $type " . $study['id']);
    return;
  }

  $nodes = node_load_multiple(array_keys($result['node']));
  foreach ($nodes as $node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $edit = FALSE;
    $title = ($node->language == 'nb') ? $study['title_no'] : $study['title_en'];
    if (empty($title))
      $title = $study['id'];
    if ($node->title != $title) {
      $node->title = $title;
      $edit = TRUE;
    }

    if ($wrapper->field_uib_ou->raw() != $ou_nid) {
      $wrapper->field_uib_ou->set($ou_nid);
      $edit = TRUE;
    }
    if (isset($study['category'])) {
      if ($wrapper->field_uib_study_category->value() != $study['category']) {
        $wrapper->field_uib_study_category->set($study['category']);
        $edit = TRUE;
      }
    }

    if ($edit) {
      $wrapper->save();
      uibx_log("$type " . $study['id'] . " updated");
    }
  }
}
