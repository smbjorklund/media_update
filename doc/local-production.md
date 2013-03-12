# Create a local copy of production
This documentation require that you already have a local installation of W3 running on a separate Postgres database that is separate from your development installation.

## Get all your files
Quickest way of getting all your files and keeping them in sync with production is by running rsync through ssh.

### Rsync your Drupal files directory
    rsync -aihH --delete user-name@attilatest:/prod_nettapp_w3/sites/w3.uib.no/files/ /your-local-installation/drupal/sites/uib.dev/files/

## Postgres configuration
First time you set this up you also need to create two postgres users in your local database.
* w3\_user Regular user with no drop permission etc.
* w3\_admin User Drupal run as locally.

### Grab the nightly database backup
    rsync -aihH user-name@attilatest:/prod_nettapp_w3/pg_dump/w3.uib.no.sql your-preferred-download-directory

### Populate your local staging databse
    psql local-staging-database-name < w3.uib.no.sql
You normally to not need to provide any user name and password in the above example if your .pgpass file is correctly set up.

## Putting is all together
You are now close to complete, very close. You need to make sure that Drupal now find your files. Create an symlink from your site install directory to w3.uib.no
    cd drupal/sites
    ln -s your-install-dir w3.uib.no
Flush all your caching data
    site-drush cc all -v

You should now have a working running clone of production that is easy and quick to keep up2date.
