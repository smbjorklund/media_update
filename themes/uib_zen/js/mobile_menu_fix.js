(function ($) {
  Drupal.behaviors.uib_mobile_menu_fix = {
    attach: function (context, settings) {
		 // Copied from http://snippets.webaware.com.au/snippets/make-css-drop-down-menus-work-on-touch-devices/
		 // see whether device supports touch events (a bit simplistic, but...)
		var hasTouch = ("ontouchstart" in window);
		var iOS5 = /iPad|iPod|iPhone/.test(navigator.platform) && "matchMedia" in window;
		// hook touch events for drop-down menus
		// NB: if has touch events, then has standards event handling too
		// but we don't want to run this code on iOS5+
		if (hasTouch && document.querySelectorAll && !iOS5) {
		    var i, len, element,
		        dropdowns = document.querySelectorAll(".menu-block-wrapper .menu li a");
		    function menuTouch(event) {
		        // toggle flag for preventing click for this link
		        var i, len, noclick = !(this.dataNoclick);

		        // reset flag on all links
		        for (i = 0, len = dropdowns.length; i < len; ++i) {
		            dropdowns[i].dataNoclick = false;
		        }

		        // set new flag value and focus on dropdown menu
		        this.dataNoclick = noclick;
		        this.focus();
		    }

		    function menuClick(event) {
		        // if click isn't wanted, prevent it
		        if (this.dataNoclick) {
		            event.preventDefault();
		        }
		    }

		    for (i = 0, len = dropdowns.length; i < len; ++i) {
		        element = dropdowns[i];
		        element.dataNoclick = false;
		        element.addEventListener("touchstart", menuTouch, false);
		        element.addEventListener("click", menuClick, false);
		    }
		}
    }
  }
})(jQuery);