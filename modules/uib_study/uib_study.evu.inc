<?php

function uib_study__evu_courses_page() {
  global $language;
  $query = new EntityFieldQuery;
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'uib_study')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_uib_study_category', 'value', 'evu')
    ->fieldOrderBy('field_uib_study_code', 'value')
    ->execute();
  if (!$results) {
    return t('No EVU courses found');
  }
  $courses = node_load_multiple(array_keys($results['node']));

  $page = array();
  $page['header'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('EVU Courses'),
  );

  foreach($courses as $nid => $node) {
    $study = entity_metadata_wrapper('node', $node);
    $study->language($language->language);
    $page[$nid] = array(
      array(
        '#type' => 'html_tag',
        '#tag' => 'h3',
        '#value' => l($study->field_uib_study_code->value() . ' ' . $study->field_uib_study_title->value(), "node/$nid")
      ),
    );
  }

  // Force EVU as the current area for this page
  uib_area__get_current(77320);

  return $page;
}
