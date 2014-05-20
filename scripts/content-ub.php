<?php

// Load UB-frontpage
$node = node_load(71388);

// Adding Zopim chat code
$chat ='<script type="text/javascript">window.$zopim||(function(d,s){var z=$zopim=function(c){z._.push(c)},$=z.s=d.createElement(s),e=d.getElementsByTagName(s)[0];z.set=function(o){z.set._.push(o)};z._=[];z.set._=[];$.async=!0;$.setAttribute("charset","utf-8");$.src="//v2.zopim.com/?25e9P8jj1JJsAgm3hwMHaINRLLRM4pCF";z.t=+new Date;$.type="text/javascript";e.parentNode.insertBefore($,e)})(document,"script");</script>';
$searchbox = '<form action ="http://bibsys-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do" style="width:100%;"><input style="width:75%; height: 4em; padding:0; float: left;border: 0; background: #eee; -moz-border-radius: 3px 0 0 3px;-webkit-border-radius: 3px 0 0 3px; border-radius: 3px 0 0 3px;" placeholder="Artikler, bøker, tidsskrifter med meir" type="text" id="oria" name="vl(freeText0)"><input type="hidden" value="UBB" name="vid"><input type="hidden" value="true" name="Login"><input type="hidden" value="search" name="fn"><button style="overflow: visible;position: relative;float: right;border: 0;padding: 0;cursor: pointer;height: 4em;width: 25%;color: #fff;text-transform: uppercase;background: #d83c3c;-moz-border-radius: 0 3px 3px 0;-webkit-border-radius: 0 3px 3px 0;border-radius: 0 3px 3px 0; text-shadow: 0 -1px 0 rgba(0, 0 ,0, .3);" type="submit">Søk</button></form>';

$node->field_uib_area_banner['und'][0]['value'] = $chat;
$node->field_uib_area_banner['und'][0]['value'] .= $searchbox;

// Social icons
$node->field_uib_social_media['und'][0]['value'] = 'twitter:uib';
$node->field_uib_social_media['und'][1]['value'] = 'facebook:uib';
$node->field_uib_social_media['und'][2]['value'] = 'youtube:uib';
$node->field_uib_social_media['und'][3]['value'] = 'vimeo:uib';
$node->field_uib_social_media['und'][4]['value'] = 'flickr:uib';

// Slideshow
$slideshow = array(76962,77042,76887);
foreach ($slideshow as $key) {
  $node->field_uib_profiled_article['und'][]['target_id'] = $key;
}

// Temporary book widget
$node->field_uib_secondary_text['und'][0]['value'] = '<script type="text/javascript" src="http://ltfl.librarything.com/forlibraries/widget.js?id=2175-2558198918"></script><div class="ltfl_bookdisplay_widget" id="ltfl_widget_ult_2161100747"></div>';
$node->field_uib_secondary_text['und'][0]['format'] = 'full_html';

node_save($node);
