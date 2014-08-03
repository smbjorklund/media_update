<?php

# This script outputs the UiB module dependencies in the GraphViz dot
# language.  The dot command can be used to convert it to a picture.

print "digraph {\n";
print "  rankdir=LR;\n";
print "  node [shape=box, padding=0, fontname=Helvetica];\n";

foreach(system_get_info('module') as $module => $info) {
  if (substr($module, 0, 3) != 'uib')
    continue; // skip all non-uib modules
  if ($module == 'uib')
    continue; // skip the profile module

  $short_name = $module;
  if (substr($short_name, 0, 4) == 'uib_')
    $short_name = substr($short_name, 4);
  print "  $module [label=\"$short_name\"];\n";

  foreach ($info['dependencies'] as $dep) {
    if (substr($dep, 0, 3) != 'uib')
      continue;
    if ($dep == 'uibx')
      continue;
    print "  $module -> $dep;\n";
  }
}

print "}\n";
