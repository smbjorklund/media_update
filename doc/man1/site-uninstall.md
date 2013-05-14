# Name

site-uninstall -- remove the site

# Synopsis

    site-uninstall [--discard]

# Description

This script removes the current site in the `drupal/sites/` directory.  The
default behaviour is to dump the database content to a file and then rename the
old site by including a timestamp in it's name.

The following options are recognized:

### --discard

Just delete the old site.  If the application has created files as the Apache
user this might fail and you might have to retry the command as `sudo site-uninstall --discard`.

# See also

[site-init](site-init.html)

