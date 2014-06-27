<?php

$node = node_load(55476);
$test_str = $node->field_uib_text['und'][0]['value'];

#$test_str = substr($test_str, 65536+32768+16384);
#$test_str = 'GEO ';

$size = 512;
$last_dur = 0;
while ($size < 1024*1024*2) {
  $before = microtime(true);

  # do stuff
  $text = str_repeat($test_str, $size/strlen($test_str));
  if (strlen($text) < $size) {
    $text .= substr($test_str, 0, $size - strlen($text));
  }

  $filtered = uib_study__filter_text($text);

  # report on time
  $dur = microtime(true) - $before;
  printf("%8d %7.3f", strlen($text), $dur);
  if ($last_dur) {
    printf(" %4.1fx", $dur/$last_dur);
  }
  print "\n";

  $size = $size*2;
  $last_dur = $dur;
}
