<?php
/**
 *
 */
class uib_area extends context_condition {
  function condition_values() {
    return array(
      1 => t('Foo'),
      2 => t('Bar'),
    );
  }

  // function editor_form($context = NULL) {
  //   $form = parent::editor_form($context);
  //   $form[1]['#title'] = t('Do not check Organisational Unit nodes');
  //   $form[2]['#title'] = t('Do not check Testimonial nodes');
  //   $form['#weight'] = -10;
  //   return $form;
  // }

  function execute() {
    $area = _uib_context_detect_area($nid);

    foreach ($this->get_contexts($area) as $context) {
      $this->condition_met($context, $area);
    }
  }
}
