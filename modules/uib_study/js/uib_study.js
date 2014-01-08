(function ($) {

  Drupal.behaviors.uib_study_prev = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".previous-exists" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "button.previous" ).click(function() {
            curData.hide();
            prevData.show();
            nextData.hide();
            $( "button.previous" ).addClass( "is-active" );
            $( "button.current" ).removeClass( "is-active" );
            $( "button.next" ).removeClass( "is-active" );
          });
      });
    }
  }

  Drupal.behaviors.uib_study_curr = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".variants-exist" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "button.current" ).click(function() {
            curData.show();
            prevData.hide();
            nextData.hide();
            $( "button.current" ).addClass( "is-active" );
            $( "button.previous" ).removeClass( "is-active" );
            $( "button.next" ).removeClass( "is-active" );
          });
      });
    }
  }

  Drupal.behaviors.uib_study_next = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".next-exists" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "button.next" ).click(function() {
            curData.hide();
            prevData.hide();
            nextData.show();
            $( "button.previous" ).removeClass( "is-active" );
            $( "button.current" ).removeClass( "is-active" );
            $( "button.next" ).addClass( "is-active" );
          });
      });
    }
  }

})(jQuery);
