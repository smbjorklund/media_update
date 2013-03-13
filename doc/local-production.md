# Create a local copy of production

This documentation require that you already have a local installation of W3
running on a separate Postgres database that is separate from your development
installation.  Run this script:

    bin/site-prod-reset

The script assumes that you have ssh access to `attilatest.uib.no`, and that
you have the database on 'glory.uib.no'.  If this is not the case adjust the
parameters at the beginning of the script accordingly.

If you don't know the password for the admin account you can log in by running:

   bin/site-drush user-login
