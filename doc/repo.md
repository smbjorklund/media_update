# The source code

We use git to track the code behind `w3.uib.no`.  To check out a copy of the code
run:

    git clone --recursive git@git.uib.no:site/w3.uib.no

If this succeeds it will create a local directory called `w3.uib.no/` with the code.
This requires that you are inside the UiB network and have the right permissions
set up.  Ask Gisle if you have trouble with this.

You can also browse the code repo directly both from
[rts](https://rts.uib.no/projects/w3/repository) and
[cgit](https://git.uib.no/cgit/site/w3.uib.no.git/tree/).  Both these will
require a UiB login for access.

The `--recursive` option used above instructs git to also fetch the submodules
used.  It's needed to get a complete runnable checkout with the full Drupal
core and the contributed modules that we depend on.  Without `--recursive` you
only get "our" code, which is fine if you only need to inspect it.

## Layout

We use 2 repos.  The root repo contains our own code and documentation.  The
directory `drupal/` in the root repo is a git submodule containing a UiB hosted
branch of the Drupal 7.x core with all the contributed modules that our code
depend on.  There are also symlinks back to the parent repo so that Drupal
will be able to locate our code.

This give us a clear separation between our code and the standard Drupal code.
The commit history in the root repo is then only about our code and we have
the full Drupal history in the sub-repo when we need to investigate Drupal
issues.  It's also easy to upgrade Drupal with a simple git merge and to update
modules with drush download.

The cross-repo symlinks are:

    drupal/profiles/uib → profiles/uib
    durpal/sites/all/modules/uib → modules
    drupal/sites/all/themes/uib → themes
    m → drupal/sites/all/modules

The last one is pure convenience as we found a frequent need to inspect
the source code of the modules we used.

Apache will run the PHP code with `drupal/` as the document root, and we
will normally also set up a symlink from `site` to the currently activated
sites directory (matching the virtual host name).  Typically:


    site → drupal/sites/w3.uib.local

This symlink is used by the various `bin/site-*` scripts to manipulate the
activated site.
