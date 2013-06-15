# Name

module-update -- update a single module from drupal.make

# Synopsis

    module-update <module-name> [ <version> ]

# Description

The _drupal.make_ file describes the core, modules and libraries
that we use.  These are also commited to the _drupal/_ sub-repo.

Run this script to update or add a single module in _drupal.make_ and refresh the
module in the _drupal/_ repo.

If you don't provide a new _<version>_, then only the refresh of the _drupal/_
repo is made.

If you are happy with the results, commit the change to the _drupal/_ repo and
commit the sub module reference to match.

# See also

[make-drupal](make-drupal.html)

