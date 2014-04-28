<?php
/**
 * @file
 * uib_dbh.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_dbh_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
