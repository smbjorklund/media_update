<?php

class SebraPlace extends stdClass {

  public function __construct($id) {
    $this->id = $id;
    $place = uib_sebra__sws_get('place?code=' . $id);
    if (empty($place)) {
      throw new Exception("Place $id not found");
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
