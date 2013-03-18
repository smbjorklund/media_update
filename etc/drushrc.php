<?php
/**
List of DB-tables that do not need to dumped into the backup-file

In oprder to use this file, softlink it into
  drupal/sites/[SERVER_NAME]/drushrc.php
*/
$options['structure-tables'] = array(
    'common' => array(
       'cache', 'cache_block', 'cache_bootstrap', 'cache_field', 'cache_filter',
       'cache_form', 'cache_image', 'cache_menu', 'cache_page', 'cache_path', 'cache_update',
       'cache_admin_menu', 'cache_coder', 'cache_l10n_update', 'cache_media_xml', 'cache_token',
       'cache_variable', 'cache_views', 'cache_views_data',
       'semaphore', 'sequences', 'queue',
       'history', 'sessions', 'watchdog',
    ),
);
