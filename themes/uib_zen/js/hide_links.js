(function ($) {
  Drupal.behaviors.uib_zen = {
    attach: function (context, settings) {
      $('.field-name-field-uib-link-section')
        .find('.field-collection-item-field-uib-link-section')
        .find('.field-item:gt(12):not(last-child)')
        .hide();
      $('.field-name-field-uib-link-section')
        .find('.field-collection-item-field-uib-link-section')
        .find('.field-name-field-uib-links')
        .find('.field-items')
        .append(
          $('<div class="more_links">Flere linker</div>')
        );
      $('.more_links').click(function() {
        $('.field-name-field-uib-link-section')
        .find('.field-collection-item-field-uib-link-section')
        .find('.field-item:gt(12)')
        .show()
        .end();
        $(this).remove();
        })
    }
  }
})(jQuery);
