<?php
$mapping = array(
  // 'arbeidsfelt-2' // joined with forskningsfelt
  // 'arbeidsfelt-2:' // joined with forskningsfelt:
  'forskningsfelt' => array('field' => 'field_uib_user_field', 'language' => 'nb', 'format' => 'value',),
  'forskningsfelt:' => array('field' => 'field_uib_user_field', 'language' => 'en', 'format' => 'value',),
  'hjemmeside' => array('field' => 'field_uib_user_url', 'format' => 'url',),
  // 'lenke' // treated as hjemmeside
  'besoksadresse:' => array('field' => 'field_uib_user_alt_address', 'format' => 'thoroughfare',),
  'fagomrade_cv' => array('field' => 'field_uib_user_opt_content', 'language' => 'nb', 'format' => 'value',),
  'fagomrade_cv:' => array('field' => 'field_uib_user_opt_content', 'language' => 'en', 'format' => 'value',),
  'prosjekter' => array('field' => 'field_uib_user_projects', 'language' => 'nb', 'format' => 'value',),
  'prosjekter:' => array('field' => 'field_uib_user_projects', 'language' => 'en', 'format' => 'value',),
  'publikasjoner' => array('field' => 'field_uib_user_publications', 'language' => 'nb', 'format' => 'value',),
  'publikasjoner:' => array('field' => 'field_uib_user_publications', 'language' => 'en', 'format' => 'value',),
  'undervisning-2' => array('field' => 'field_uib_user_teaching', 'language' => 'nb', 'format' => 'value',),
  'undervisning-2:' => array('field' => 'field_uib_user_teaching', 'language' => 'en', 'format' => 'value',),
  'funksjon' => array('field' => 'field_uib_user_alt_position', 'language' => 'nb', 'format' => '',),
  'funksjon:' => array('field' => 'field_uib_user_alt_position', 'language' => 'en', 'format' => '',),
  'romnummer' => array('field' => 'field_uib_user_room', 'format' => '',),
  // 'rss-tittel' // handled with rssurl
  'rssurl' => array('field' => 'field_uib_user_feed', 'format' => 'url',),
  );
// Some default texts
$opt_title_nb = t('Kompetanse');
$opt_title_en = t('Qualifications');
$default_country = 'NO';
$default_town = t('Bergen');
$default_rss_title = t('RSS feed');

$updated_count = 0;
// Get all local users
$query = new EntityFieldQuery();
$result = $query->entityCondition('entity_type', 'user')
  ->execute();
if (!empty($result['user'])) {
  $user_list = array_keys($result['user']);
  $user_count = count($user_list);
  $chunk = 2500;
  while ($subset = array_splice($user_list, 0, $chunk)) {
    $users = entity_load('user', $subset);
    foreach ($users as $entity) {
      $edit = FALSE;
      $wrapper = entity_metadata_wrapper('user', $entity);
      if ($wrapper->getIdentifier() > 1) {
        $name = $wrapper->name->value();
        if (!stripos($name, 'stub for')) {
          try {
            // Get user data from w2
            $w2user = new XTopic("username:$name");
          }
          catch (Exception $e) {
            uibx_log('Unable to fetch user data for "' . $name . '" from w2');
            // try next user
            continue;
          }
          $w2u = (array) $w2user;
          // Remove w2 scope from field names (but keep the colon)
          foreach ($w2u as $field => $value) {
            if (strpos($field, ':')) {
              $stripped_field = substr($field, 0, (strpos($field, ':') + 1));
              unset($w2u[$field]);
              $w2u[$stripped_field] = $value;
            }
          }
          // Some data get special treatment
          if (empty($w2u['hjemmeside']) && !empty($w2u['lenke'])) {
            // Use home page mapping
            $w2u['hjemmeside'] = $w2u['lenke'];
          }
          if (!empty($w2u['hjemmeside']) && !valid_url($w2u['hjemmeside'])) {
            unset($w2u['hjemmeside']);
          }
          if (!empty($w2u['rssurl'])) {
            if (!valid_url($w2u['rssurl'])) {
              unset($w2u['rssurl']);
            }
            elseif (empty($w2u['rss-tittel'])) {
              // Set a default title of RSS feed if it is missing
              $w2u['rss-tittel'] = $default_rss_title;
            }
          }
          // Join research/work fields
          if (empty($w2u['forskningsfelt'])) {
            if (!empty($w2u['arbeidsfelt-2'])) {
              $w2u['forskningsfelt'] = $w2u['arbeidsfelt-2'];
            }
          }
          elseif (!empty($w2u['arbeidsfelt-2'])) {
            $w2u['forskningsfelt'] .= PHP_EOL . $w2u['arbeidsfelt-2'];
          }
          if (empty($w2u['forskningsfelt:'])) {
            if (!empty($w2u['arbeidsfelt-2:'])) {
              $w2u['forskningsfelt:'] = $w2u['arbeidsfelt-2:'];
            }
          }
          elseif (!empty($w2u['arbeidsfelt-2:'])) {
            $w2u['forskningsfelt:'] .= PHP_EOL . $w2u['arbeidsfelt-2:'];
          }
          foreach ($mapping as $field => $map) {
            if (!empty($w2u[$field])) {
              $target = $map['field'];
              if (!empty($map['format'])) {
                if ($map['format'] == 'value') {
                  $w2u[$field] = array(
                    $map['format'] => check_markup($w2u[$field], 'restricted_html'),
                    'format' => 'restricted_html',
                    );
                }
                else {
                  $w2u[$field] = array($map['format'] => $w2u[$field]);
                }
              }
              if (isset($map['language'])) {
                $wrapper->language($map['language'])->$target->set($w2u[$field]);
                $edit = TRUE;
              }
              else {
                $wrapper->$target->set($w2u[$field]);
                $edit = TRUE;
              }
              // Add title for rss feed
              if ($field == 'rssurl') {
                $wrapper->field_uib_user_feed->title->set($w2u['rss-tittel']);
              }
              // Add default title for data migrated into optional field
              if ($field == 'fagomrade_cv') {
                $wrapper->language('nb')->field_uib_user_opt_title->set($opt_title_nb);
              }
              if ($field == 'fagomrade_cv:') {
                $wrapper->language('en')->field_uib_user_opt_title->set($opt_title_en);
              }
              // Add default country and town to alternate address
              if ($field == 'besoksadresse:') {
                $wrapper->$target->country->set($default_country);
                $wrapper->$target->locality->set($default_town);
              }
            }
          }
        }
        else {
          uibx_log('Ignoring user "' . $name . '" uid=' . $entity->uid);
        }
      }
      else {
        uibx_log('Ignoring user "' . $name . '" uid=' . $entity->uid);
      }
      if ($edit) {
        $wrapper->save();
        if (empty($wrapper->field_uib_w2_id->value())) {
          uibx_log('Note that user "' . $name . '" uid=' . $entity->uid . ' lacks w2-id');
        }
        $updated_count++;
      }
    }
  }
}
uibx_log('Updated data for ' . $updated_count . ' user(s) out of ' . $user_count);
