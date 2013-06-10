# Name

make-drupal -- recreate 'drupal/' from 'drupal.make'

# Synopsis

    make-drupal

# Description

The _drupal.make_ file specifies the core, module, themes and libraries that we use.
This can be used to recreate the _drupal/_ directory using the `drush make` command.

This script runs `drush make` for you and also recreates the links that we have
set up back to the w3 repo to pick up our modules and themes.

Instead of letting `drush make` download the core, this script will clone the core
git repo and use that as base for the repo.  The main reason for this arrangement is
that it makes it easier to research the history of the core code and we need a git repo
for _drupal/_ anyways.

# See also

[module-update](module-update.html)

