<?php
/**
 * @file
 * uib_user.drush.inc
 */
function uib_user_drush_command() {
  $items['uib-user-clean'] = array(
    'description' => 'Manage blocked user accounts',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'limit' => 'The amount of time (in days) before the user is considered stale',
    ),
    'options' => array(
      'dry-run' => 'Do not make any changes',
    ),
  );

 return $items;
}

/**
 * Manage blocked users
 */
function drush_uib_user_clean($limit) {
  if (empty($limit)) {
    $limit = variable_get('uib_user_stale_limit', 365);
  }
  if (!is_numeric($limit)) {
    return FALSE;
  }
  if (drush_get_option('dry-run')) {
    $dry_run = TRUE;
  }
  else {
    $dry_run = FALSE;
  }

  // get all blocked users
  $result = db_query('SELECT uid, name, access FROM users WHERE status = :sta', array(':sta' => 0));
  $day = 86400;
  foreach ($result as $user) {
    if ($user->uid > 1) {

      // Remove aliases for stale users
      $since = (time() - $user->access) / $day;
      if ($since >= $limit) {
        $alias = uibx_path_load("user/$user->uid");
        if ($alias) {
          foreach ($alias as $a) {
            if ($dry_run) {
                uibx_log('Would have removed alias "' . $a->alias . '" for ' . $a->source . ' (' . $user->name . ')', 'notice');
            }
            else {
              path_delete($a->pid);
              uibx_log('Removed alias "' . $a->alias . '" for ' . $a->source . ' (' . $user->name . ')', 'notice');
            }
          }
        }
      }
    }
  }
}
