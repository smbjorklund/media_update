<?php
/**
 * Creates a page with a list of evu coursed
 */
function uib_study__evu_courses_page() {
  global $language;
  $today = date("c");

  // Fetch all evu uib_study
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

  $evus = node_load_multiple(array_keys($results['node']));
  // Fetch data from fs-pres; XXX make it a single request
  foreach ($evus as $nid => $study) {
    $data = uib_study__fspres_get_node_json($nid, 'info.json');
    $data['node'] = $study;
    $evus[$nid]->data = $data;
  }

  // Get all evu_study_offer uib_articles
  $query = new EntityFieldQuery;
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'uib_article')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_uib_article_type', 'value', 'evu_study_offer')
    ->propertyOrderBy('title', 'ASC')
    ->execute();

  $listed = array();
  $page = array();

  $page['header'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h1',
    '#value' => t('Offered EVU Courses (@count)', array('@count'=> count($evus))),
  );

  // List all evu_study_offer and their evu courses
  if ($results) {
    $artics = node_load_multiple(array_keys($results['node']));
    foreach ($artics as $nid => $artic) {
      $artic_added = FALSE;
      if (!empty ($artic->field_uib_relation['und'])) {
        $course_ids = array_map('current', $artic->field_uib_relation['und']);
        $listed = array_merge ($listed, $course_ids);

        foreach ($course_ids as $course_id) {
          if (!empty($evus[$course_id])){
            if (!$artic_added){
              $artic_added = TRUE;
              $div = array(
                '#type' => 'container',
                '#attributes' => array(
                  'class' => "uib-study-evu-offer",
                ),
                'header' => array(
                  '#type' => 'html_tag',
                  '#tag' => 'h2',
                  '#value' => l($artic->title, "node/$nid"),
                ),
                'lead_text' => array(
                  '#type' => 'html_tag',
                  '#tag' => 'p',
                  '#value' => $artic->field_uib_lead['und'][0]['safe_value'],
                ),
              );
            }
            $div[$course_id] = uib_study__evu_course($evus[$course_id]);
          }
        }
      }
      if($artic_added)
        $page[$nid] = $div;
    }
  }

  // List all evu courses not in an evu_study_offer
  if (sizeof($listed) < sizeof($evus)) {
    $div = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => "uib-study-evu-offer",
      ),
      'header' => array(
        '#type' => 'html_tag',
        '#tag' => 'h2',
        '#value' => t('Other EVU courses'),
      ),
    );
    foreach ($evus as $nid => $evu) {
      if (!array_search($nid, $listed))  {
        $div[$nid] = uib_study__evu_course($evus[$nid]);
      }
    }
    $page['orfans'] = $div;
  }

  // Force EVU as the current area for this page.
  uib_area__get_current(77320);

  return $page;
}

function uib_study__evu_date($iso, $year=0) {
  $d = explode('-', $iso);
  if ($year == $d[0]) {
    array_shift($d);
  }
  return implode('.', array_reverse($d));
}

/**
 * Pick up evu data to created block of course information.
 *
 * @param object $node Full node object.
 *
 * @return array Return a drupal render array as content of block.
 */
function uib_study__evu_courses_block($node) {
  $data = uib_study__fspres_get_node_json($node->nid, 'info.json', FALSE);

  if (sizeof($data['evu']['kurs']) > 0) {
    foreach ($data['evu']['kurs'] as $key => $value) {
      $result = uib_study__evu_instance($value);
    }
  }
  else {
    $result = t('Sorry! There are no evu-courses available at this moment');
  }

  $block = array(
    'title' => 'EVU',
    'content' => $result,
  );

  return $block;
}

/**
 * Parses the information of a course node into a render array
 *
 * @param object $course The course node with a field "data" containing the fs_press information
 *
 * @return array Return a drupal render array with the course information
 */

function uib_study__evu_course($course) {
  global $language;
  $data = $course->data;
  $title = ($language->language == 'nb' ? $data['emnenavn'] : $data ['emnenavn_en']);
  $course_div =  array(
      '#type' => 'container',
      '#attributes' => array(
      'class' => "course",
    ),
    'header' => array(
       '#type' => 'html_tag',
       '#tag' => 'h3',
       '#value' => l($title .' ['.$course->data['emneid']['emnekode'].']', 'node/' . $course->nid),
    ),
  );

  if ($data['evu']['kurs']) {
    foreach ($data['evu']['kurs'] as $instance) {
      $course_div[] = uib_study__evu_instance($instance);
    }
  }
  else {
    $course_div['no_instances'] = array(
      '#markup' => t('There are currently no scheduled courses of this subject'),
    );
  }
  return $course_div;
}

/**
 * Parses EVU cource instance.
 *
 * @param array $instance
 *   Instance of EVU kurs to be parsed.
 *
 * @return array
 *   An render array with key EVU data.
 */
function uib_study__evu_instance($instance) {
  $idiv = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'instance'),
  );

  $tdiv = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'text'),
  );

  // Semester
  $today = date("c");
  $timecode = $instance['kursid']['tidkode'];
  $semester = (substr($timecode,0,1) == 'H' ? t('Autumn') : t('Spring'));
  $year = substr($timecode, 2);
  $tdiv['tidkode'] = array('#markup' => '<span class="title">' . $semester . ' ' . check_plain($year) . "</span>");

  // Course date
  if (isset($instance['dato_fra'])) {
    $tdiv['dates'] = array('#markup' => '<br />' .
      t('Course date: @start_date - @end_date', array (
        '@start_date'=> uib_study__evu_date($instance['dato_fra']),
        '@end_date' => uib_study__evu_date($instance['dato_til']),
      ))
    );
  }

  // Price
  $fee = t('Not set');
  if (isset($instance['kostnad'])) {
    if ($instance['kostnad'] === 0) {
      $fee = t('Free');
   }
   elseif ($instance['kostnad'] > 0) {
      $fee = t('NOK ' . $instance['kostnad']);
   }
  }
  $tdiv['fee'] = array('#markup' => '<br />' . t('Price: @fee', array('@fee' => $fee)));

  // Deadline && sing up button
  $expires = t('Expired');
  if (isset($instance['dato_frist_soknad'])) {
    if ($instance['dato_frist_soknad'] >= $today) {
      $expires = uib_study__evu_date($instance['dato_frist_soknad']);
      if (!empty($instance['url_evuweb'])) {
        $sdiv = array(
          '#type' => 'container',
          '#attributes' => array('class'=> 'sign-up'),
          'button' => array(
            '#type' => 'link',
            '#attributes' => array('class'=> 'sign-up-button'),
            '#href' => $instance['url_evuweb'],
            '#title' => t('Sign up'),
          ),
        );
      }
    }
  }
  $tdiv['deadline'] = array('#markup' => '<br />' . t('Application deadline: @deadline', array('@deadline' => $expires)));

  // Putting the pieces together
  $idiv['text'] = $tdiv;
  if (isset($sdiv))
    $idiv['sing-up'] = $sdiv;
  $idiv['clear'] = array('#markup' => '<div style="clear: both;"></div>');
  $div[$timecode] = $idiv;

  return $div;
}
