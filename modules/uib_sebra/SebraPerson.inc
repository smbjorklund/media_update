<?php
/**
 * @file
 * Information about a user obtained from Sebra.
 *
 * SebraPerson is a stdClass object with the following attributes: id,
 * first_name, last_name, email, sex, phone_office, phone_mobile,
 * visit_address_*, person_type, place_code, position_name_no, position_name_en,
 * position_code, position_category.  Attributes might be missing.
 */

class SebraPerson extends stdClass {

  /** Create a new SebraPerson object.
   *
   *  Will throw an exception if no user with the given name is known by Sebra.
   *  The exception will have a 'code' of 404 in that case.
   *
   *  @param $id
   *    The UiB username of the person to fetch information about
   */

  public function __construct($id) {
    $person = uib_sebra__sws_get('person?id=' . $id);
    if (empty($person)) {
      throw new Exception("Person $id not found", 404);
    }

    $this->id = $id;
    $this->first_name = (string)$person->name;
    $this->last_name = (string)$person->surname;
    $this->email = (string)$person->epost;
    $this->sex = (string)$person->sex;

    $this->phone_office = (string)$person->tlf;
    if ($this->phone_office == 'na')
      $this->phone_office = '';
    $this->phone_mobile = (string)$person->mobile;
    if ($this->phone_mobile == 'na')
      $this->phone_mobile = '';

    $this->visit_address_street = (string)$person->address;
    $this->visit_address_zip = (string)$person->postnr;
    $this->visit_address_city = (string)$person->postcode;
    $this->visit_address_country = (string)$person->land;

    $staff = uib_sebra__sws_get('staff?id=' . $id);
    if (!empty($staff)) {
      $this->person_type = 'staff';
      $this->place_code = (string)$staff->place;
      $this->position_name_no = (string)$staff->title;
      $this->position_name_en = (string)$staff->title_english;
      $this->position_code = (string)$staff->code;
      $this->position_category = (string)$staff->title_category;
    }
    else {
      $extern = uib_sebra__sws_get('affiliated?id=' . $id);
      if (!empty($extern)) {
        $this->person_type = 'extern';
        $this->place_code = (string)$extern->place;
        $this->position_name_no = (string)$extern->title;
        $this->position_name_en = (string)$extern->title_english;
        $this->position_category = (string)$extern->title_category;
      }
    }

    $area_roles = uib_sebra__sws_get('omraaderoller?id=' . $id);
    $this->content_manager_areas = array();
    $user_roles = user_roles();
    $this->roles = array();
    $this->roles[DRUPAL_AUTHENTICATED_RID] = $user_roles[DRUPAL_AUTHENTICATED_RID];
    $user_roles = array_flip($user_roles);
    if (!empty($area_roles->administrator)) {
      foreach ($area_roles->administrator->role as $role) {
        $role_group = (string)$role['group'];

        // map "Redaktør" to "Level 2" user (implies also level 3),
        // map "Innholdsprodusent" to a "Level 3" user
        if ($role_group == 'Redaktør') {
          $role_name = 'level 2';
          $this->roles[$user_roles[$role_name]] = $role_name;
          $role_name = 'level 3';
          $this->roles[$user_roles[$role_name]] = $role_name;
        }
        elseif ($role_group == 'Innholdsprodusent') {
          $role_name = 'level 3';
          $this->roles[$user_roles[$role_name]] = $role_name;
        }
        else {
          continue;
        }

        foreach ($role->omraade_kode as $area_code) {
          array_push($this->content_manager_areas, (string)$area_code);
        }
      }

      // make sure the array is unique
      $this->content_manager_areas = array_unique($this->content_manager_areas);
    }
  }
}
