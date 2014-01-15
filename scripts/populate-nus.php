<?php

# Populate vocabulary 'uib_nus' with taxonomy terms.

$data = FALSE;
$url = 'http://fs-pres.test.uib.no/';
$nusId = 'fag/info.json';
$vocabularyName = 'uib_nus';
$url .= $nusId;
$field_nusid = 'field_uib_nus_id';

$res = drupal_http_request($url);
if ($res->code == 200 && $res->headers['content-type'] == 'application/json') {
  uibx_log('GET ' . $url);
  $data = drupal_json_decode($res->data);
}

$vocabulary = taxonomy_vocabulary_machine_name_load($vocabularyName);
foreach ($data as $key => $value) {
  $map = explode('.', $key);
  if (array_key_exists(1, $map)) {
    $child_term = entity_create('taxonomy_term', array(
      'name' => $key . ' ' . $value['nn'] . ' / ' . $value['en'],
      'vocabulary_machine_name' => $vocabularyName,
      'parent' => array(0),
      'parent' => array($parent_term->tid),
      'vid' => $vocabulary->vid,
    ));
    $term = entity_metadata_wrapper('taxonomy_term', $child_term);
    $term->$field_nusid->set($key);
    $term->language('nb')->field_uib_term_title->set($value['nn']);
    $term->language('en')->field_uib_term_title->set($value['en']);
    $term->save();
    if (isset($parent_term->tid)) {
      uibx_log('Created term: ' . $child_term->name . ' (' . $child_term->tid . ') child of ' . $parent_term->tid, 'success');
    }
  }
  else {
    $parent_term = entity_create('taxonomy_term', array(
      'name' => $key . ' ' . $value['nn'] . ' / ' . $value['en'],
      'vocabulary_machine_name' => $vocabularyName,
      'parent' => array(0),
      'vid' => $vocabulary->vid,
    ));
    $term = entity_metadata_wrapper('taxonomy_term', $parent_term);
    $term->$field_nusid->set($key);
    $term->language('nb')->field_uib_term_title->set($value['nn']);
    $term->language('en')->field_uib_term_title->set($value['en']);
    $term->save();
    if (isset($parent_term->tid)) {
      uibx_log('Created parent term: ' . $parent_term->name . ' (' . $parent_term->tid . ')', 'success');
    }
  }
}
