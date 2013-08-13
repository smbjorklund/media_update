# fs-pres.app.uib.no

We plan to use [fs-pres.app.uib.no](http://fs-pres.app.uib.no) as our interface
to information about Study Programmes and Courses.

## The fs-pres site

The [fs-pres site](http://fs-pres.app.uib.no) is a Django application.
The code lives in the `site/fs_pres.app.uib.no.git` repo.
It uses SQLite as database and the latest version of that database is commited to the
source repo directly (as `var/site.db.gz`).

Updates to the databasebase is currently a manual process.  The README.txt file
explains how to sync the fs-pres database with FS.  Normally just done in
a developer instance of fs-pres and then the compressed `var/site.db` is
commited to the repo and unpacked on _real_.

### Installation on real

The actual site lives in the `/var/www/applications/fs-pres` on _real.uib.no_.
This is a clone of the source repo.

Apache serving fs-pres.app.uib.no host is configured to forward all requests
to http://localhost:8083/ where the application runs under 'paster serve'.
Use the `/etc/init.d/fs-pres` script to start, restart or stop the service as root.

## Integration with w3

The study programs and courses are represented in w3 as the content type `uib_study`.  This currently
contains the information required to create various lists using views.  The presentation pages are still
served from w2, so no further integration with fs-pres is implemented currently.

The `uib_study` content type has the following fields:

* language ('nb' or 'en')
* field\_uib\_study\_code (eg 'INF101')
* title
* field\_uib\_study\_type ('program' or 'course')
* field\_uib\_study\_category ('phdprogram','bachelorprogram', 'undergraduate', 'masterprogram', ...)
* field\_uib\_ou (which organisation unit does it belong to)

The nodes are kept up-to-date by running the `drush uib-sync-fs` command (provided by the `uib_study` module).
This is currently invoked from the `etc/cron.daily/cron-drupal-sync-fs` script.  Thus w3 will update automatically
within a day after fs-pres has been updated.
