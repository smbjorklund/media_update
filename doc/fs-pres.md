# fs-pres.app.uib.no

We use [fs-pres.app.uib.no](http://fs-pres.app.uib.no) as our interface
to information about Study Programmes and Courses.

## The fs-pres site

The [fs-pres site](http://fs-pres.app.uib.no) is a Django application.
The code lives in the `site/fs_pres.app.uib.no.git` repo.
It uses SQLite as database.

### Installation on vengeance

The real site will eventually be installed on a new py-box.

A test installations runs on vengeance (under the name fs-pres.test.uib.no).

Apache serving fs-pres.test.uib.no host is configured to forward all requests
to http://localhost:8083/ where the application runs under 'paster serve'.
Use the `/etc/init.d/fs-pres` script to start, restart or stop the service as root.

## Integration with w3

The study programs, specializations and courses are represented in w3 as the content type `uib_study`.  This currently
contains the information required to create various lists using views.

The `uib_study` content type has the following fields:

* language ('nb' or 'en')
* field\_uib\_study\_code (eg 'INF101')
* title
* field\_uib\_study\_type ('program', 'specialization' or 'course')
* field\_uib\_study\_category ('phdprogram','bachelorprogram', 'undergraduate', 'masterprogram', 'evu', ...)
* field\_uib\_ou (which organisation unit does it belong to)

The nodes are kept up-to-date by running the `drush uib-sync-fs` command (provided by the `uib_study` module).
This is currently invoked from the `etc/cron.daily/cron-drupal-sync-fs` script.  Thus w3 will update automatically
within a day after fs-pres has been updated.
