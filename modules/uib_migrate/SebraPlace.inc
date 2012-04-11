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
    $this->maildomain = (string)$place->maildomain;
  }
}
