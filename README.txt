w3.uib.no
============

This repository contains the code needed to run the UiB eksternweb application
(to be known as 'http://w3.uib.no' and later take over 'http://www.uib.no).

We use git submodules here, so after the initial clone you need to run:

    git submodule update --init --recursive

to grab the rest of the code to get a working environment.

To set up a test site, configure Apache to serve the 'drupal' directory
at the root of some virtual host.  Having the string 'uib' as part of of the
hostname helps the git ignore rules in the drupal repo.  You might for instance
use a domainname like 'w3.uib.local' set up as an alias for localhost.

Then you need to make sure you have drush installed.

Then set up the drupal site by invoking:

    bin/site-install w3.uib.local

Replace 'w3.uib.local' with whatever hostname you set up.  Visit the site
in a browser to verify that the site works.  The site will be set up with
an 'admin' user with the obvious password.

It will also create a symlink at 'site' linking to the site. The 'site' will be
its own git repo.

The 'doc' directory contains further information you might want to read first.

To fill up the site with some content, migrate data from testbool by invoking
a command like this one:

    bin/site-drush migrate-import --verbose --all

This will import the default test data set (defined by
modules/uib_migrate/test-jur/).  Should finish in a minute or two.

To switch to the 'test-hf' data set run:

    bin/site-drush vset uib_test_dir test-hf

and then run 'migrate-import' once more.

To see what kind of data is available for import you might run:

    bin/site-drush migrate-status
