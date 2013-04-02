<?php
/**
 * @file
 * uib_area.drush.inc
 * @return [type] [description]
 */
function uib_area_drush_command() {
  $items['uib-area-connect-ou'] = array(
    'description' => 'Traversal of areas to connect missing organisational units',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );

  return $items;
}

/**
 * Update area nodes that lack OU indication
 * with a relevant parental OU.
 *
 * It is possible to set an option --dry-run
 * If dry-run is set, nodes are checked and some output is given,
 * but nothing is changed. Note that you may want to combine the
 * dry-run option with --strict=0 --verbose.
 */
function drush_uib_area_connect_ou() {
  $dry_run = FALSE;
  if (drush_get_option('dry-run')) {
    $dry_run = TRUE;
  }
  // Find area nodes that lack OU.
  // Done in two steps as EntityFieldQuery lacks NotExists in D7.

  // Find all area nodes in which OU is set.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area')
    ->fieldCondition('field_uib_ou', 'target_id', 0, '>');
  $result = $query->execute();
  $with_ou = array();
  if ($result) {
    foreach($result['node'] as $node) {
      $with_ou[] = $node->nid;
    }
    // Get all the other area nodes, i.e. those that lack OU
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'area')
      ->entityCondition('entity_id', $with_ou, 'NOT IN');
    $result2 = $query->execute();
    if ($result2) {
      $nodes = entity_load('node', array_keys($result2['node']));
      foreach($nodes as $node) {
        if ($dry_run) {
          uibx_log("Checking OU of node $node->nid ...", "notice");
        }
        $ou_nid = uib_area__get_ou_nid($node);
        if (!empty($ou_nid)) {
          $node->field_uib_ou['und'][]['target_id'] = $ou_nid;
          if ($dry_run) {
            uibx_log("-- would update node=$node->nid with ou=$ou_nid", "notice");
          }
          else {
            field_attach_update('node', $node);
          }
        }
        else {
          if ($dry_run) {
            uibx_log("** found no OU for node $node->nid **", "warning");
          }
        }
      }
    }
  }
}
