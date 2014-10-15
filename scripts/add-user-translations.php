<?php
/**
 * Check if users' translations for both English and
 * Norwegian languages are ativated. Add if missing.
 */
$trans = 0;
$query = new EntityFieldQuery();
$result = $query->entityCondition('entity_type', 'user')->execute();
if (!empty($result['user'])) {
  $user_list = array_keys($result['user']);
  $chunk = 1000;
  while ($subset = array_splice($user_list, 0, $chunk)) {
    $users = entity_load('user', $subset);
    foreach ($users as $uid => $user) {
      if ($uid > 1) {
        $handler = entity_translation_get_handler('user', $user);
        $translations = $handler->getTranslations();
        if (!empty($translations->data)) {
          if (count($translations->data) == 1) {
            if ($translations->original == 'en') {
              $translation = array(
                'status' => 1,
                'language' => 'nb',
                'source' => 'en',
              );
              $handler->setTranslation($translation);
              user_save($user);
              $trans++;
            }
          }
        }
      }
    }
  }
}
uibx_log("Initiated 'nb' translation for $trans users");
