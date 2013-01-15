# Drupal deployment
This describe an deployment on a more and less clean application server. Info in there will be moved into GIT as soon as we have a consensus.

## Installation
### Prepare installation
* Create an empty database. Follow instruction in INSTALL.pgsql.txt found in Drupal root directory.
* Install the cli tool Drush. Drush is a command line tool to control, setup and change your Drupal installation.
* Require that the Ruby plugin compass is installed *yum install rubygems*  ; *gem update --system*; *gem install compass*.

### Run the production install script
* Run the production installation script *bin/prod-site-install*.

## Post installation
### Security
* Make sure the database permission setting is correct (http://drupal.org/documentation/install/create-database).
* Test and make sure login is only possible on https (example.com/usr and example.com/user/login), http://drupal.org/security/secure-configuration.

### Performance
* Verify development modules and settings is turned on/off uib_devel feature module. Make sure it is off in production.
* All production settings if turned on/off by the uib_prod feature module. Make sure it is on in production.

### Configuration
* Make sure Drupal file area is correct and folder and files have the correct permission and owner. (http://drupal* org/security/secure-configuration). Verify your settings in *admin/config/media/file-system*.
* *publich://*
* *private://*
* *tmp://*
* Make sure Drupal cron at desired times, http://drupal.org/cron.
* Drupal create log entries during normal operation. In production settings are these done by Drupal core syslog module. Make sure the site not uses the default * blog module, and that syslog events is picked up in the infrastructure logging service.
* Check PHP configuration. PHP init. memory and bandwith values are very low and need to be adjusted. Max upload and mem usage, see * ttp://drupal.org/node/97193.
* Make sure locale mail is forwarded. Drupal send/generate email and these are dropped into the local mail system by default PHP mail() and we * eed to make sure they are forwarded correctly and have a valid sender address.*

## Data migration
* Sjekk /var/www/lib/php/uib/drupal/setup.php og /var/www/etc/auth.txt

## Configuration changes
Drupal config normally lives in the live database. It is exported and broken down as feature modules. Feature modules is just like any other module but contain functionality and config. Updates made to these will require us to get the current settings, in the databse, up to sync with that's last git commit.

Theme styling is written in SASS (SCSS) and any updates made to this will require recompile to produce new CSS-files, flushing of caches in all subsystems.

### GIT and submodules.
Get your current code update to date.

* *git submodule update --recursive*
* *bin/site-drush cc all* Flush all your drupal caches. This is make sure that drupal check the db. for it's runtime settings used by *drush fl*
* *bin/site-drush fl* show the status of the current runtime settings vs latest version from git.
* *bin/site-drush fr name_of_module* Enable you select what module to upgrade.

### Theme changes
* *git submodule update --recursive*

If any changes to the template then compass need to be run.
*cd themes/uib_zen*
*compass compile -c config-prod.rb* This will recompile any SCSS-files updates since last compile.
*bin/site-drush cc all* flush the local Drupal CSS cache.

We also need to make sure to flush our proxy cache servers, aka. Varnish (insert documentation here).
