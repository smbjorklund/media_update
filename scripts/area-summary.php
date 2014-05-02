<?php

# Script that lists all the areas in the system with counts for how many
# articles there are of various types

$areas = array();
$articles = array();

# gather data
$result = db_query("SELECT nid, language, status, title, created FROM {node} WHERE type='area' ORDER BY nid");
foreach ($result as $row) {
  $row->articles = array();
  $areas[$row->nid] = $row;
}

$result = db_query("SELECT nid, language, status, title, created FROM {node} WHERE type='uib_article' ORDER BY nid");
foreach ($result as $row) {
  $articles[$row->nid] = $row;
}

$result = db_query("SELECT * from {field_data_field_uib_article_type} WHERE bundle='uib_article' ORDER BY entity_id");
foreach ($result as $row) {
  $articles[$row->entity_id]->type = $row->field_uib_article_type_value;
}

$result = db_query("SELECT * from {field_data_field_uib_area} WHERE bundle='uib_article' AND delta=0 ORDER BY entity_id");
foreach ($result as $row) {
  $area_nid = $row->field_uib_area_target_id;
  if (empty($areas[$area_nid])) {
    uibx_log("Article node/$row->entity_id references non-existing area $area_nid", 'error');
    continue;
  }
  $areas[$area_nid]->articles[$row->entity_id] = $articles[$row->entity_id];
}

# output info
$new_news_limit = time() - 12*7*24*60*60;

foreach ($areas as $nid => $area) {
  print "node/$nid st=$area->status";
  $counters = array(
    'articles' => count($area->articles), 'event' => 0, 'infopage'=> 0, 'news' => 0, 'new_news' => 0,
  );
  foreach ($area->articles as $art) {
    if (!array_key_exists($art->type, $counters)) {
      $counters[$art->type] = 0;
    }
    $counters[$art->type]++;
    if ($art->type == 'news' && $art->created > $new_news_limit)
      $counters['new_news']++;
  }
  foreach ($counters as $type => $count) {
    print " $type=$count";
  }
  print " $area->title\n";
}
