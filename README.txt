w3.uib.no
============

This repository contains the code needed to run the UiB eksternweb application
(to be known as 'http://w3.uib.no' and later take over 'http://www.uib.no').

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

It will also create a symlink at 'site' linking to the site. The 'site' will be its own git repo.

The 'doc' directory contains further information you might want to read first.

To fill up the site with some content, migrate data from teststring by invoking a command like this one:

    bin/site-drush migrate-import --verbose --all
    bin/site-drush uib-migrate-build-menu --verbose

This will import the default test data set (defined by modules/uib_migrate/test-jur/)
and fill in the area menu.  Should finish in a minute or two.

To switch to the 'test-hf' data set run:

    bin/site-drush vset uib_test_dir test-hf

and then run 'migrate-import' once more.  To migrate all data run:

    bin/site-drush vset uib_test_dir ALL

To migrate all data for certain area. Create a text file containing a list of areas (one on each line). Store the file in  modules/uib_migrate/ folder. Then run:

    bin/site-drush vset uib_test_dir ALL
    bin/site-drush migrate-import --verbose --all --strict=0 --area_subset=your_file_name

Example: Migrate all content of jur and hf to your site but running:

    bin/site-drush vset uib_test_dir ALL
    bin/site-drush migrate-import --verbose --all --strict=0 --area_subset=uib_areas_subset_jurhf.txt
    bin/site-drush uib-migrate-build-menu --verbose

To see what kind of data is available for import you might run:

    bin/site-drush migrate-status

To enable the Norwegian interface translations run (it's not part of the regular install since it's quite slow):

    bin/update-norsk

If your a developer you probably also want to enable the 'uib_devel' module.
This sets up some testing accounts and arrange for various conveniences
for inspecting the site.  Just run:

    bin/site-drush pm-enable --yes uib_devel
