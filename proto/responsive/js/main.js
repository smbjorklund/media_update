jQuery(document).ready(function($){
  $(".menu-button").toggle(function(e){
      $(".sf-menu").animate({top:'30px'});
    }, function(e){
      $(".sf-menu").animate({top:'-500'});
    });

});