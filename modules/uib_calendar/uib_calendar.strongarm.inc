<?php
/**
 * @file
 * uib_calendar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uib_calendar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_day_and_month';
  $strongarm->value = 'd. F';
  $export['date_format_day_and_month'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_time';
  $strongarm->value = 'G:i';
  $export['date_format_time'] = $strongarm;

  return $export;
}
