/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.uib_toggle_menu = {
    attach: function (context, settings) {
      jQuery('.mobile-show-menu').click(function() {
        var left_position = jQuery('#navigation').css('left');
        var window_width = jQuery(window).width() + 'px';
        var new_position = '100%';
        if (left_position == window_width || left_position == '100%') {
          new_position = '20%';
        }
        jQuery('#navigation').animate({left: new_position},'slow', function() {
        });
        return false;
      });
    }
  }
  Drupal.behaviors.uib_toggle_search = {
    attach: function (context, settings) {
      jQuery('.mobile-show-search').click(function() {
        jQuery('#global-searchform').slideToggle('slow', function() {
        });
        jQuery('#searchField').focus();
        return false;
      });
    }
  }
})(jQuery, Drupal, this, this.document);
