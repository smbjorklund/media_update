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
  'site_slogan' => '',
  'site_name' => 'University of Bergen',
);
  $realm_variables['language']['nb'] = array(
  'site_slogan' => '',
  'site_name' => 'Universitetet i Bergen',
);

return $realm_variables;
}
