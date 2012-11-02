# Server setup

* RHEL6
 * EPEL-repo
 * UiB-RHEL6-Repo

## Dependicy
	yum install http://yum.postgresql.org/9.1/redhat/rhel-6-x86_64/pgdg-redhat91-9.1-5.noarch.rpm
	cat << EOF > /etc/yum/pluginconf.d/rhnplugin.conf 
	[main]
	enabled = 1
	gpgcheck = 1
	exclude=postgresql*
	
	# You can specify options per channel, e.g.:
	#
	#[rhel-i386-server-5]
	#enabled = 1
	#
	#[some-unsigned-custom-channel]
	#gpgcheck = 0
	EOF
	yum clean all
	yum install -y postgresql91.x86_64 postgresql91-libs.x86_64
	yum install -y munin-node git
	yum install -y httpd php php-pgsql php-domxml-php4-php5 php-gd php-mbstring php-ldap
	yum install -y no.uib.it-drush-7x no.uib.it-php.uib

### Drush

Drush installs libraries in a sub-dir. I order to populate the lib, drush is run as root when it's installed. If more libraries is to be installed, Drush must be run as root.

### PostgreSQL

W3 uses PostgreSQL 9.1, therefor we need newer drivers than RHEL 6 supplies

### UiB-php-lib

UiBs php-lib is installed in order to run cron-jobs for integrations of data from other systems.
