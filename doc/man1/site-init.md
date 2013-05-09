# Name

site-init -- initialize the site

# Synopsis

    site-init [options] [site-name]

# Description

This script initializes a new site under the `drupal/sites/`
directory.  This involves generating a `settings.php` file for
drupal which defines what database to use.  We also set up the `site`
link that all the other site-\* scripts use to determine what site
to operate on.  This script does not modify the database.
After intialization use the *site-install* script to install the
application from scratch or *site-prod-reset* to fill up the database
with a copy of the current production database (and files).

The site name defaults to w3.uib.9zlhb.xip.io (which resolves to 127.0.0.1 aka localhost).

The following options are recognized:

### --force

Force initialization even if there is already a site present.

### --fresh

Don't try to preserve the site name and database settings from the current site.
Use the defaults.

### --discard

Don't backup the old site before creating a new one.  Just remove it.

### --sqlite

Shortcut for **--driver sqlite**

### --postgres, --pgsql

Shortcut for **--driver pgsql**

### --driver [ "sqlite" | "pgsql" | ... ]

This selects what kind of database driver to use.  For "sqlite" and "pgsql" this
will also provide defaults for the other database parameters.  For Postgres
the defaults are user1:pass1@localhost/db1 or user1:pass1@glory.uib.no/$USER-db1.
The first one is selected if some server listens on localhost.
For sqlite the default database file is `site/files/db.sqlite`.

### --host _name_

The hostname where the database server lives.

### --port _num_

The port at hostname where the database server listens.  Doesn't have to be provided
if the database listens on the default port.

### --database _name_

The database name on the given server.  For sqlite this is the path to the database file.

### --username _name_

The username user for the database.  Defaults to "user1".

### --password _pass_

The password used to log into the database.  Defaults to "pass1".

# See also

[site-install](site-install.html), [site-prod-reset](site-prod-reset.html).

