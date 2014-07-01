<?php

$sizes = array(0, 100, 500, 1000, 2000, 5000, 10000, 50000, 100000, 500000);
$count = array();

$rows = db_query('SELECT length(field_uib_text_value) FROM node AS n LEFT JOIN field_data_field_uib_text AS t ON nid = entity_id WHERE type = :type AND status = 1', array('type' => 'uib_article'));
foreach($rows as $row) {
  $size = $row->length;
  if ($size === NULL)
    $size = 0;
  for ($i = 0; $i < count($sizes); $i++) {
    if ($size <= $sizes[$i])
      break;
  }
  @$count[$i]++;
}

for ($i = 0; $i < count($sizes); $i++) {
  @printf("<= %6d %6d\n", $sizes[$i], $count[$i]);
}
@printf(">  %6d %6d\n", $sizes[count($sizes)-1], $count[count($sizes)]);

