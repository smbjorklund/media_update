<?php

class SebraPlace extends stdClass {

  public function __construct($id) {
    $url = 'http://sebra.uib.no/sws/place?code=' . $id;
    $this->id = $id;
    $place = simplexml_load_file($url);
    if (empty($place)) {
      throw new Exception("Place $id not found: " . $url);
    }
    $this->name = (string)$place->name;
    $this->address = (string)$place->address;
    $this->postbox = (string)$place->postboks;
    $this->postcode = (string)$place->postnr;
    $this->postarea = (string)$place->postcode;
    $this->phone = (string)$place->tlf;
    $this->alias = (string)$place->alias;
    $this->maildomain = (string)$place->maildomain;
  }
}
