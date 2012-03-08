w3.uib.no
============

This repository contains the code needed to run the UiB eksternweb application
(to be known as 'http://w3.uib.no' and later take over 'http://www.uib.no).

We use git submodules here, so after the initial clone you need to run:

    git submodule update --init --recursive

to grab the rest of the code to get a working envirionment.

To set up a test site you might want to run something like:

    bin/site-install w3.uib.local

The domain name should be a name your local server accepts and map to this
'drupal' directory.
