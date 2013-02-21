(function ($) {
  Drupal.behaviors.uib_zen = {
    attach: function (context, settings) {
        $('.uib-tabs-container').tabs();
    }
  }
})(jQuery);
