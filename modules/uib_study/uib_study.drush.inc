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
  $study_status = array();
  $studies_all = array();
  $incomplete_refs = array();
  $query = 'SELECT n.status, c.entity_id, c.field_uib_study_code_value
    FROM node n, field_data_field_uib_study_code c
    WHERE n.nid = c.entity_id';
  $result = db_query($query);
  foreach ($result as $row) {
    $unused_codes[$row->field_uib_study_code_value] = $row->entity_id;
    $studies_all[$row->field_uib_study_code_value] = $row->entity_id;
    $study_status[$row->field_uib_study_code_value] = $row->status;
  }
  $unused_codes = $studies_all;

  // Find what Organization Units we have
  $ou_id = array();
  $query = 'SELECT o.entity_id, o.field_uib_ou_id_value
    FROM node n, field_data_field_uib_ou_id o
    WHERE n.nid = o.entity_id AND n.type = :bnd';
  $result = db_query($query, array(':bnd' => 'uib_ou'));
  foreach ($result as $row) {
    $ou_id[$row->entity_id] = $row->field_uib_ou_id_value;
  }

  $err = 0;

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
    $res = uib_study__fspres_request("sted/$fspres_oid/info.json");
    if ($res->code == 200 && $res->headers['content-type'] == 'application/json') {
      $data = drupal_json_decode($res->data);
      if (isset($data['emner_fag'])) {
        foreach ($data['emner_fag'] as $emne) {
          $missing_refs = uib_study__update_study('course', $emne, $nid, $studies_all);
          if ($missing_refs) {
            $incomplete_refs[$emne['id']] = $missing_refs;
          }
          unset($unused_codes[$emne['id']]);
        }
      }
      if (isset($data['studieprogrammer_fag'])) {
        foreach ($data['studieprogrammer_fag'] as $program) {
          $missing_refs = uib_study__update_study('program', $program, $nid, $studies_all);
          if ($missing_refs) {
            $incomplete_refs[$program['id']] = $missing_refs;
          }
          unset($unused_codes[$program['id']]);
        }
      }
    }
    else {
      if ($res->code != 404) {
        $err++;
      }
    }
  }

  // if possible, fix any remaining incomplete program references
  if ($incomplete_refs) {
    foreach ($incomplete_refs as $study_code => $missing_refs) {
      $study_node = node_load($studies_all[$study_code]);
      $incomplete = entity_metadata_wrapper('node', $study_node);
      $delta = count($study_node->field_uib_study_part_of['und']);
      $found = 0;
      foreach ($missing_refs as $missing) {
        if ($studies_all[$missing]) {
          $incomplete->field_uib_study_part_of[$delta]->set($studies_all[$missing]);
          $delta++;
          $found++;
        }
        else {
          uibx_log("Referenced program [from $study_code] $missing is missing", 'warning');
        }
      }
      if ($found) {
        $incomplete->save();
        uibx_log("Study $study_code updated");
      }
    }
  }

  if ($err) {
    uibx_log("Will not unpublish studies because $err errors occured", 'warning');
  }
  else {
    foreach ($unused_codes as $study_code => $study_nid) {
      if ($study_status[$study_code]) {
        $unused = node_load($study_nid);
        $unused->status = 0;
        node_save($unused);
        uibx_log('Unpublished study: ' . $study_code);
      }
    }
  }
}

/**
 * [uib_study__update_study description]
 * @param  [type] $type      [description]
 * @param  [type] $study     [description]
 * @param  [type] $ou_nid    [description]
 * @param  [type] &$existing [list of existing studies]
 * @return [type]            [Returns an empty array or an array with missing study programs]
 */
function uib_study__update_study($type, $study, $ou_nid, &$existing) {
  $no_path_prefix = $type == 'course' ? 'emne' : 'studieprogram';
  $en_path_prefix = $type == 'course' ? $type : 'studyprogramme';

  $admin_user = &drupal_static(__FUNCTION__);
  if (!isset($admin_user)) {
    $admin_user = user_load(1);
  }

  $refs_incomplete = array();
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_study_type', 'value', $type)
    ->fieldCondition('field_uib_study_code', 'value', $study['id'])
    ->addMetaData('account', $admin_user)
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

    // Node title
    if (empty($study['title_no']) && empty($study['title_en'])) {
      $metadata->title->set($study['id']);
    }
    else {
      $metadata->title->set($study['title_no'] . ' / ' . $study['title_en']);
    }

    // Populate Norwegian version
    $metadata->language->set('nb');
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

    // program references
    if (!empty($study['ref_programs'])) {
      foreach ($study['ref_programs'] as $ref_code) {
        $delta = 0;
        if ($existing[$ref_code]) {
          $metadata->field_uib_study_part_of[$delta]->set($existing[$ref_code]);
          $delta++;
        }
        else {
          $refs_incomplete[] = $ref_code;
        }
      }
    }

    $metadata->save();
    $existing[$study['id']] = $study_node->nid;

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
    return $refs_incomplete;
  }

  $nodes = node_load_multiple(array_keys($result['node']));
  foreach ($nodes as $node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $edit = FALSE;

    if ($wrapper->status->value() == 0) {
      $wrapper->status->set(1);
      $edit = TRUE;
    }

    if (empty($study['title_no']) && empty($study['title_en'])) {
      $title = $study['id'];
    }
    else {
      $title = $study['title_no'] . ' / ' . $study['title_en'];
    }
    if ($wrapper->title->value() != $title) {
      $wrapper->title->set($title);
      $edit = TRUE;
    }

    if ($wrapper->language('nb')->field_uib_study_title->value() != $study['title_no']) {
      $wrapper->language('nb')->field_uib_study_title->set($study['title_no']);
      $edit = TRUE;
    }
    if ($wrapper->language('en')->field_uib_study_title->value() != $study['title_en']) {
      $wrapper->language('en')->field_uib_study_title->set($study['title_en']);
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

    if (!empty($study['ref_programs'])) {
      // Check if any change in referenced programs
      $prev_refs = array();
      foreach ($wrapper->field_uib_study_part_of->getIterator() as $delta => $term) {
        $prev_refs[] = $term->raw();
      }
      $new_refs = array();
      foreach ($study['ref_programs'] as $ref_code) {
        if ($existing[$ref_code]) {
          $new_refs[] = $existing[$ref_code];
        }
      }
      sort($prev_refs);
      sort($new_refs);
      if ($prev_refs != $new_refs) {
        $wrapper->field_uib_study_part_of = array();
        $delta = 0;
        foreach ($study['ref_programs'] as $ref_code) {
          if ($existing[$ref_code]) {
            $wrapper->field_uib_study_part_of[$delta]->set($existing[$ref_code]);
            $delta++;
          }
          else {
            $refs_incomplete[] = $ref_code;
          }
        }
        $edit = TRUE;
      }
    }

    if ($edit) {
      $wrapper->save();
      uibx_log("$type " . $study['id'] . " updated");
    }
  }
  return $refs_incomplete;
}
