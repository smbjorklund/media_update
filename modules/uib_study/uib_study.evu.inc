<?php

function uib_study__evu_courses_page() {
  global $language;
  $today = date("c");

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
  $nodes = node_load_multiple(array_keys($results['node']));

  $page = array();
  $page['header'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Offered EVU Courses' . ' (' . count($nodes) . ')'),
  );

  // fetch data from fs-pres; XXX make it a single request
  $courses = array();
  foreach($nodes as $nid => $node) {
    $data = uib_study__fspres_get_node_json($nid, 'info.json');
    $data['node'] = $node;
    $courses[$data['evu']['kurskode']] = $data;
  }

  // XXX Categorize and sort them

  // Generate page
  foreach($courses as $kode => $kurs) {
    $div = array(
      '#type' => 'container',
      '#attributes' => array(
        'style' => "border: 1px solid black; margin: 5px; padding: 5px; border-radius: 3px; background: #ddd;",
      ),
    );
    $div['header'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h3',
      '#value' => l($kurs['emnenavn'], "node/" . $kurs['node']->nid),
    );

    if ($kurs['evu']['kurs']) {
      foreach ($kurs['evu']['kurs'] as $instance) {
        $div[] = uib_study__evu_courses($instance);
      }
    }
    else {
      $div['no_instances'] = array(
        '#markup' => t('There are currently no scheduled courses of this subject'),
      );
    }
    $page[$kode] = $div;

  }

  // Force EVU as the current area for this page.
  uib_area__get_current(77320);

  return $page;
}

function uib_study__evu_date($iso, $y=0) {
  $d = explode('-', $iso);
  if ($y == $d[0]) {
    array_shift($d);
  }
  return implode('.', array_reverse($d));
}

/**
 * Pick up evu data to created block of cource information.
 *
 * @param object $node Full node object.
 *
 * @return array Return a drupal render array as content of block.
 */
function uib_study__evu_courses_block($node) {
  $data = uib_study__fspres_get_node_json($node->nid, 'info.json', FALSE);
  foreach ($data['evu']['kurs'] as $key => $value) {
    $result = uib_study__evu_courses($value);
  }
  $block = array(
    'title' => 'EVU',
    'content' => $result,
  );

  return $block;
}

/**
 * Parses EVU cource instance.
 *
 * @param  array $instance
 *   Instance of EVU kurs to be parsed.
 *
 * @return array
 *   An render array with key EVU data.
 */
function uib_study__evu_courses($instance) {
  $today = date("c");
  $cource = '';

  $tidkode = $instance['kursid']['tidkode'];
  $y = substr($tidkode, 2);
  $tdiv = array(
    '#type' => 'container',
    '#attributes' => array(
      'style' => 'float: left; width: 60%; padding-left: 2em;',
    ),
    'tidkode' => array('#markup' => '<span style="font-weight: bold; font-size: larger;">' . check_plain($tidkode) . "</span>"),
  );

  if (isset($instance['dato_fra'])) {
    $tdiv['dates'] = array('#markup' => '<br>' . uib_study__evu_date($instance['dato_fra'], $y) . '–' . uib_study__evu_date($instance['dato_til']));
  }

  $idiv = array(
    '#type' => 'container',
    '#attributes' => array(),
    'time' => $tdiv,
  );

  if (!empty($instance['url_evuweb'])) {
    $sdiv = array(
      '#type' => 'container',
      '#attributes' => array(
        'style' => 'float: left; width: 20%; min-width: 8em; overflow: hidden;',
      ),
    );

    $text = '<span style="font-weight: bold; font-size: larger;">' . t('Sign up') . '</span>';

    if (isset($instance['kostnad'])) {
      $text .= '<br>NOK&nbsp;' . $instance['kostnad'];
    }

    $text = l($text, $instance['url_evuweb'], array(
      'html' => 'TRUE',
      'attributes' => array(
        'style' => 'background:#484; color: white; display: block; text-align: center; padding: 3px; border-radius: 6px;',
      ),
    ));

    $sdiv['button'] = array('#markup' => $text);

    if (isset($instance['dato_frist_soknad'])) {
      if ($instance['dato_frist_soknad'] < $today) {
        $sdiv['expires'] = array('#markup' => t('Expired'));
      }
      else {
        $sdiv['expires'] = array('#markup' => '<div>' . t('Expires') . ':&nbsp;' . uib_study__evu_date($instance['dato_frist_soknad'], $y) . '</div>');
      }
    }

    $idiv['signup'] = $sdiv;
  }

  $idiv['clear'] = array('#markup' => '<div style="clear: both;"></div>');
  $div[$tidkode] = $idiv;

  return $div;
}
