<?php
/**
 * @file
 * @return [type] [description]
 */
function uib_devel_drush_command() {
  $items['uib-fill-area'] = array(
    'description' => 'Fill /jur area fields with content',
    'aliases' => array('uib-ac', ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-create-content'] = array(
    'description' => 'Create content for /jur',
    'aliases' => array('uib-ct', ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_uib_devel_uib_fill_area() {
  $path = drupal_get_normal_path('jur');
  $areaid =  explode('/', $path);
  if (is_numeric($areaid[1])){
    $area = node_load($areaid[1]);

    $area->field_uib_feed['und'][0]['url'] = 'http://www.vg.no/rss/create.php?categories=20';
    $area->field_uib_feed['und'][0]['title'] = 'Siste fra VG-sporten';

    $area->field_uib_primary_text['und'][0]['value'] = '<h4>Primary</h4><p>Dignissim molestie luctus vel ligula consectetuer Nam maecenas pellentesque pellentesque class, cras sapien sociis aptent faucibus pharetra pede venenatis egestas eget sodales ac nulla quam. Nibh lacus ullamcorper. Aenean orci eros nostra magnis dictumst. Phasellus magnis cursus scelerisque, aenean ac urna class sodales integer platea praesent habitant praesent eget.</p>';
    $area->field_uib_primary_text['und'][0]['format'] =  'restricted_html';
    $area->field_uib_secondary_text['und'][0]['value'] = '<h4>Secondary</h4><ul><li><a href="#">Fadderprogram</a></li><li><a href="#">Fagdag</a></li><li><a href="#">Forstesemesterstudie</a></li><li><a href="#">HSU-Studentutvalg</a></li><li><a href="#">Infosenteret</a></li></li><li><a href="#">Masterprogram</a></li></li><li><a href="#">Praktisk informasjon</a></li></li><li><a href="#">Semesterstart 2012</a></li></li><li><a href="#">Studiestartbrosjyre</a></li></ul>';
    $area->field_uib_secondary_text['und'][0]['format'] =  'restricted_html';
    $area->field_uib_tertiary_text['und'][0]['value'] = '<h4>Tertiary</h4><p>Netus tempor. Iaculis placerat mus et ullamcorper dui integer habitasse magnis accumsan placerat tempus purus potenti sapien bibendum. Sapien enim duis semper proin pede quam. Netus, quam sociosqu enim nec ullamcorper habitant lectus nunc facilisis hendrerit sed phasellus conubia metus libero, suspendisse suspendisse porta vitae.</p>';
    $area->field_uib_tertiary_text['und'][0]['format'] = 'restricted_html';
    $area->field_uib_bottom_text['und'][0]['value'] = '<h4>Bottom</h4><p>Curae;. Suscipit Fermentum senectus Vivamus montes eleifend Ullamcorper pede semper curae; morbi vehicula. Vestibulum. Volutpat sed ornare mi hendrerit ultrices vulputate a fusce magna erat litora molestie quisque placerat odio adipiscing, dui. Sollicitudin. Ipsum integer duis consectetuer commodo hac dui dapibus nec sociis quis dapibus bibendum porttitor ante sed primis.</p>';
    $area->field_uib_bottom_text['und'][0]['format'] = 'restricted_html';

    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'uib_article')
      ->propertyCondition('language', 'nb')
      ->fieldCondition('field_uib_article_type','value', 'news', '=')
      ->range(0, 5);
    $result = $query->execute();
    if(!empty($result['node'])){
      foreach($result['node'] as $news){
        $area->field_uib_profiled_article['und'][]['target_id'] = $news->nid;
      }
    }

    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'uib_testimonial')
      ->propertyCondition('language', 'nb')
      ->range(0, 1);
    $result = $query->execute();
    if(!empty($result['node'])){
      $area->field_uib_profiled_testimonial['und'][]['target_id'] = current($result['node'])->nid;
    }

    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'file')
      ->propertyCondition('type', 'image')
      ->range(0, 1);
    $result = $query->execute();
    if(!empty($result['file'])){
      $area->field_uib_bottom_media['und'][0] = array(
        'fid' => current($result['file'])->fid,
        'display' => 1,
      );
    }


    node_save($area);
    drush_log('Filled area content for /jur');
  }
}

function drush_uib_devel_uib_create_content() {
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
    $node->field_uib_date['und'][0]['value2'] = date("Y-m-d H:i:s", strtotime("+4 hour"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Foredrag om Lasse';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'lecture';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s", strtotime("+2 hour"));
    $node->field_uib_date['und'][0]['value2'] = date("Y-m-d H:i:s", strtotime("+6 hour"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Vi synger julen inn';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'seminar';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s", strtotime("+4 hour"));
    $node->field_uib_date['und'][0]['value2'] = date("Y-m-d H:i:s", strtotime("+14 hour"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'Kunstutstilling';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'event';
    $node->field_uib_event_type['und'][0]['value'] = 'exhibition';
    $node->field_uib_date['und'][0]['value'] = date("Y-m-d H:i:s");
    $node->field_uib_date['und'][0]['value2'] = date("Y-m-d H:i:s", strtotime("+1 week"));
    node_save($node);

    $node = new stdClass;
    $node->type = 'uib_article';
    $node->title = 'En artikkel med alle felt';
    $node->language = 'nb';
    $node->field_uib_area['und'][0]['target_id'] = $areaid[1];
    $node->field_uib_article_type['und'][0]['value'] = 'news';
    $node->field_uib_lead['und'][0]['value'] = 'Dignissim molestie luctus vel ligula consectetuer Nam maecenas pellentesque pellentesque class, cras sapien sociis aptent faucibus pharetra pede venenatis egestas eget';
    $node->field_uib_kicker['und'][0]['value'] = 'SFF2012';
    $node->field_uib_fact_box['und'][0]['value'] = 'Fakta om saken';
    $node->field_uib_text['und'][0]['value'] = 'Dignissim molestie luctus vel ligula consectetuer Dignissim molestie luctus vel ligula consectetuer Dignissim molestie luctus vel ligula consectetuer Dignissim molestie luctus vel ligula consectetuer Dignissim molestie luctus vel ligula consectetuer Dignissim molestie luctus vel ligula consectetuer';

    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'file')
      ->propertyCondition('type', 'image')
      ->range(0, 1);
    $result = $query->execute();
    if(!empty($result['file'])){
      $node->field_uib_main_media['und'][0] = array(
        'fid' => current($result['file'])->fid,
        'display' => 1,
      );
      $node->field_uib_media['und'][0] = array(
        'fid' => current($result['file'])->fid,
        'display' => 1,
      );
    }
    node_save($node);

    drush_log('Created 4 events and 1 news for /jur');
  }
}
