(function ($) {
  Drupal.behaviors.uib_tabs = {
    attach: function (context, settings) {
        $('.uib-tabs-container').tabs();
    }
  }
})(jQuery);
