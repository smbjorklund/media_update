<?php
// Timezone setting depend on http://drupal.org/node/1017020 patch
function uib_form_install_configure_form_alter(&$form, $form_state) {
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Oslo';
}
