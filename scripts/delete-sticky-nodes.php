<?php

/**
 *  This deletes all uib_articles who is set to sticky, no lead and body
 */

$query = new EntityFieldQuery;
$query = $query
     ->entityCondition('entity_type', 'node')
     ->propertyCondition('type', 'uib_article')
     ->propertyCondition('sticky', 1);
$result = $query->execute();
if (!empty($result['node'])) {
  foreach (array_keys($result['node']) as $nid) {
    $node = node_load($nid);
    node_delete($nid);
    print "The node with nid:$node->nid was deleted\n";
  }
}
