<?php
/**
 *
 */
class uib_area_reaction extends context_reaction {
  function options_form($context) {
    return array('UIB Area' => array('#type' => 'value', '#value' => TRUE));
  }

  function options_form_submit($values) {
    return array('area' => 1);
  }

  function execute(&$nid = NULL) {
    $contexts = context_active_contexts();

    foreach ($contexts as $context) {
      if (!empty($context->reactions['areaid'])) {
      }
    }

    if (isset($nid)) {
      $node = node_load($nid);
      return ($node->title);
    }
  }

}
