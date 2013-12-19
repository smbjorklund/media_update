<?php
/**
 * Fix author and byline from w2
 */
$bundles = array('uib_article', 'uib_testimonial');
$cnt = 0;
foreach ($bundles as $bundle) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->propertyCondition('uid', '0')
    ->fieldCondition('field_uib_w2_id','value', '0', '>');
  $result = $query->execute();

  if (!empty($result)) {
    $nr = count($result['node']);
    uibx_log("Checking $nr $bundle nodes...");
    $nodes = entity_load('node', array_keys($result['node']));

    foreach ($nodes as $nid => $node_obj) {
      $changed = '';
      $node = entity_metadata_wrapper('node', $node_obj);
      $w2_data = new XTopic($node->field_uib_w2_id->value(), TRUE, "w2 author of node $nid");
      // Author
      if (!empty($w2_data->author) && empty($w2_data->author_name)) {
        $w2_data->author_name = uib_migrate__get_user_name($w2_data->author);
      }
      if (isset($w2_data->author_name)) {
        if ($uid = uib_migrate__get_user($w2_data->author_name)) {
          $node->author->set($uid);
          $changed .= 'author';
        }
      }
      // Byline
      if ($bundle != 'uib_testimonial') {
        $existing_byline = $node->field_uib_byline->value();
        if (empty($existing_byline) && !empty($w2_data->byline)) {
          foreach($w2_data->byline as $delta => $byline_w2_id) {
            $byline_author = uib_migrate__get_user_name($byline_w2_id);
            $uid = uib_migrate__get_user($byline_author);
            if ($uid) {
              $node->field_uib_byline[$delta]->set($uid);
              if ($changed) {
                $changed .= ', ';
              }
              $changed .= 'byline';
            }
          }
        }
      }

      $changed = trim($changed);
      if ($changed) {
        $node->save();
        $node_title = $node->title->value();
        $node_nid = $node->getIdentifier();
        $cnt++;
        uibx_log("Updated node $node_nid '$node_title' [$changed]");
      }
    }
  }
}
uibx_log("Updated $cnt nodes");
