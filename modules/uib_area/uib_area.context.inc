<?php
/**
 * @file
 * uib_area.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_area_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ansattside_blocks';
  $context->description = 'Blocks that are unique to employee pages';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'foransatte' => 'foransatte',
        'foransatte/*' => 'foransatte/*',
        'en/foremployees' => 'en/foremployees',
        'en/foremployees/*' => 'en/foremployees/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-page-area-menu' => array(
          'module' => 'menu_block',
          'delta' => 'page-area-menu',
          'region' => 'content',
          'weight' => '-23',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that are unique to employee pages');
  t('block');
  $export['ansattside_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_blocks';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'area' => 'area',
        'uib_article' => 'uib_article',
        'uib_testimonial' => 'uib_testimonial',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'area_map' => 'area_map',
        'calendar' => 'calendar',
        'recent_news:newsarchive' => 'recent_news:newsarchive',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_area-area_parents' => array(
          'module' => 'uib_area',
          'delta' => 'area_parents',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-calendar-block_1' => array(
          'module' => 'views',
          'delta' => 'calendar-block_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-calendar-block_4' => array(
          'module' => 'views',
          'delta' => 'calendar-block_4',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-recent_news-block' => array(
          'module' => 'views',
          'delta' => 'recent_news-block',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'uib_area-feed' => array(
          'module' => 'uib_area',
          'delta' => 'feed',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'uib_area-jobbnorge' => array(
          'module' => 'uib_area',
          'delta' => 'jobbnorge',
          'region' => 'sidebar_second',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['area_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_blocks_not_ansattsider';
  $context->description = 'Blocks that should show on all area pages but not employee pages';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'area' => 'area',
        'uib_article' => 'uib_article',
        'uib_testimonial' => 'uib_testimonial',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~foransatte' => '~foransatte',
        '~foransatte/*' => '~foransatte/*',
        '~en/foremployees' => '~en/foremployees',
        '~en/foremployees/*' => '~en/foremployees/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_area-node_children' => array(
          'module' => 'uib_area',
          'delta' => 'node_children',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that should show on all area pages but not employee pages');
  t('block');
  $export['area_blocks_not_ansattsider'] = $context;

  return $export;
}
