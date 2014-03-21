(function ($) {
  Drupal.behaviors.uib_tabs = {
    attach: function (context, settings) {
      $('.uib-tabs-container').tabs({
        show: function(event, ui) {
          if (ui.panel.id) {
            window.location.hash = ui.panel.id;
          }
        }
      });
    }
  }
})(jQuery);
