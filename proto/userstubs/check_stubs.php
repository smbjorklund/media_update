<?php
/**
 * @file
 *  Fix for user stub remnants
 */
define('DRUPAL_ROOT', getcwd());
//define('DRUPAL_ROOT', '/home/ter062/www/w3.uib.no/drupal');
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$be_verbose = TRUE; // Info is displayed along the way if set to TRUE
// book-keeping
$stub_cnt = 0;
$corresponding_users = 0;
$nodes_found = 0;
$fixed_node_cnt = 0;
$node_contacts_found = 0;
$fixed_node_contacts_cnt = 0;
$deleted_stubs = 0;
$w2_fails = 0;
$fixed_users = array();

//  Get all users that are user stubs
$result = db_select('users', 'f')
  ->fields('f', array('uid', 'name'))
  ->condition('name', "User stub%", 'LIKE')
  ->execute();

if (isset($result)) {
  $stub_cnt = $result->rowCount();
  foreach ($result as $record) { //  For each user stub
    // Obtain necessary information: stub uid, w2 id, username (ask w2 for this)
    $tmp = explode(" ", $record->name); // disentangle stub w2 id from stub name
    $w2_id = trim($tmp[3]);
    unset($w2u);
    try {
      $w2u = new XTopic($w2_id); // Get uib user name for this user from w2
    }
    catch (Exception $e) {
      $w2_fails++;
      continue; // can't go any further if user name can't be looked up
    }
    if (empty($w2u->{'uib-id'})) {
      $w2_fails++;
      continue; // can't go any further if user name can't be looked up
    }
    $uib_user_name = $w2u->{'uib-id'}; // uib-id needs to be accessed in this particular way because the name includes a dash.

    // Get local user with this username and its uid, if present
    $usrez = db_select('users', 'f')
      ->fields('f', array('uid'))
      ->condition('name', $uib_user_name, '=')
      ->execute();

    unset($local_user);
    if (isset($usrez)) {
      foreach ($usrez as $local_user) {
      }
      if (!empty($local_user->uid)) {

        $corresponding_users++;
        if ($be_verbose) {
          echo "Stub [uid = $record->uid with w2 id = $w2_id] info should be merged with user $uib_user_name [uid = $local_user->uid]...<br>", PHP_EOL;
        }
        //    Find all node content connected to the stub user
        //    Bundles (content types): area, uib_article, uib_ou, uib_study, uib_testimonial

        $or_conditions = db_or(); // Since db_select defaults to AND, we need a OR condition first
        $or_conditions->condition('type', 'area', '=');
        $or_conditions->condition('type', 'uib_article', '=');
        $or_conditions->condition('type', 'uib_ou', '=');
        $or_conditions->condition('type', 'uib_study', '=');
        $or_conditions->condition('type', 'uib_testimonial', '=');

        // find node->uid from stub uid to user uid
        $contrez = db_select('node', 'f')
          ->fields('f', array('nid'))
          ->condition('uid', $record->uid, '=')
          ->condition($or_conditions)
          ->execute();

        if (isset($contrez)) {
          $nodes_found += $contrez->rowCount();
          if ($be_verbose) {
            if ($contrez->rowCount() > 0) {
              echo "--- " . $contrez->rowCount() . " nodes need to be fixed...<br>", PHP_EOL;
            }
            else {
              echo "--- no nodes to fix<br>", PHP_EOL;
            }
          }
        }
        // Find  content of type uib_article where contacts is connected to stub user
        // field_data_field_uib_contacts -> field_uib_contacts_target_id from stub user uid to user uid
        $query = db_select('node','f');
        $query->join('field_data_field_uib_contacts', 'fc', 'fc.entity_id = f.nid');
        $query->fields('f', array('nid'));
        $query->condition('fc.field_uib_contacts_target_id', $record->uid, '=');
        $query->condition('f.type', 'uib_article', '=');
        $contrez = $query->execute();

        if (isset($contrez)) {
          $node_contacts_found += $contrez->rowCount();
          if ($be_verbose) {
            if ($contrez->rowCount() > 0) {
              echo "--- " . $contrez->rowCount() . " contacts need to be fixed...<br>", PHP_EOL;
            }
            else {
              echo "--- no contacts to fix<br>", PHP_EOL;
            }
          }
        }
        $fixed_users[$local_user->uid] = $uib_user_name;
      }
    }
  } //  End foreach user stub
}

// done
if ($be_verbose) {
  echo "Number of user stubs found: $stub_cnt, of which $corresponding_users corresponded to existing users.<br>";
  if ($w2_fails > 0) {
    echo "Number of w2 lookup failures: $w2_fails<br>";
  }
  if ($corresponding_users > 0) {
    echo "Number of relevant nodes found: $nodes_found<br>";
    echo "Number of relevant contacts in articles found: $node_contacts_found<br>";
    echo "Users to merge:<br>";
    foreach ($fixed_users as $fuid => $fu) {
      echo "$fu [$fuid]<br>";
    }
  }
}
