<?php
/**
 * Removes aliases that point to user accounts that are
 * not the main user account for a real person.
 *
 * The main account is called "hoveduid" in Sebra speech,
 * and is checked by using a Sebra web service (by the
 * uib_sebra_user_is_main() function in the uib_sebra module)
 */
$result = db_query('SELECT uid, name, status FROM users');
foreach ($result as $user) {
  if ($user->uid > 1) {
    $is_main = uib_sebra_user_is_main($user->name);
    if (!$is_main) {
      if ($is_main === NULL) {
        $status = '';
        if ($user->status == 0) {
          $status = 'blocked ';
        }
        uibx_log('No data in Sebra for ' . $status . 'user ' . $user->name, 'notice');
      }
      else {
        // Remove alias(es)
        while ($alias = path_load("user/$user->uid")) {
          path_delete($alias['pid']);
          uibx_log('Removed alias "' . $alias['alias'] . '" for ' . $alias['source'] . ' (' . $user->name . ')', 'notice');
        }
      }
    }
  }
}
