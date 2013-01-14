# Drupal deployment
This describe an deployment on a more and less clean application server. Info in there will be moved into GIT as soon as we have a consensus.

## Installation

### Run the production install script.
* Empty database to install into.
* Require that the Drupal system tool drush is installed
* Require that the Ruby plugin compass is installed (yum install rubygems + gem update --system; gem install compass).

## Post installation

* Make sure the database permission setting is correct (http://drupal.org/documentation/install/create-database).
*  Verify development modules and settings is turned on/off uib_devel feature module. Make sure it is off in production.
*  All production settings if turned on/off by the uib_prod feature module. Make sure it is on in production.
*  Test and make sure login is only possible on https (example.com/usr and example.com/user/login), http://drupal.org/security/secure-configuration.
*  Make sure Drupal file area is correct and folder and files have the correct permission and owner. publich:// private:// tmp:// (http://drupal* org/security/secure-configuration). Verify your settings in admin/config/media/file-system.
*  Make sure Drupal cron at desired times, http://drupal.org/cron.
*  Drupal create log entries during normal operation. These are done by Drupal core syslog module. Make sure the site not uses the default * blog module, and that syslog events is picked up in the infrastructure logging service.
*  Check PHP configuration. PHP init. memory and bandwith values are very low and need to be adjusted. Max upload and mem usage, see * ttp://drupal.org/node/97193.
*  Make sure locale mail is forwarded. Drupal send/generate email and these are dropped into the local mail system by default PHP mail() and we * eed to make sure they are forwarded correctly and have a valid sender address.*

## Data migration

* Sjekk /var/www/lib/php/uib/drupal/setup.php og /var/www/etc/auth.txt
