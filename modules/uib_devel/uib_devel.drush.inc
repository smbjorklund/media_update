<?php
/**
 * @file
 * @return [type] [description]
 */
function uib_devel_drush_command() {
  $items['uib-devel-fill-area'] = array(
    'description' => 'Fill all area content, /jur is the chosen area',
    'aliases' => array('uib-ac', ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-devel-create-content'] = array(
    'description' => 'Create content for /jur',
    'aliases' => array('uib-ct', ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_uib_devel_fill_area() {
  $path = drupal_get_normal_path('jur');
  $areaid =  explode('/', $path);
  if (is_numeric($areaid[1])){
    $area = node_load($areaid[1]); 

    $area->field_uib_feed['und'][0]['url'] = 'http://www.vg.no/rss/create.php?categories=20';
    $area->field_uib_feed['und'][0]['title'] = 'Siste fra VG-sporten';
    
    $area->field_uib_primary_text['und'][0]['value'] = '<h4>Primary</h4><p>Dignissim molestie luctus vel ligula consectetuer Nam maecenas pellentesque pellentesque class, cras sapien sociis aptent faucibus pharetra pede venenatis egestas eget sodales ac nulla quam. Nibh lacus ullamcorper. Aenean orci eros nostra magnis dictumst. Phasellus magnis cursus scelerisque, aenean ac urna class sodales integer platea praesent habitant praesent eget.</p>';
    $area->field_uib_primary_text['und'][0]['format'] =  'basic_html';
    $area->field_uib_secondary_text['und'][0]['value'] = '<h4>Secondary</h4><ul><li><a href="#">Fadderprogram</a></li><li><a href="#">Fagdag</a></li><li><a href="#">Forstesemesterstudie</a></li><li><a href="#">HSU-Studentutvalg</a></li><li><a href="#">Infosenteret</a></li></li><li><a href="#">Masterprogram</a></li></li><li><a href="#">Praktisk informasjon</a></li></li><li><a href="#">Semesterstart 2012</a></li></li><li><a href="#">Studiestartbrosjyre</a></li></ul>';
    $area->field_uib_secondary_text['und'][0]['format'] =  'basic_html'; 
    $area->field_uib_tertiary_text['und'][0]['value'] = '<h4>Tertiary</h4><p>Netus tempor. Iaculis placerat mus et ullamcorper dui integer habitasse magnis accumsan placerat tempus purus potenti sapien bibendum. Sapien enim duis semper proin pede quam. Netus, quam sociosqu enim nec ullamcorper habitant lectus nunc facilisis hendrerit sed phasellus conubia metus libero, suspendisse suspendisse porta vitae.</p>';
    $area->field_uib_tertiary_text['und'][0]['format'] = 'basic_html';
    $area->field_uib_bottom_text['und'][0]['value'] = '<h4>Bottom</h4><p>Curae;. Suscipit Fermentum senectus Vivamus montes eleifend Ullamcorper pede semper curae; morbi vehicula. Vestibulum. Volutpat sed ornare mi hendrerit ultrices vulputate a fusce magna erat litora molestie quisque placerat odio adipiscing, dui. Sollicitudin. Ipsum integer duis consectetuer commodo hac dui dapibus nec sociis quis dapibus bibendum porttitor ante sed primis.</p>';
    $area->field_uib_bottom_text['und'][0]['format'] = 'basic_html';

    //$area->field_uib_profiled_article['und'][0]['target_id'] =  'xx';
    //$area->field_uib_profiled_article['und'][1]['target_id'] =  'xx';
    //$area->field_uib_profiled_article['und'][2]['target_id'] =  'xx';
    //$area->field_uib_profiled_article['und'][3]['target_id'] =  'xx';
    node_save($area);
    drush_log('Filled area content for /jur');
  }
}

function drush_uib_devel_create_content() {
  $path = drupal_get_normal_path('jur');
  $areaid =  explode('/', $path);
  if (is_numeric($areaid[1])){
    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'En fint seminar om Jur';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'seminar';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s");
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Foredrag om Lasse';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'foredrag';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s", strtotime("+2 hour"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Vi synger julen inn';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'seminar';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s", strtotime("+4 hour"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Kunstutstilling';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'utstilling';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s");
    $node->field_uib_date['und'][0]['value2'] = date("Y-m-d H:i:s", strtotime("+1 week"));
    node_save($node);

    drush_log('Created 4 events for /jur');
  }
}