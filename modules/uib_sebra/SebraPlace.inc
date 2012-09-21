<?php
/**
 * @file
 * Information about a UiB organisation unit obtained from Sebra.
 */
class SebraPlace extends stdClass {

  /**
   * Construct a new SebraPlace object.
   *
   * The object will have the attributes 'name', 'address', 'postbox',
   * 'postcode', 'postarea', 'phone', 'fax', 'alias', 'maildomain'.
   *
   * @param $id
   *    The place code.  It's a 6-digit number.  For instance '221000'
   *    represent the IT-department.
   */
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
