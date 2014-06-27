<?php
/**
 * Removes all but the last of area aliases listed by uib_area__list_area_aliases()
 * and all duplicates.
 */
$prev_src = '';
$prev_language = '';
$prev_alias = '';
$cnt = 0;
$rmcnt = 0;
$uib_area_aliases = uib_area__list_area_aliases();
foreach ($uib_area_aliases as $key => $value) {
  $uib_area_aliases[$key] = trim($value, '/');
}
$result = db_query('SELECT pid, source, alias, language FROM {url_alias} ORDER BY source, language, pid DESC');
foreach ($result as $alias) {
  $cnt++;
  if ($alias->source == $prev_src && $alias->alias == $prev_alias && $alias->language == $prev_language) {
    path_delete($alias->pid);
    $rmcnt++;
  }
  elseif ($alias->source == $prev_src && $alias->language == $prev_language) {
    $prev_alias = $alias->alias;

    // Check if one of special area aliases
    $tmp = explode('/', $alias->source);
    if (array_shift($tmp) == 'node') {
      if (is_numeric(array_shift($tmp))) {
        if (in_array(implode('/', $tmp), $uib_area_aliases)) {
          uibx_log("removed: $alias->source <= $alias->alias [$alias->language]");
          path_delete($alias->pid);
          $rmcnt++;
        }
      }
    }
  }
  else {
    $prev_src = $alias->source;
    $prev_language = $alias->language;
    $prev_alias = $alias->alias;
  }
}
uibx_log("Removed $rmcnt of $cnt aliases");
