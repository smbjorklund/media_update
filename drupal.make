; This file declares what modules are required for the w3 application.
; The 'drupal' directory can be rebuilt from scratch based on this file by
; invoking the 'make-drupal' command (which invokes 'drush make').
;
; Normally you should not edit this file directly.  The 'module-update'
; command is used to upgrade individual modules.
;
core = 7.x
api = 2

;translations[] = nb

; core
projects[drupal][version] = 7.25

; themes
projects[zen][version] = 5.4

; modules
projects[addressfield][version] = 1.0-beta5
projects[admin_menu][version] = 3.0-rc4
projects[advanced_help][version] = 1.1
projects[better_exposed_filters][version] = 3.0-beta3
projects[better_formats][version] = 1.0-beta1
projects[bot][revision] = d0e10c65616f267543e717addc17422979f83bd2
projects[calendar][version] = 3.4
projects[coder][version] = 1.2
projects[context][version] = 3.1
projects[ctools][version] = 1.3
projects[date][version] = 2.7
projects[devel][version] = 1.3
projects[diff][version] = 3.2
projects[entity][version] = 1.3
projects[entity_translation][version] = 1.0-beta3
projects[entityreference][version] = 1.1
projects[entityreference_prepopulate][version] = 1.4
projects[eu-cookie-compliance][version] = 1.12
projects[features][version] = 1.0
projects[features][patch][] = http://drupal.org/files/features-component-list-as-info.patch
projects[feeds][version] = 2.0-alpha8
projects[feeds_xpathparser][version] = 1.0-beta4
projects[field_collection][version] = 1.0-beta5
projects[field_collection][patch][] = https://drupal.org/files/hide-empty-field-collections-1276258-33_0.patch
projects[field_group][version] = 1.3
projects[field_permissions][version] = 1.0-beta2
projects[file_entity][version] = 2.0-alpha3
projects[filecache][version] = 1.0-beta2
projects[flag][version] = 2.1
projects[geocoder][version] = 1.2
projects[geofield][version] = 1.2
projects[geophp][version] = 1.7
projects[google_analytics][version] = 1.4
projects[i18n][version] = 1.10
projects[job_scheduler][version] = 2.0-alpha3
projects[l10n_client][version] = 1.3
projects[l10n_update][version] = 1.0-beta3
projects[ldap][version] = 1.0-beta12
projects[libraries][version] = 1.0
projects[link][version] = 1.2
projects[login_destination][version] = 1.1
projects[markdown][version] = 1.2
projects[media][version] = 2.0-alpha3
projects[media][patch][] = patches/media_7212_fix.patch
projects[media_vimeo][revision] = 81decc73c27764437876a2c9482a66592aa71ffb
projects[media_vimeo][patch][] = https://drupal.org/files/register-video-vimeo-mimetype-1931136-1.patch
projects[media_youtube][version] = 2.0-rc3
projects[menu_admin_per_menu][version] = 1.0
projects[menu_block][version] = 2.3
projects[migrate][version] = 2.4
projects[module_filter][version] = 1.8
projects[override_node_options][version] = 1.12
projects[panels][version] = 3.3
projects[pathauto][version] = 1.2
projects[phone][revision] = 5e0ea65a1f398f0d154aa5ffa71e7add0f63908b
projects[redirect][version] = 1.0-rc1
projects[role_delegation][version] = 1.1
projects[role_export][version] = 1.0
projects[rules][version] = 2.6
projects[scheduler][version] = 1.1
projects[service_links][version] = 2.1
projects[strongarm][version] = 2.0
projects[subpathauto][version] = 1.3
projects[title][version] = 1.0-alpha7
projects[token][version] = 1.5
projects[taxonomy_menu][version] = 1.4
projects[transliteration][version] = 3.1
projects[variable][version] = 2.3
projects[view_unpublished][version] = 1.1
projects[views][version] = 3.7
projects[views][patch][] = https://drupal.org/files/views-3.x-dev-issue_1331056-32.patch
projects[views_bulk_operations][version] = 3.2
projects[views_data_export][version] = 3.0-beta7
projects[views_slideshow][version] = 3.1
projects[wysiwyg][version] = 2.2
projects[wysiwyg][patch][] = https://drupal.org/files/wysiwyg-tinymce-invisible.179482.10.patch

; libraries
libraries[jquery.cycle][download][type] = file
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle/archive/4fffa1d366e964267ca433db9f8bfc83723f04a4.zip

libraries[tinymce][download][type] = file
libraries[tinymce][download][url] = http://download.moxiecode.com/tinymce/tinymce_3.5.8.zip
