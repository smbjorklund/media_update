# Drupal deployment
This describe an deployment on a more and less clean application server.

## Installation
### Prepare installation
* Create an empty database. Follow instruction in INSTALL.pgsql.txt found in Drupal root directory.
* Install the cli tool Drush. Drush is a command line tool to control, setup and change your Drupal installation.
* Require that the Ruby plugin compass is installed *yum install rubygems*  ; *gem update --system*; *gem install compass*.
* Make sure that any needed soft links pointing to your storage area exist during installation (details missing, Mike)
* Please make sure that Drupal’s file areas are correct set up. Apache and the local user that you running drush need write permission. Further reading found on http://drupal.org/security/secure-configuration. Verify that your settings on *admin/config/media/file-system*.

Default drupal PHP stream wrappers are:

* *public://* Area where files are served up directly without bootstrapping drupal access control system.
* *private://* Files in this location is controlled by Drupal access control.
* *tmp://* Drupal temporary area. Examples used during upload of files to drupal.

### Run the production install script
* Run the production installation script *bin/prod-site-install*.

## Post installation
### Security
* Make sure the database permission setting is correct (http://drupal.org/documentation/install/create-database).
* Test and make sure login is only possible on https (example.com/usr and example.com/user/login), http://drupal.org/security/secure-configuration.

### Configuration
* Make sure Drupal cron at desired times, http://drupal.org/cron.
* Drupal generate log entries. Production settings direct Drupal watchdog messages through Drupal core syslog-module. Veriry that system default log behavor dblog module is turned on. Make sure that syslog events is picked up in the infrastructure logging service.
* Check PHP configuration. PHP init. memory and bandwith values are very low and need to be adjusted. Max upload and mem usage, see * ttp://drupal.org/node/97193.
* Make sure locale mail is forwarded. Drupal send/generate email and these are dropped into the local mail system by default PHP mail() and we * eed to make sure they are forwarded correctly and have a valid sender address.*

### Performance
* Verify development module *uib_devel* is off and that production module *uib_prod* is turned on. *uib_prod* define all production settings.

## Data migration
* Sjekk /var/www/lib/php/uib/drupal/setup.php og /var/www/etc/auth.txt

## Configuration changes
Drupal config lives in the database. Modules sometime create it’s own tables but also use the Drupal core variables table to store it's settings. Settings are exported and broken down as feature modules. Feature modules is just like any other module but contain functionality and config. Updates made to these will require us to get the current settings, in the databse, up to sync with that's last git commit.

Theme styling is written in SASS (SCSS) and any updates made to this will require recompile to produce new CSS-files, flushing of caches in all subsystems.

### GIT and submodules.
Get your current code update to date.

* *git submodule update --recursive*
* *bin/site-drush cc all* Flush all your drupal caches. This is make sure that drupal check the db. for it’s runtime settings used by *drush fl*
* *bin/site-drush fl* show the status of the current runtime settings vs latest version from git.
* *bin/site-drush fr name_of_module* Enable you select what module to upgrade.

### Theme changes
* *git submodule update --recursive*

If any changes to the template then compass need to be run.
*cd themes/uib_zen*
*compass compile -c config-prod.rb* This will recompile any SCSS-files updates since last compile.
*bin/site-drush cc all* flush the local Drupal CSS cache.

We also need to make sure to flush our proxy cache servers, aka. Varnish (insert documentation here).
