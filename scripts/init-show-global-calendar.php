<?php

// The field_uib_show_global_calendar is new and this is run to
// make sure that the default value is set for all existing events.
$query = new EntityFieldQuery;
$query = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'uib_article')
  ->fieldCondition('field_uib_article_type', 'value', 'event', '=');
$result = $query->execute();
if (!empty($result['node'])) {
  $chunk = 1000;
  $node_list = array_keys($result['node']);
  $cnt = 0;
  while ($shortlist = array_splice($node_list, 0, $chunk)) {
    $events = entity_load('node', $shortlist);
    foreach ($events as $node) {
      $event = entity_metadata_wrapper('node', $node);
      if ($event->field_uib_show_global_calendar->value() != 1) {
        $event->field_uib_show_global_calendar->set(1);
        $event->save();
        $cnt++;
        uibx_log('Event nid:' . $event->getIdentifier() . ' set to show in global calendar', 'notice');
      }
    }
  }
  uibx_log('Fixed global calendar setting for ' . $cnt . ' out of ' . count($result['node']) . ' events', 'notice');
}
