<?php

$uib_language = array('nb' => 'aktuelt', 'en' => 'news');
foreach ($uib_language as $lang => $path) {
  $path = drupal_get_normal_path($path, $lang);
  $areaid =  explode('/', $path);
  if (is_numeric($areaid[1])) {
    $area = node_load($areaid[1]);
    // Setup feed
    $area->field_uib_feed['und'][0]['url'] = 'http://rss.opoint.com/?username=uib_feed&password=2f663b1101cecbb1c79bd00fc9f70c1f&list_id=110496';
    $area->field_uib_feed['und'][0]['title'] = 'UiB i media';
    // Setup social icons
    $area->field_uib_social_media['und'][0]['value'] = 'twitter:uib';
    $area->field_uib_social_media['und'][1]['value'] = 'facebook:uib';
    $area->field_uib_social_media['und'][2]['value'] = 'youtube:uib';
    $area->field_uib_social_media['und'][3]['value'] = 'vimeo:uib';
    $area->field_uib_social_media['und'][4]['value'] = 'flickr:uib';

    // Get 9 node ids
    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'uib_article')
      ->propertyCondition('language', $lang)
      ->fieldCondition('field_uib_article_type','value', 'news', '=')
      ->fieldCondition('field_uib_area','target_id', $areaid[1], '=')
      ->propertyOrderBy('created', 'DESC')
      ->range(0, 9);
    $result = $query->execute();
    if (empty($result['node'])) {
      uibx_log('Can not load any nodes', 'error');
      continue;
    }
    $nids = array_keys($result['node']);
    // Setup profiled articles (the slide show)
    for ($i = 0; $i <= 3; $i++) {
      $area->field_uib_profiled_article['und'][$i]['target_id'] = $nids[$i];
    }
    // Setup profiled messages (other stuff)
    for ($i = 0; $i <= 4; $i++) {
      $area->field_uib_profiled_message['und'][$i]['target_id'] = $nids[$i+4];
    }
    node_save($area);
    // Setup relevant link (field collection)
    $values = array(
      'field_name' => 'field_uib_link_section',
      'field_uib_title' => array(
        LANGUAGE_NONE => array(array('value' => 'Aktuelle lenker')),
      ),
      'field_uib_links' => array(
        LANGUAGE_NONE => array(
          array('url' => '#','title' => 'Presserom'),
          array('url' => '#','title' => 'Offentleg journal'),
          array('url' => '#','title' => 'Ledige stillinger'),
          array('url' => '#','title' => 'Nye doktorgrader'),
          array('url' => '#','title' => 'Pressemeldinger'),
        ),
      ),
    );
    $entity = entity_create('field_collection_item', $values);
    $entity->setHostEntity('node', $area);
    $entity->save();
    // Another field collection
    $values = array(
      'field_name' => 'field_uib_link_section',
      'field_uib_title' => array(
        LANGUAGE_NONE => array(array('value' => 'Kalender - Det skjer')),
      ),
      'field_uib_links' => array(
        LANGUAGE_NONE => array(
          array('url' => '#','title' => 'Se hele kalenderen'),
        ),
      ),
    );
    $entity = entity_create('field_collection_item', $values);
    $entity->setHostEntity('node', $area);
    $entity->save();
    node_save($area);

    uibx_log('Aktuelt is setup','notice');
  }
  // Setup frontpage, tried with drupal_get_normal_path og variable_get. But didnt work.
  $query = new EntityFieldQuery;
  $query = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'area')
      ->fieldCondition('field_uib_area_type','value', 'frontpage', '=')
      ->propertyCondition('language', $lang)
      ->range(0, 1);
  $result = $query->execute();
  if (!empty($result['node'])) {
    $frontpage_nid = array_keys($result['node']);
    $frontpage = node_load($frontpage_nid[0]);
    // Setup profiled articles
    for ($i = 0; $i <= 3; $i++) {
      $frontpage->field_uib_profiled_article['und'][$i]['target_id'] = $nids[$i];
    }
    // Setup social icons
    $frontpage->field_uib_social_media['und'][0]['value'] = 'twitter:uib';
    $frontpage->field_uib_social_media['und'][1]['value'] = 'facebook:uib';
    $frontpage->field_uib_social_media['und'][2]['value'] = 'youtube:uib';
    $frontpage->field_uib_social_media['und'][3]['value'] = 'vimeo:uib';
    $frontpage->field_uib_social_media['und'][4]['value'] = 'flickr:uib';
    // Setup profiled messages, first news
    for ($i = 0; $i <= 2; $i++) {
      $frontpage->field_uib_profiled_message['und'][$i]['target_id'] = $nids[$i+4];
    }
    // Setup profiled messages, events
    $query = new EntityFieldQuery;
    $query = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'uib_article')
      ->propertyCondition('language', $lang)
      ->fieldCondition('field_uib_article_type','value', 'event', '=')
      ->propertyOrderBy('created', 'DESC')
      ->range(0, 3);
    $result = $query->execute();
    if (!empty($result['node'])) {
      $nids = array_keys($result['node']);
      for ($j = 0; $j <= 2; $j++) {
        $frontpage->field_uib_profiled_message['und'][$i]['target_id'] = $nids[$j];
        $i++;
      }
    }
    node_save($frontpage);
    uibx_log('Frontpage is setup','notice');
  }
}
