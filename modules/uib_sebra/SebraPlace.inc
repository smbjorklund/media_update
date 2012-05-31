<?php

class SebraPlace extends stdClass {

  public function __construct($id) {
    $url = 'http://sebra.uib.no/sws/place?code=' . $id;
    $this->id = $id;
    if (function_exists('drush_log')) {
      drush_log('GET ' . $url);
    }
    $place = @simplexml_load_file($url);
    if (empty($place)) {
      throw new Exception("Place $id not found: " . $url);
    }
    $this->name = (string)$place->name;
    $this->address = (string)$place->address;
    $this->postbox = (string)$place->postboks;
    $this->postcode = (string)$place->postnr;
    $this->postarea = (string)$place->postcode;
    $this->phone = (string)$place->tlf;
    $this->fax = (string)$place->fax;
    $this->alias = (string)$place->alias;
    $this->maildomain = (string)$place->maildomain;

    // Instead of empty strings we get the string "None" leaked
    // for the NULL attributes.  Sometimes we also get "na".
    foreach ($this as $key => $value) {
      if ($value == "None" || $value == "na") {
        $this->$key = NULL;
      }
    }
  }
}
