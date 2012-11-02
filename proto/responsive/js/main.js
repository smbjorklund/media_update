jQuery(document).ready(function($){
  $(".menu-button").toggle(function(e){
      $(".sf-menu").animate({top:'30px'});
    }, function(e){
      $(".sf-menu").animate({top:'-500'});
    });

});
jQuery(document).ready(function($){
  $(".menu-button").toggle(function(e){
      $(".sf-menu-2").animate({top:'100px'});
    }, function(e){
      $(".sf-menu-2").animate({top:'-800'});
    });

});