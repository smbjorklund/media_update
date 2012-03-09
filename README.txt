w3.uib.no
============

This repository contains the code needed to run the UiB eksternweb application
(to be known as 'http://w3.uib.no' and later take over 'http://www.uib.no).

We use git submodules here, so after the initial clone you need to run:

    git submodule update --init --recursive

to grab the rest of the code to get a working envirionment.

To set up a test site, configure Apache to serve the the 'drupal' directory
at the root of some virtual host.  Having the string 'uib' as part of of the
hostname helps the git ignore rules in the drupal repo.  You might for instance
use a domainname like 'w3.uib.local' set up as an alias for localhost.

Then set up the drupal site by invoking:

    bin/site-install w3.uib.local

Replace 'w3.uib.local' with whatever hostname you set up.  Visit the site
in a browser to verify that the site works.  The site will be set up with
an 'admin' user with the obvious password.

It will also create a symlink at 'site' linking to the site. The 'site' will be
its own git repo.

The 'doc' directory contains further information you might want to read first.
