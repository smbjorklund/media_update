<?php

// Fixes dates for
// Articles: event & phd_press_release

// Find migrated articles.
// Assumptions: If they are not edited they should still be in GMT,
//   but if they are edited, they are expected to be local timezone.
$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'uib_article')
  ->fieldCondition('field_uib_article_type', 'value', array('event', 'phd_press_release'))
  ->fieldCondition('field_uib_w2_id', 'value', '0', '>')
  ->execute();
if ($result) {
  $migrated_nids = array_keys($result['node']);
  foreach ($migrated_nids as $article_nid) {
    // Fix date if they have been edited
    $rez = db_query('SELECT field_uib_date_value
      FROM {field_revision_field_uib_date}
      WHERE bundle = :bnd AND entity_id = :nid AND field_uib_date_value > :nda',
      array(':nid' => $article_nid, ':bnd' => 'uib_article', ':nda' => '1800-01-01 00:00:00')
      );
    if ($rez->rowCount() > 1) {
      // This has been edited. Fixit.
      if (!fix_article_node_dates($article_nid)) {
        uibx_log('Unable to fix dates for [migrated] node/' . $article_nid, 'warning');
      }
    }
  }
}

// Find all articles created in w3
// Assume local datetime, convert to UTC in db

$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'uib_article')
  ->propertyCondition('nid', $migrated_nids, 'NOT IN')
  ->fieldCondition('field_uib_article_type', 'value', array('event', 'phd_press_release'))
  ->execute();
if ($result) {
  // Fix dates
  foreach (array_keys($result['node']) as $article_nid) {
    // Check if there is a date for this node
    $rez = db_query('SELECT field_uib_date_value
      FROM {field_data_field_uib_date}
      WHERE bundle = :bnd AND entity_id = :nid AND field_uib_date_value > :nda',
      array(':nid' => $article_nid, ':bnd' => 'uib_article', ':nda' => '1800-01-01 00:00:00')
      );
    if ($rez->rowCount() > 0) {
      if (!fix_article_node_dates($article_nid)) {
        uibx_log('Unable to fix dates for node/' . $article_nid, 'warning');
      }
    }
  }
}


/**
 * Convert a datetime string from one timezone to another
 * @param  string               $localoid  DateTime string to be converted
 * @param  DateTimeZone object  $from_tz   Timezone to convert from
 * @param  DateTimeZone object  $to_tz     Timezone to convert to
 * @return string                          Converted DateTime string
 */
function convert_date($localoid, $from_tz, $to_tz) {
  if (empty($localoid)) {
    return $localoid;
  }
  $datetime = new DateTime($localoid, $from_tz);
  $datetime->setTimeZone($to_tz);
  return $datetime->format('Y-m-d H:i:s');
}

/**
 * Fix dates for an article node
 * @param  integer  $nid  article node id
 */
function fix_article_node_dates($nid = NULL) {
  if (empty($nid)) {
    return FALSE;
  }
  $local_tz = new DateTimeZone('Europe/Oslo');
  $gmt_tz = new DateTimeZone('GMT');
  $article_node = node_load($nid);
  $article = entity_metadata_wrapper('node', $article_node);
  $date_assemblage = $article->field_uib_date->value();
  $changed = FALSE;
  if (!empty($date_assemblage['value'])) {
    $date_assemblage['value'] = convert_date($date_assemblage['value'], $local_tz, $gmt_tz);
    $changed = TRUE;
  }
  if (!empty($date_assemblage['value2'])) {
    $date_assemblage['value2'] = convert_date($date_assemblage['value2'], $local_tz, $gmt_tz);
    $changed = TRUE;
  }
  if ($changed) {
    $article->field_uib_date->set($date_assemblage);
    $article->save();
  }
  return TRUE;
}
