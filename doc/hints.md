
## Drush

### Alias for site-drush

You will grow tired of invoking `site-drush` the verbose way, so you might want to add this to your `~/.bashrc` file:

    alias d=bin/site-drush


### Quick login from command line

    open $(d uli)
    open $(d uli gaa041)


### ~/.drush/drushrc.php

    <?php
    $options['yes'] = TRUE;

We use for our files and throw-away databases, so avoiding the "Are you sure?"
prompts is really handy.

## Postgres

We will deploy with postgres as our database.  Since the postgres team has no come up
with a test database server where we can create and destroy databases at will, we have
set up our own at glory.uib.no.  On that server you can log in with the username 'user1'.

If you create youself a `~/.pgpass` file with this content:

    glory.uib.no:5432:*:user1:pass1

You will be able to log into that server with 'psql -h glory.uib.no -U user1' and it should
also work to run `site-install w3.uib.local postgres` to set up a new drupal instance on postgres.


## Migration

### Avoid 'Error geocoding - OVER\_QUERY\_LIMIT' problem

It happens when you run 'drush uib-sebra-places' which does a few hundreds geocoding requests to Google in a short period of time.

Geocoding is currently performed by accessing Google API. Varnish (with a looong expire cache time) that caches all results from Google locally. To utilize this you have to override your DNS/hosts config.

Add this line to your /etc/hosts file:
    
    2001:700:200:6::66 maps.googleapis.com
