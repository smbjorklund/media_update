<?php

/**
 *  This will update all events to set to show on global calendar
 */

$query = new EntityFieldQuery;
$query = $query
     ->entityCondition('entity_type', 'node')
     ->propertyCondition('type', 'uib_article')
     ->fieldCondition('field_uib_article_type', 'value', 'event', '=');
$result = $query->execute();
if (!empty($result['node'])) {
  foreach (array_keys($result['node']) as $nid) {
    $node = node_load($nid);
    $node->field_uib_show_global_calendar['und'][0]['value'] = 1;
    node_save($node);
    print "The node with nid:$node->nid was set to show on global calendar\n";
  }
}
