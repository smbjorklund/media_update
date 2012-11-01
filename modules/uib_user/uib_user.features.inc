<?php
/**
 * @file
 * uib_feature_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_feature_user_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
