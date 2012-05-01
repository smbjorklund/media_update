# Apache developement setup

This just documents how Gisle has set up Apache on OS X to allow local developement.
In the description below replace _username_ with your own.

First you need to enable Apache and PHP.  Apache is enabled from "System Preferences >> Sharing >> Web sharing".
This will start up Apache and set up the _~/Sites_ directory mapped to <http://localhost/~username/>.

The configuration files for Apache is found in the _/etc/apache2_ directory.

Turn on PHP by commenting out the "LoadModule php5\_module" line of _/etc/apache2/httpd.conf_.  Run `sudo apachectl restart`
for the change to take effect.  Test it by creating a _~/Sites/phpinfo.php_ file with this content:

    <?php phpinfo();

and then visit <http://localhost/~username/phpinfo.php>.  If you see a page
full of information about your PHP installation then that part is set up.

During the setup process OS X would have created a _/etc/apache2/username.conf_ file with content like this:

    <Directory "/Users/username/Sites/">
        Options Indexes MultiViews
        AllowOverride None
        Order allow,deny
        Allow from all
    </Directory>

In order for the Drupal apache configuration (its _.htaccess_ file) to take
effect you want to change the `AllowOverride None` to `AllowOverride all`.

After that if you check out a copy of [Drupal](http://drupal.org/project/drupal) somewhere
under _~/Sites_ it should now just work.  You might for instance obtain your
copy like this:

    cd ~/Sites
    git clone --branch 7.x git://git.drupal.org/project/drupal.git

and then visit <http://localhost/~username/drupal> to complete the installation.

Likewise I've chosen to checkout the w3.uib.no tree under _~/Sites_:

    cd ~/Sites
    git clone --recursive git@git.uib.no:site/w3.uib.no.git
    cd w3.uib.no
    bin/site-install w3.uib.local

The w3.uib.no application wants to run from the root of its own domain. Above
I created a site that should run from <http://w3.uib.local>, so I added this
line to my _/etc/hosts_ file:

    127.0.0.1       w3.uib.local

and then I created _/etc/apache2/other/username-vhosts.conf_ with this content:

    NameVirtualHost 127.0.0.1:80

    <VirtualHost 127.0.0.1:80>
        ServerName localhost
        DocumentRoot /Users/username/Sites
    </VirtualHost>

    <VirtualHost 127.0.0.1:80>
        ServerName w3.uib.local
        DocumentRoot /Users/username/Sites/w3.uib.no/drupal
    </VirtualHost>

That's it!
