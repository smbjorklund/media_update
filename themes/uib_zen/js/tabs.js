(function ($) {
  Drupal.behaviors.uib_tabs = {
    attach: function (context, settings) {
      $('.uib-tabs-container').tabs({
        show: function(event, ui) {
          if (ui.panel.id) {
            var initialScroll = $(window).scrollTop();
            window.location.hash = ui.panel.id;
            $(window).scrollTop(initialScroll);
            $('#page').scrollTop(0);
          }
        }
      });
    }
  }
})(jQuery);
