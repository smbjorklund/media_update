<?php
/**
 * @file
 * uib_setup.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function uib_setup_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['en'] = array(
  'site_name' => 'University of Bergen',
  'site_slogan' => '',
);
  $realm_variables['language']['nb'] = array(
  'site_name' => 'Universitetet i Bergen',
  'site_slogan' => '',
);

return $realm_variables;
}
