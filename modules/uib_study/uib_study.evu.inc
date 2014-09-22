<?php

function uib_study__evu_courses_page(){
  $page = array(
    'form' => drupal_get_form('uib_study__evu_courses_page_form'),
    'list' => uib_study__evu_courses_page_list(),
  );
  return $page;
}

function uib_study__evu_courses_page_form($form, &$form_state){
  $form['semesters'] = array(
    '#type' => 'checkboxes',
    '#options' => array('autumn' => t('Autumn'),'spring'=> t('Spring')),
    '#title' => t('Filter by Semester'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
  );
  return $form;
}

function uib_study__evu_courses_page_form_submit ($form, &$form_state){
  $form_semesters = $form_state['values']['semesters'];
  $form_state['storage']['semesters'] = $form_semesters;
  $form_state['rebuild'] = TRUE;

  global $semester;
  if ($form_semesters['autumn'] && !$form_semesters['spring']){
    $semester = 'H';
  }
  elseif(!$form_semesters['autumn'] && $form_semesters['spring']){
    $semester = 'V';
  }
  else{
    $semester = FALSE;
  }
}

/**
 * Creates a page with a list of evu coursed
 */
function uib_study__evu_courses_page_list() {
  global $language;

  $today = date("c");
  $main = array();

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
    $main['no_results'] = array(
      '#type' => 'container',
      '#attributes' => array( ),
      'header' => uib_study__evu_html_tag('p', t('No EVU courses found')),
    );
    return $main;
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
    ->propertyCondition('language', $language->language)
    ->propertyCondition('status', 1)
    ->fieldCondition('field_uib_article_type', 'value', 'evu_study_offer')
    ->propertyOrderBy('title', 'ASC')
    ->execute();

  $listed = array();

  $main['count'] = uib_study__evu_div_clear();
  // List all evu_study_offer and their evu courses
  if ($results) {
    $offers = node_load_multiple(array_keys($results['node']));
    // For each offer (article)
    foreach ($offers as $nid => $offer) {
      // If the article has related articles (courses)
      if (!empty ($offer->field_uib_relation['und'])) {
        $course_ids = array_map('current', $offer->field_uib_relation['und']);
        $listed = array_merge ($listed, $course_ids);
        $main[$nid] = uib_study__evu_courses_list($offer, $course_ids, $evus);
      }
    }
  }

  // List all evu courses not in an evu_study_offer
  if (sizeof($listed) < sizeof($evus)) {
    $div = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => "uib-study-evu-offer",
      ),
      'header' => uib_study__evu_html_tag('h2', t('Other EVU courses')),
      'list' => array(
        '#items' => array(),
        '#theme' => 'item_list',
      ),
    );
    foreach ($evus as $nid => $evu) {
      if (!array_search($nid, $listed))  {
        $div['list']['#items'][] = drupal_render(uib_study__evu_course($evus[$nid]));
      }
    }
    $main['orfans'] = $div;
  }

  // Force EVU as the current area for this page.
  uib_area__get_current(77320);

  return $main;
}

function uib_study__evu_courses_list($offer, $course_ids, $evus) {
  global $semester;
  $output = array();
  $offer_added = FALSE;

  foreach ($course_ids as $course_id) {
    // If it is an evu curs
    if (!empty($evus[$course_id])){
      $div_course = uib_study__evu_course($evus[$course_id]);
      if (!$semester || $div_course) {
        // Prevents empty offers from being listed
        if (!$offer_added){
          $offer_added = TRUE;
          $output = array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => "uib-study-evu-offer",
            ),
            'header' => uib_study__evu_html_tag('h2', l($offer->title, 'node/' . $offer->nid)),
            'lead_text'=> array(),
            'list' => array(
              '#items' => array(),
              '#theme' => 'item_list',
            )
          );
          if (isset($offer->field_uib_lead['und'])) {
            $output['lead_text'] = uib_study__evu_html_tag('p', $offer->field_uib_lead['und'][0]['safe_value'], 'lead-text');
          }
        }
        $output['list']['#items'][] = drupal_render($div_course);
      }
    }
  }
  return $output;
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
 * @param object $course The course node with a field "data" containing the
 * fs_press information
 *
 * @return array Return a drupal render array with the course information
 */

function uib_study__evu_course($course) {
  global $language;
  global $semester;
  $data = $course->data;
  $title = ($language->language == 'nb' ? $data['emnenavn'] : $data ['emnenavn_en']);
  $course_div =  array(
      '#type' => 'container',
      '#attributes' => array(
      'class' => "course",
    ),
    'header' => uib_study__evu_html_tag('h3',
      l($data['emneid']['emnekode'].' / ' . $title , 'node/' . $course->nid)
    ),
    'study_points' => uib_study__evu_html_tag('p',
      t('Study points: @study_points', array('@study_points' => $data['studiepoeng'])), 'course-info'
    ),
  );
  $has_instances = FALSE;
  if ($data['evu']['kurs']) {
    if (!$semester) {
      $has_instances = TRUE;
      foreach ($data['evu']['kurs'] as $instance) {
        $course_div[] = uib_study__evu_instance($instance);
      }
    }
    else {
      foreach ($data['evu']['kurs'] as $instance) {
        if (uib_study__evu_instance_on_semester($instance, $semester)) {
          $course_div[] = uib_study__evu_instance($instance);
          $has_instances = TRUE;
        }
      }
    }
  }

  if (!$has_instances) {
    if ($semester) {
      return FALSE;
    }
    else{
      $course_div['no_instances'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => "no_instances",
        ),
        'no_instances' => uib_study__evu_html_tag('p', t('There are currently no scheduled courses of this subject')),
      );
    }
  }
  return $course_div;
}

function uib_study__evu_instance_on_semester($instance, $semester) {
  $ins_semester = substr($instance['kursid']['tidkode'], 0, 1);
  return $ins_semester == $semester;
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
    '#attributes' => array('class' => 'instance-info'),
  );

  // Semester
  $today = date("c");
  $timecode = $instance['kursid']['tidkode'];
  $sem = (substr($timecode, 0, 1) == 'H' ? t('Autumn') : t('Spring'));
  $year = substr($timecode, 2);
  $tdiv['tidkode'] = uib_study__evu_html_tag('span', $sem . ' ' . check_plain($year), 'semester');

  // Course date
  if (isset($instance['dato_fra'])) {
    $tdiv['dates'] = array(
      'br' => array('#markup' => '<br />'),
      'title' => uib_study__evu_html_tag('span', t('Course date') . ': ', 'title'),
      'text'=>uib_study__evu_html_tag('span', uib_study__evu_date($instance['dato_fra']) .' - '.
        uib_study__evu_date($instance['dato_til'])),
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
  $tdiv['fee'] = array(
    'br' =>array('#markup' => '<br />'),
    'title' => uib_study__evu_html_tag('span', t('Price') . ': ', 'title'),
    'text' => uib_study__evu_html_tag('span', $fee)
  );

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
  $tdiv['deadline'] = array(
    'br' =>array('#markup' => '<br />'),
    'title' => uib_study__evu_html_tag('span', t('Application deadline') . ': ', 'title'),
    'text' => uib_study__evu_html_tag('span', $expires)
  );

  // Putting the pieces together
  $idiv['text'] = $tdiv;
  if (isset($sdiv))
    $idiv['sing-up'] = $sdiv;
  $idiv['clear'] = uib_study__evu_div_clear();
  $div[$timecode] = $idiv;

  return $div;
}

function uib_study__evu_html_tag ($type, $value, $classes = '') {
  $output = array(
    '#type' => 'html_tag',
    '#tag' => $type,
    '#value' => $value,
  );
  if($classes != '')
    $output['#attributes'] = array('class' => $classes);
  return $output;
}

function uib_study__evu_div_clear() {
return array(
    '#type' => 'container',
    '#attributes' => array('class'=>'clear'),
    'num_offered' => uib_study__evu_html_tag('p',''),
  );
}
