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

  /**
   * Get area menu style.
   */
  $current_area = uib_area__get_current();
  if (!empty($current_area)) {
    $menu_style = field_get_items('node', $current_area, 'field_uib_menu_style');
    $variables['classes_array'][] = $menu_style[0]['value'];
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
  $variables['page_title'] = $variables['site_name'];
  $variables['page_title_link'] = l($variables['site_name'], '<front>', array('attributes' => array('title' => $variables['site_name'] . " " . t('Home'))));
  $variables['uib_node_edit_mode'] = '';
  if (!empty($variables['node']->type) && $variables['node']->type == 'area') {
    $current_area = $variables['node'];
    // use the title of current area
    $variables['page_title'] = $current_area->title;
    $variables['page_title_link'] = l(check_plain($current_area->title), 'node/' . $current_area->nid, array('attributes' => array('title' => check_plain($current_area->title) . " " . t('Home'))));
  }
  else {
    $current_area = uib_area__get_current();
    if (!empty($current_area)) {
      // use the title of current area
      $variables['page_title'] = $current_area->title;
      $variables['page_title_link'] = l(check_plain($current_area->title), 'node/' . $current_area->nid, array('attributes' => array('title' => check_plain($current_area->title) . " " . t('Home'))));
    }
  }

  if (arg(0) == 'node' && arg(1) != 'add') {
    if ($variables['language']->language == 'nb') {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu-no');
    }
    else {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu');
    }
  }

  if (isset($variables['page']['header']['locale_language'])) {
    $variables['extra_language'] = $variables['page']['header']['locale_language'];
  }

  // Render areas custom logo.
  if (!empty($current_area)) {
    $output = field_view_field('node', $current_area, 'field_uib_logo',
      array(
        'type' => 'image',
        'label' => 'hidden',
        'settings' => array(
          'image_style' => 'custom_logo',
        )
      )
    );
  }
  $variables['custom_logo'] = render($output);

  if (isset($variables['node'])) {
    // Create a variable that indicates whether we are in EDIT mode or not
    $suggestions = theme_get_suggestions(arg(), 'page');
    if ($suggestions) {
      if (in_array('page__node__edit', $suggestions)) {
        $variables['uib_node_edit_mode'] = 'edit';
      }
    }

    if ($variables['node']->type == 'area') {
      if (isset($variables['page']['content']['uib_area_node_children'])) {
        unset($variables['page']['content']['uib_area_node_children']);
      }
    }
  }
}

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
      if ($variables['field_uib_area_type']['und']['0']['value'] == 'research group') {
        $variables ['classes_array'][] = t('research_g_node');
      }

      if ($variables['field_uib_area_type']['und']['0']['value'] == 'faculty') {
        $variables ['classes_array'][] = t('faculty_node');
      }

      if ($variables['field_uib_area_type']['und']['0']['value'] == 'institute') {
        $variables ['classes_array'][] = t('institute_node');
      }

      if ($variables['field_uib_area_type']['und']['0']['value'] == 'research school') {
        $variables ['classes_array'][] = t('research_s_node');
      }

      if ($variables['field_uib_area_type']['und']['0']['value'] == 'section') {
        $variables ['classes_array'][] = t('section_node');
      }

      if ($variables['field_uib_area_type']['und']['0']['value'] == 'unit') {
         $variables ['classes_array'][] = t('unit_node');
      }
      if (isset($variables['content']['field_uib_profiled_article'])) {
        $weight = $variables['content']['field_uib_profiled_article']['#weight'];
        unset($variables['content']['field_uib_profiled_article']);
        $variables['content']['field_uib_profiled_article'][]['#markup'] = views_embed_view('area_slideshow', 'default', $variables['nid']);
        $variables['content']['field_uib_profiled_article']['#weight'] = $weight;
      }
      $tmp_block_html = views_embed_view('faculty_departments_kids', 'block', $variables['nid']);
      if (stripos($tmp_block_html, 'view-content') !== FALSE) { // display only if any content present
        $variables['content']['group_two_column']['field_uib_kids']['#markup'] = $tmp_block_html;
        $variables['content']['group_two_column']['field_uib_kids']['#weight'] = 6;
      }

       if ($variables['field_uib_show_staff']['und'][0]['value'] == 1) {
        $variables['content']['field_uib_front_staff']['#markup'] = views_embed_view('ansatte', 'page_1', $variables['nid']);
                $variables['content']['field_uib_front_staff']['#weight'] = 12;
       }
      // Hide "relevant links section" if empty [RTS-1073]
      if (isset($variables['content']['group_two_column']['field_uib_link_section']['#items'])) {
        if (empty($variables['content']['group_two_column']['field_uib_link_section']['#items'][0]['value'])) {
          hide($variables['content']['group_two_column']['field_uib_link_section']);
        }
      }
    }
    // Handle articles
    if ($variables['type'] == 'uib_article') {
       if ($variables['node']->field_uib_article_type['und'][0]['value'] == 'news') {
        // Setup kicker
        // -- First determine which date to set
        if ($variables['node']->created < $variables['node']->revision_timestamp) {
          $up_date = format_date($variables['node']->revision_timestamp, 'medium');
        }
        else {
          $up_date = format_date($variables['node']->created, 'medium');
        }
        if (empty($variables['node']->field_uib_kicker['und'][0]['value'])) {
          // set default value for kicker in news articles
          $variables['node']->field_uib_kicker['und'][0] = array('value' => t('News'),   'format' => NULL, 'safe_value' => t('News'));
          $field_uib_kicker = field_view_field('node', $variables['node'], 'field_uib_kicker', array('label' => 'hidden'));
          $variables['content']['field_uib_kicker'] = $field_uib_kicker;
          $variables['content']['field_uib_kicker'][0]['text'] = array('#markup' => "<div class=\"uib-kicker-text\">" . t('News') . "</div>");
        }
        else {
          $variables['content']['field_uib_kicker'][0]['text'] = array('#markup' => "<div class=\"uib-kicker-text\">" . $variables['content']['field_uib_kicker'][0]['#markup'] . "</div>");
        }
        $variables['content']['field_uib_kicker'][0]['#markup'] = "";
        $variables['content']['field_uib_kicker'][0]['date'] = array('#markup' => "<div class=\"uib-kicker-date\">" . $up_date . "</div>");

        // Byline
        $uib_news_byline = "";
        $byline_nrof_authors = 0;
        if (isset($variables['field_uib_byline']['und'])) {
          $byline_nrof_authors = count($variables['field_uib_byline']['und']);
        }
        if ($byline_nrof_authors > 0) {
          $uib_news_byline = t('By') . ' ';
          $glue = "";
          // join authors into a single line
          for ($i = 0; $i < $byline_nrof_authors; $i++) {
            $uib_news_byline .= $glue . $variables['content']['group_article_main']['field_uib_byline'][$i]['#markup'];
            if ($i == $byline_nrof_authors - 2) {
              $glue = ' ' . t('and') . ' '; // not comma between last names
            }
            else {
              $glue = ', '; // comma between names
            }
          }
          hide($variables['content']['group_article_main']['field_uib_byline']);
          $variables['content']['group_article_main']['uib_news_byline'] = array('#markup' => "<div class=\"uib-news-byline\">" . $uib_news_byline . "</div>");
        }
        else {
          if (isset ($variables['node']->name)) {
            $uib_news_byline = t('By') . ' ' . $variables['node']->name;
            $variables['content']['group_article_main']['uib_news_byline'] = array('#markup' => '<div class="uib-news-byline">' . $uib_news_byline . "</div>");
          }
        }
        $variables['content']['group_article_main']['uib_news_byline']['#suffix'] = '<div class="uib-news-byline-created uib-publish-info">' . t('Created') . ' ' . format_date($variables['node']->created, 'long') . '</div><div class="uib-news-byline-last-updated uib-publish-info">' . t('Last updated') . ' ' . format_date($variables['node']->revision_timestamp, 'long') . '</div>';
      }
      else {
        // In articles of other types than 'news': Ensure that no byline is shown
        if (!empty($variables['content']['field_uib_byline'])) {
          hide($variables['content']['field_uib_byline']);
        }
        $variables['content']['group_article_main']['field_uib_text']['#suffix'] = '<div class="uib-article-created uib-publish-info">' . t('Created') . ' ' . format_date($variables['node']->created, 'long') . '</div><div class="uib-article-last-updated uib-publish-info">' . t('Last updated') . ' ' . format_date($variables['node']->revision_timestamp, 'long') . '</div>';
      }
      // Ensure that the labels of some fields, which are shown in the
      // main content sidebar, are not show when the fields contain no data
      if (empty($variables['node']->field_uib_location['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_location']);
      }
      if (empty($variables['node']->field_uib_fact_box['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_fact_box']);
      }
      if (empty($variables['field_uib_area']['und'][0]['entity'])) {
         hide($variables['content']['group_article_sidebar']['field_uib_area']);
      }
      if (empty($variables['node']->field_uib_media['und'][0]['uri'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media']);
      }
      elseif (empty($variables['node']->field_uib_media['und'][0]['field_uib_copyright']['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media'][0]['field_uib_copyright']);
      }
      elseif (empty($variables['node']->field_uib_media['und'][0]['field_uib_owner']['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media'][0]['field_uib_owner']);
      }

      // Section that only run on employee nodes.
      if (stripos($variables['node_url'], 'foransatte') !== FALSE OR stripos($variables['node_url'], 'foremployees') !== FALSE) {
        // Do not show related area on employee pages [RTS 1225]
        hide($variables['content']['group_article_sidebar']['field_uib_area']);

        // Add page-area-menu to node group_article_sidebar
        $block = module_invoke('menu_block', 'block_view', 'page-area-menu');
        $block = '<div class="block"><h2 class="block-title">' . $block['subject_array']['#markup'] . '</h2>' . render($block['content']) . '</div>';
        if (!empty($variables['content']['group_article_sidebar']['#id'])) {
          $variables['content']['group_article_sidebar']['page-area-menu']['#markup'] = $block;
        }
        else {
          $variables['content']['group_article_sidebar']['#weight'] = 4;
          $variables['content']['group_article_sidebar']['#id'] =  'node_uib_article_full_group_article_sidebar';
          $variables['content']['group_article_sidebar']['#prefix'] = '<div class="group-article-sidebar">';
          $variables['content']['group_article_sidebar']['#suffix'] = '</div>';
          $variables['content']['group_article_sidebar']['page-area-menu']['#markup'] = $block;
        }
      }

      if (isset($variables['field_uib_text']['und']) && (strstr($variables['field_uib_text']['und'][0]['safe_value'],'uib-tabs-container'))) {
        drupal_add_library('system' , 'ui.tabs');
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/tabs.js',
          array('group' => JS_THEME, )
        );
      }
    }

    if (in_array($variables['title'], array('Ansattsider', 'Employee Pages'))) {
      drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/hide_links.js',
        array('group' => JS_THEME, )
      );
    }
  }
  else {
    if ($variables['type'] == 'uib_testimonial') {
      $variables['title'] = '';
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

function uib_zen_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if (isset($variables['element']['#bid']) && ($variables['element']['#bid']['delta'] == 'top-area-menu') && ($element['#original_link']['depth'] == 2))
    $output = '<a href="#">' . $element["#title"] . '</a> ';
  else
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
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

/**
 * template_preprocess_region()
 * @param $variables
 *
 */
function uib_zen_preprocess_region(&$variables) {
  if (isset($variables['region']) == 'content_top') {
    $variables['classes_array'][] = 'clearfix';
  }
}

/**
* Override or insert variables into the block template
*
* @param $variables
*   An array of varibales to pass to the theme template
* @param $hook
*   The name of the template being rendered
*/
function uib_zen_preprocess_block(&$variables, $hook) {
  //arrays containg block_html_id of blocks where the title is getting colored squares
  $blue_block = array(
    'block-views-recent-news-block',
    'block-uib-area-area-parents',
    'block-views-faculties-block-1',
    'block-uib-area-jobbnorge',
  );
  $orange_block = array(
    'block-views-calendar-block-1',
  );
  if (in_array ($variables['block_html_id'], $blue_block)) {
    $variables['classes_array'][] = 'blue-block';
    $variables['block']->subject = '<span></span>' . $variables['block']->subject;
  }
  if (in_array ($variables['block_html_id'], $orange_block)) {
    $variables['classes_array'][] = 'orange-block';
    $variables['block']->subject = '<span></span>' . $variables['block']->subject;
  }
}

/**
* Override or insert variables into the field template
*
* @param $variables
*   A array of variables to pass to the theme template
* @param $hook
*   The name of the template being rendered
*/
function uib_zen_preprocess_field(&$variables, $hook) {
  //arrays containg field_name_css of blocks where the title is getting colored squares
  $blue_block = array(
    'field-uib-area',
    'field-uib-files',
  );
  if (in_array($variables['field_name_css'], $blue_block)) {
    $variables['classes_array'][] = 'blue-block';
    $variables['label'] = '<span></span>' . $variables['label'];
  }
}
