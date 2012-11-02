#!/bin/bash
if [ $(cat /etc/redhat-release |grep 'Red Hat Enterprise Linux Server release 6'|wc -l) -lt 1 ]
then
echo ERROR: Only RHEL6 >/dev/stderr
exit 1
fi
yum install http://yum.postgresql.org/9.1/redhat/rhel-6-x86_64/pgdg-redhat91-9.1-5.noarch.rpm
cp -a  /etc/yum/pluginconf.d/rhnplugin.conf  /etc/yum/pluginconf.d/rhnplugin.conf.bak-$(date -I)
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
yum install -yq postgresql91.x86_64 postgresql91-libs.x86_64
yum install -yq munin-node git
yum install -yq httpd php php-pgsql php-domxml-php4-php5 php-gd php-mbstring php-ldap
yum install -yq no.uib.it-drush-7x no.uib.it-php.uib
