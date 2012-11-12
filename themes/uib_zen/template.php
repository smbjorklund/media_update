<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   uib_zen_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: uib_zen_field()
 *
 *   where uib_zen is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  uib_zen_preprocess_html($variables, $hook);
  uib_zen_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function uib_zen_preprocess_html(&$variables, $hook) {

  if (!$variables['user']->uid == '0') {
    $user = user_load($variables['user']->uid);

    if (empty($user->field_grid['und']) || !empty($user->field_grid['und'][0]['value']) == '0')
      $variables['classes_array'][] = 'grid';
  }
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function uib_zen_preprocess_page(&$variables, $hook) {
  /**
  * Setup variables for handling of current area
  *   'area'
  *    pointer to relevant area node object. Empty if no relevant area present
  *   'page_title'
  *    Area title to be used. Defaults to site name if no relevant area present
  *   'page_title_link'
  *    Full url to area home. Defaults to front page if no relevant area present
  *    Corresponding modifications to use page_title and page_title_link were made in page.tpl.php
  */
  
  $variables['area'] = "";
  $variables['page_title'] = $variables['site_name'];
  $variables['page_title_link'] = l($variables['site_name'], $variables['front_page'], array('attributes' => array('title' => $variables['site_name'] . " " . t('Home'))));

  if (isset($variables['node'])) {
    $node = $variables['node'];
  }
  elseif (arg(0) == 'node' && is_numeric(arg(1))) {
    // if no node present, load node from information in url
     $node = node_load(arg(1));
  }
  if (isset($node)) {
    if ($node->type == 'area') {
      // if content is of type 'area' use its title and node id
      $variables['area'] = $node;
      $variables['page_title'] = $node->title;
      $variables['page_title_link'] = l($node->title, 'node/' . $node->nid, array('attributes' => array('title' => $node->title . " " . t('Home'))));
      // set menu style
      $variables['uib_menu_style'] = 'uib_menu_style_' . $variables['node']->field_uib_menu_style['und'][0]['value'];
    }
    else {
      // if content is of other type ('article', 'testimonial'),
      // use title of its referenced area and its node id
      // -- get the referenced area from the node object
      $belongs_to = $node->field_uib_area['und'][0];
      if (isset($belongs_to['entity'])) {
        // if the entity object is present, use it
        $referenced_area = $belongs_to['entity'];
      }
      else {
        // if the entity object is not present, load the object by using
        // the node id throught the node_load function
        $referenced_area = node_load($belongs_to['target_id']);
      }
      if (isset($referenced_area->title)) {
        $variables['area'] = $referenced_area;
        $variables['page_title'] = $referenced_area->title;
        $variables['page_title_link'] = l(check_plain($referenced_area->title), 'node/' . $referenced_area->nid, array('attributes' => array('title' => check_plain($referenced_area->title) . " " . t('Home'))));
        // set menu style as for referenced area
        $variables['uib_menu_style'] = 'uib-menu-style-' . $referenced_area->field_uib_menu_style['und'][0]['value'];
      }
    }
  }
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function uib_zen_preprocess_node(&$variables, $hook) {
  if ($variables['page']) { // only preprocess if node is rendered in page mode
    if ($variables['type'] == 'area') {
      if ($variables['field_uib_area_type']['0']['value'] == 'research group') {
        $variables ['classes_array'][] = t('research_g_node');
      }

      if ($variables['field_uib_area_type']['0']['value'] == 'faculty') {
        $variables ['classes_array'][] = t('faculty_node');
      }

      if ($variables['field_uib_area_type']['0']['value'] == 'institute') {
        $variables ['classes_array'][] = t('institute_node');
      }

      if ($variables['field_uib_area_type']['0']['value'] == 'research school') {
        $variables ['classes_array'][] = t('research_s_node');
      }

      if ($variables['field_uib_area_type']['0']['value'] == 'section') {
        $variables ['classes_array'][] = t('section_node');
      }

      if ($variables['field_uib_area_type']['0']['value'] == 'unit') {
         $variables ['classes_array'][] = t('unit_node');
      }
    }
    // Handle articles
    if ($variables['type'] == 'uib_article') {
      if ($variables['field_uib_article_type'][0]['value'] == 'news') {
        // Setup kicker
        // -- First determine which date to set
        if ($variables['node']->created < $variables['node']->revision_timestamp) {
          $up_date = format_date($variables['node']->revision_timestamp, 'medium');
        }
        else {
          $up_date = format_date($variables['node']->created, 'medium');
        }
        if (empty($variables['field_uib_kicker'][0]['value'])) {
          // set default value for kicker in news articles
          $variables['content']['field_uib_kicker'][0]['text'] = array('#markup' => "<div class=\"uib-kicker-text\">" . t('news') . "</div>");
        }
        else {
          $variables['content']['field_uib_kicker'][0]['text'] = array('#markup' => "<div class=\"uib-kicker-text\">" . $variables['content']['field_uib_kicker'][0]['#markup'] . "</div>");
          $variables['content']['field_uib_kicker'][0]['#markup'] = "";
        }
        $variables['content']['field_uib_kicker'][0]['date'] = array('#markup' => "<div class=\"uib-kicker-date\">" . $up_date . "</div>");

        // Byline
        $uib_news_byline = "";
        $byline_nrof_authors = count($variables['field_uib_byline']);
        if ($byline_nrof_authors > 0) {
          $uib_news_byline = t('By') . ' ';
          $glue = "";
          // join authors into a single line
          for ($i = 0; $i < $byline_nrof_authors; $i++) {
            $uib_news_byline .= $glue . $variables['content']['field_uib_byline'][$i]['#markup'];
            if ($i == $byline_nrof_authors - 2) {
              $glue = ' ' . t('and') . ' '; // not comma between last names
            }
            else {
              $glue = ', '; // comma between names
            }
          }
          hide($variables['content']['field_uib_byline']);
          $variables['content']['uib_news_byline'] = array('#markup' => "<div class=\"uib-news-byline\">" . $uib_news_byline . "</div>");
        }
      }
      else {
        // In articles of other types than 'news': Ensure that no byline is shown
        if (!empty($variables['content']['field_uib_byline'])) {
          hide($variables['content']['field_uib_byline']);
        }
      }
    }
  }

  /*
  // Optionally, run node-type-specific preprocess functions, like
  // uib_zen_preprocess_node_page() or uib_zen_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
  */
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */
