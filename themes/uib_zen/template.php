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
  if (isset($variables['node'])) {
    if ($variables['node']->type == 'uib_article'){
      if ($variables['node']->language != $variables['language']->language) {
        $variables['title_prefix'] = '<div class="uib-not-translated">' .t('The content of this article has not been translated.') . '</div>';
        drupal_set_breadcrumb(array());
      }
    }
  }
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
  if (!empty($current_area) && $current_area->field_uib_area_type['und'][0]['value'] == 'frontpage') {
    $variables['page_title_link'] = l(check_plain($current_area->title), '', array('attributes' => array('title' => check_plain($current_area->title) . " " . t('Home'))));
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
      unset($variables['page']['content']['uib_area_node_children']);
    }
  }

  $variables['uib_long_page_title'] = FALSE;
  if (strlen($variables['page_title']) > 47 && !empty($variables['custom_logo'])) {
    $variables['uib_long_page_title'] = TRUE;
  }
  elseif (strlen($variables['page_title']) > 65 && empty($variables['custom_logo'])) {
    $variables['uib_long_page_title'] = TRUE;
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
      if ($variables['field_uib_area_type']['und']['0']['value'] == 'newspage') {
        $variables ['classes_array'][] = t('newspage_node');
        //This field is printed in a view in the sidebar
        unset($variables['content']['group_two_column']['field_uib_link_section']);
        if (isset($variables['content']['group_two_column']['field_uib_profiled_message'])) {
          $weight = $variables['content']['group_two_column']['field_uib_profiled_message']['#weight'];
          unset($variables['content']['group_two_column']['field_uib_profiled_message']);
          $variables['content']['field_uib_profiled_message'][]['#markup'] = views_embed_view('frontpage_profiled_articles', 'newspage_one_chosen_item', $variables['nid']);
          $variables['content']['field_uib_profiled_message']['#weight'] = $weight;
          $variables['content']['field_uib_profiled_message_2'][]['#markup'] = views_embed_view('frontpage_profiled_articles', 'newspage_two_chosen_items', $variables['nid']);
          $variables['content']['field_uib_profiled_message_2']['#weight'] = $weight - 1;
          $variables['content']['field_uib_profiled_message_last'][]['#markup'] = views_embed_view('frontpage_profiled_articles', 'newspage_last_chosen_items', $variables['nid']);
          $variables['content']['field_uib_profiled_message_last']['#weight'] = $weight + 1;
          // Recent news block from uib_area module
          $recent_news_block = module_invoke('uib_area', 'block_view', 'newspage_recent_news');
          $variables['content']['field_uib_newspage_recent_news'] = $recent_news_block['content'];
          $variables['content']['field_uib_newspage_recent_news']['#weight'] = $weight + 2;
          $variables['content']['field_uib_newspage_recent_news'][0]['#markup'] = l(t('News archive'), drupal_get_path_alias(current_path()) . '/news-archive');
        }
        unset($variables['content']['group_two_column']);
      }
      if ($variables['field_uib_area_type']['und']['0']['value'] == 'frontpage') {
        $variables ['classes_array'][] = t('frontpage_node');
        //This field is printed as view
        unset($variables['content']['group_two_column']['field_uib_profiled_message']);
        unset($variables['content']['group_two_column']['field_uib_link_section']);
        // Adding js to fix mobile menu on front page
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/mobile_menu_fix.js',
          array('group' => JS_THEME, )
        );
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
      if (!isset($variables['content']['field_uib_primary_text'])) {
        $variables['content']['field_uib_primary_media'][0]['#view_mode'] = 'content_main';
        $variables['content']['field_uib_primary_media'][0]['file']['#style_name'] = 'content_main';
        $variables['classes_array'][] = 'no-primary-text';
      }
    }

    // Handle articles
    if ($variables['type'] == 'uib_article') {
        $variables['content']['title']['#markup'] = '<h1>' . $variables['title'] . '</h1>';
        $variables['content']['title']['#weight'] = 0.5;
      if ($variables['node']->field_uib_article_type['und'][0]['value'] == 'news') {
        // Setup kicker
        // -- First determine which date to set
        $created = format_date($variables['node']->created, 'medium');
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
        $variables['content']['field_uib_kicker'][0]['date'] = array('#markup' => "<div class=\"uib-kicker-date\">" . $created . "</div>");

        // Byline
        $uib_news_byline = "";
        $byline_nrof_authors = 0;
        $glue = "";
        if (isset($variables['field_uib_byline']['und'])) {
          $byline_nrof_authors = count($variables['field_uib_byline']['und']);
        }
        if ($byline_nrof_authors > 0) {
          $uib_news_byline = t('By') . ' ';
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
        }
        if (!empty($variables['field_uib_external_author']['und'])) {
          if (empty($uib_news_byline)) {
            $uib_news_byline = t('By') . ' ';
          }
          $uib_news_byline .= $glue . $variables['field_uib_external_author']['und'][0]['value'];
        }
        hide($variables['content']['group_article_main']['field_uib_byline']);
        $variables['content']['group_article_top']['uib_news_byline'] = array('#markup' => "<div class=\"uib-news-byline\">" . $uib_news_byline . "</div>");
        $variables['content']['group_article_top']['uib_news_byline']['#suffix'] = '<div class="uib-news-byline-created uib-publish-info">' . t('Created') . ' ' . format_date($variables['node']->created, 'long') . '</div><div class="uib-news-byline-last-updated uib-publish-info">' . t('Last updated') . ' ' . format_date($variables['node']->revision_timestamp, 'long') . '</div>';
        $variables['content']['group_article_top']['#prefix'] = '<div class="article-info">';
      }
      elseif ($variables['node']->field_uib_article_type['und'][0]['value'] == 'event') {
        if (empty($variables['node']->field_uib_kicker['und'][0]['value'])) {
          $event_type_machine_name = $variables['node']->field_uib_event_type['und'][0]['value'];
          $event_type_info = field_info_field('field_uib_event_type');
          $event_type_default = $event_type_info['settings']['allowed_values'][$event_type_machine_name];
          $event_type = i18n_string_translate('field:field_uib_event_type:#allowed_values:' . $event_type_machine_name, $event_type_default);
          $variables['node']->field_uib_kicker['und'][0] = array(
            'value' => $event_type,
            'format' => NULL,
            'safe_value' => $event_type
          );
          $field_uib_kicker = field_view_field('node', $variables['node'], 'field_uib_kicker', array('label' => 'hidden'), $variables['language']);
          $variables['content']['field_uib_kicker'] = $field_uib_kicker;
        }
        // Ensure that no byline is shown
        if (!empty($variables['content']['group_article_main']['field_uib_byline'])) {
          hide($variables['content']['group_article_main']['field_uib_byline']);
        }
      }
      else {
        // In all other article types ensure that no byline is shown
        if (!empty($variables['content']['group_article_main']['field_uib_byline'])) {
          hide($variables['content']['group_article_main']['field_uib_byline']);
        }
        // ... and that we show timestamps
        $variables['content']['group_article_top']['field_uib_text']['#suffix'] = '<div class="uib-article-created uib-publish-info">' . t('Created') . ' ' . format_date($variables['node']->created, 'long') . '</div><div class="uib-article-last-updated uib-publish-info">' . t('Last updated') . ' ' . format_date($variables['node']->revision_timestamp, 'long') . '</div>';
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
        if (empty($variables['content']['group_article_sidebar']['#id'])) {
          $variables['content']['group_article_sidebar']['#weight'] = 4;
          $variables['content']['group_article_sidebar']['#id'] =  'node_uib_article_full_group_article_sidebar';
          $variables['content']['group_article_sidebar']['#prefix'] = '<div class="group-article-sidebar">';
          $variables['content']['group_article_sidebar']['#suffix'] = '</div>';
        }
        $variables['content']['group_article_sidebar']['field_uib_relation'] = $variables['content']['field_uib_relation'];
        unset($variables['content']['field_uib_relation']);
      }

      if (isset($variables['field_uib_text']['und']) && (strstr($variables['field_uib_text']['und'][0]['safe_value'],'uib-tabs-container'))) {
        drupal_add_library('system' , 'ui.tabs');
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/tabs.js',
          array('group' => JS_THEME, )
        );
      }

      if (!in_array($variables['node']->field_uib_area['und'][0]['target_id'], array(1, 2))) {
        $service_links = theme('item_list', array(
          'items' => service_links_render($variables['node'], FALSE),
          'style' => SERVICE_LINKS_STYLE_IMAGE,
        ));
        if (!empty($variables['content']['group_article_main'])) {
          $variables['content']['group_article_top']['#suffix'] = '<div class="service-links">' . $service_links . '</div></div>';
          $variables['content']['group_article_top']['#weight'] = $variables['content']['group_article_main']['#weight'] - 0.5;
          if (empty($variables['content']['group_article_top']['#prefix'])) {
            $variables['content']['group_article_top']['#prefix'] = '<div class="article-info">';
          }
        }
      }
    }

    if (in_array($variables['title'], array('Ansattsider', 'Employee Pages'))) {
      drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/hide_links.js', array('group' => JS_THEME, ));
    }
  }

  if ($variables['view_mode'] == 'teaser' && $variables['type'] == 'uib_testimonial') {
    $variables['title'] = '';
  }

  // Add theme suggestion to nodes printed in view mode (newspage)
  if (($variables['type'] == 'uib_article') && ($variables['field_uib_article_type']['und'][0]['value'] == 'news')) {
    if ($variables['view_mode'] == 'teaser') {
      $variables['theme_hook_suggestions'][] = 'node__news__recent_news';
    }
  }

  if ($variables['view_mode'] == 'short_teaser') {
    $variables['theme_hook_suggestions'][] = 'node__children';
  }

  $variables['is_employee'] = FALSE;
  if (stripos($variables['node_url'], 'foransatte') !== FALSE OR stripos($variables['node_url'], 'foremployees') !== FALSE) {
    $variables['is_employee'] = TRUE;
  }

  if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'short_teaser') {
    $variables['is_employee'] = TRUE;
  }
}

function uib_zen_menu_link(array $variables) {
  global $user;
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if ($element['#href'] == 'node/add/uib-article') {
    // prepopulate byline field
    $output = '<a href="' . url($element['#href'], array('query' => array('field_uib_byline' => $user->uid))) . '"';
    if (!empty($element['#localized_options']['attributes']['title'])) {
      $output .= ' title="' . t($element['#localized_options']['attributes']['title']) . '"';
    }
    $output .= '>' . t($element['#title']) . '</a>';
  }
  elseif (isset($variables['element']['#bid']) && ($variables['element']['#bid']['delta'] == 'top-area-menu') && ($element['#original_link']['depth'] == 2) && (!drupal_is_front_page()))
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
  if ($variables['block_html_id'] == 'block-uib-area-colophon') {
    $variables['content'] = '<div class="block-wrapper">' . $variables['content'] . '</div>';
  }
  if ($variables['block_html_id'] == 'block-menu-menu-area-1') {
    $variables['classes_array'][] = 'clearfix';
  }

  //arrays containg block_html_id of blocks where the title is getting colored squares
  $blue_block = array(
    'block-views-recent-news-block',
    'block-uib-area-area-parents',
    'block-views-faculties-block-1',
    'block-uib-area-jobbnorge',
    'block-views-79622ce408d27be255f959dc886a6751',
    'block-views-59c9268577c7dee7af4089857ed7ab4e',
    'block-uib-area-feed',
  );
  $orange_block = array(
    'block-views-calendar-block-1',
    'block-views-e35933dcbeaec830701d3e48e98f0046',
    'block-views-87d291272c77934f60566c1a5bccebdf',
  );
  if (in_array ($variables['block_html_id'], $blue_block)) {
    if ($variables['block']->subject) {
      $variables['classes_array'][] = 'blue-block';
      $variables['block']->subject = '<span></span>' . $variables['block']->subject;
    }
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
  static $blue_block_done = FALSE;
  //arrays containing field_name_css of blocks where the title is getting colored squares
  $blue_block = array(
    'field-uib-area',
    'field-uib-files',
    'field-uib-title',
  );
  if (in_array($variables['field_name_css'], $blue_block)) {
    // Deal separately with certain field collections
    if (empty($variables['label']) && $variables['field_name_css'] == 'field-uib-title' && $variables['element']['#object']->field_name == 'field_uib_link_section') {
      $variables['items'][0]['#markup'] = '<span></span>' . $variables['items'][0]['#markup'];
      if ($blue_block_done) {
        // Fix to make second "block" in field collection orange
        $variables['classes_array'][] = 'orange-block';
      }
      else {
        $variables['classes_array'][] = 'blue-block';
        $blue_block_done = TRUE;
      }
    }
    else {
      $variables['classes_array'][] = 'blue-block';
      $variables['label'] = '<span></span>' . $variables['label'];
    }
  }
  if ($variables['element']['#field_name'] == 'field_uib_relation') {
    $variables['classes_array'][] = 'block-uib-area';
  }
}

function __uib_media_content($vars) {
  $content .= $vars;
  return $content;
}

function uib_zen_field($variables) {
  $output = '';
  // List of fields that will be rendered with simplified markup
  $simple_markup = array(
    'field_uib_lead',
    );
  if (in_array($variables['element']['#field_name'], $simple_markup)) {
    // Simplified markup
     foreach ($variables['items'] as $delta => $item) {
      $output = '<p class="' . $variables['classes'] . '">' . $item['#markup'] . '</p>';
    }
  }
  else {
    // Standard markup with lots of divs

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }

    if ($variables['element']['#field_name'] == 'field_uib_relation') {
      $output .= '<div class="field-wrapper">';
      // Potentially insert a header
      $header = uib_article__relation_title($variables['element']['#object']);
      if (!empty($header)) {
        $output .= '<h2 class="block-title">' . $header . '</h2>';
      }
      // Render this particular field as an unordered list
      // Render the items.
      $output .= '<ul class="field-items clearfix">';
      foreach ($variables['items'] as $delta => $item) {
        $output .= drupal_render($item);
      }
      $output .= '</ul></div>';
    }
    else {

      // Render the items.
      $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
      foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
      }
      $output .= '</div>';
    }
    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
  }
  return $output;
}
