<?php

class SebraPerson extends stdClass {

  public function __construct($id) {
    $url = 'http://sebra.uib.no/sws/person?id=' . $id;
    uibx_log('GET ' . $url);
    $person = @simplexml_load_file($url);
    if (empty($person)) {
      throw new Exception("Person $id not found: " . $url);
    }

    $this->id = $id;
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

    $url = 'http://sebra.uib.no/sws/staff?id=' . $id;
    uibx_log('GET ' . $url);
    $staff = @simplexml_load_file($url);
    if (!empty($staff)) {
      $this->person_type = 'staff';
      $this->place_code = (string)$staff->place;
      $this->position_code = (string)$staff->code;
      $this->position_name_no = (string)$staff->title;
      $this->position_name_en = (string)$staff->title_english;
      $this->position_category = (string)$staff->title_category;
    }
    else {
      $url = 'http://sebra.uib.no/sws/affiliated?id=' . $id;
      uibx_log('GET ' . $url);
      $extern = @simplexml_load_file($url);
      if (!empty($extern)) {
        $this->person_type = 'extern';
        $this->place_code = (string)$extern->place;
        $this->position_name_no = (string)$extern->title;
        $this->position_name_en = (string)$extern->title_english;
        $this->position_category = (string)$extern->title_category;
      }
    }

    if (0) {
      $url = 'http://sebra.uib.no/sws/omraaderoller?id=' . $id;
      uibx_log('GET ' . $url);
      $roles = @simplexml_load_file($url);
      //...
    }
  }
}
