# Development setup

This document explains how to set up your box so that you can start hacking on
the w3.uib.no application.

## Software and Tools

Before we start we need make sure we have the following tools installed and set up.
This section explains how to obtain the tools on Mac OSX.  How to do the same on Linux
is left as an exercise for the interested reader.

### Git

Start by installing Xcode (from the AppStore).  Then open "Xcode >
Preferences... > Downloads > Components" and make sure the "Command Line
Tools" are installed.  This will install make, C compilers, and git.

### Apache

Apache is bundled with Mac OSX.  To enable it just run [`sudo apachectl
start`](http://superuser.com/questions/455505/how-do-i-start-apache-in-osx-mountain-lion).
This will both start up Apache and make sure it's enabled on the next system
reboot.  The configuration files for Apache is found in the _/etc/apache2_ directory.

Verify that it works by visiting <http://localhost>.

### PHP

PHP is bundled with Mac OSX, but not enabled in Apache by default.  To enable it
remove the '#' mark in front of the "LoadModule php5\_module" line of
_/etc/apache2/httpd.conf_.  Run `sudo apachectl restart` for the change to take
effect.

Verify that it works by running:

    echo "<?php phpinfo();" >/Library/WebServer/Documents/phpinfo.php

and then visit <http://localhost/phpinfo.php>.

### Drush

Download the latest 7.x-version from <http://drupal.org/project/drush>.  Unpack
it and either add the directory to the PATH or set up a symbolic link to
_drush-7.x-*/drush_ from somewhere in your PATH.  Run `drush version` to verify
that it works.

Alternative clone the sources with git, and check out the latest 7.x-release:

    cd ~
    git clone http://git.drupal.org/project/drush.git
    git checkout $(git tag | grep 7.x-5 | tail -1)
    cd ~/bin
    ln -s ~/drush/drush

### Compass

The [compass program](http://compass-style.org/) is required to compile the
style sheets.  Compass is a Ruby program and is installed as a Ruby package
using the `gem` tool.

    gem update --system
    gem install compass

Run 'compass --version' to verify that it works.

It's a good idea to not pollute the system version Ruby with added packages.  Because
of that many will prefer to use [Homebrew](http://mxcl.github.io/homebrew/) to install
a new Ruby and install gems into that that one.

## Set up the application

### Grab the sources

Go somewhere you prefer to have your code checked out (we use _/tmp_ in the
following example, but you can probably come up with something better).
Then run:

    cd /tmp
    git clone --recursive git@git.uib.no:site/w3.uib.no
    cd w3.uib.no

This should give you our sourced user _/tmp/w3.uib.no_ and a Drupal instance
for Apache to serve at _/tmp/w3.uib.no/drupal_.

### Set up w3.uib.local

The w3.uib.no application wants to run from the root of its own domain, so we need
to enable a VirtualHost to serve the checked out directory.  The recommended name
is <http://w3.uib.local>.

First we add an entry for this name in the _/etc/hosts_ file:

    127.0.0.1       w3.uib.local

Then we create the file _/etc/apache2/other/w3.uib.no-vhosts.conf_ with this content:

    NameVirtualHost 127.0.0.1:80

    <VirtualHost 127.0.0.1:80>
        ServerName w3.uib.local
        DocumentRoot /tmp/w3.uib.no/drupal
    </VirtualHost>

    <Directory "/tmp/w3.uib.no/drupal">
        Options Indexes MultiViews
        AllowOverride all
        Order allow,deny
        Allow from all
    </Directory>

Then run `sudo apachectl restart` and visit <http://w3.uib.local> to verify that it
works.  You will get into the Drupal install dialog, which we will not use. We'll
install the site from the command line instead:

    cd /tmp/w3.uib.no
    bin/site-install w3.uib.local
    bin/site-drush pm-enable --yes uib_devel

Then goto  <http://w3.uib.local> once more.  You should now see the empty front page
of the w3 application and you can [login](http://w3.uib.local/user) as _admin:admin_.
