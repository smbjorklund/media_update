<?php
/**
 * @file
 * uib_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_calendar_views_api() {
  return array("version" => "3.0");
}
