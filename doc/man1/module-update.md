# Name

module-update -- update a single module from drupal.make

# Synopsis

    module-update <module-name>

# Description

The _drupal.make_ file describes the core, modules and libraries
that we use.  These are also commited to the 'drupal' sub-repo.

To update a module edit the required version in _drupal.make_ and then run this
script with the module name as argument.  That will update the module.  If you are
happy with the results, commit the change to the drupal repo and move the sub module
reference to match.

# See also

[make-drupal](make-drupal.html)

