jQuery(document).ready(function($){
  $(".menu-button").toggle(function(e){
      $(".sf-menu").animate({top:'0'});
    }, function(e){
      $(".sf-menu").animate({top:'-340px'});
    });
});
