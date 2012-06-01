<?php

class SebraPerson extends stdClass {

  public function __construct($id) {
    $url = 'http://sebra.uib.no/sws/person?id=' . $id;
    $this->id = $id;
    if (function_exists('drush_log')) {
      drush_log('GET ' . $url);
    }
    $person = @simplexml_load_file($url);
    if (empty($person)) {
      throw new Exception("Place $id not found: " . $url);
    }
    $this->first_name = (string)$person->name;
    $this->last_name = (string)$person->surname;
    $this->email = (string)$person->epost;
    $this->sex = (string)$person->sex;
    $this->phone_office = (string)$person->tlf;
    $this->phone_mobile = (string)$person->mobile;
    $this->visit_address_street = (string)$person->address;
    $this->visit_address_zip = (string)$person->postnr;
    $this->visit_address_city = (string)$person->postcode;
    $this->visit_address_country = (string)$person->land;
  }
}
