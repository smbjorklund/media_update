
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

We use git for our files and throw-away databases, so it usually doesn't matter if drush overwrite
some files.  Skipping manual confirmation on all the "Are you sure?" prompts is a time saver.

## Postgres

### Running into resource limitation in your local sandbox
Example. You try to drop all your database tables from drush.

    bin/site-drush sql-drop
    Do you really want to drop all tables? (y/n): y
    psql:/private/tmp/drush_bGSS68:1: WARNING:  out of shared memory
    psql:/private/tmp/drush_bGSS68:1: ERROR:  out of shared memory
    HINT:  You might need to increase max_locks_per_transaction.

#### Locate your database config
Postgresql installed with homebrew is normally found at

    /usr/local/var/postgres/postgresql.conf

Locate your increase max_locks_per_transaction entry, a higher number like 128 might be sutible. Changing this require that you restart your database server.

#### Running out of kernel space (SHMMAX)
Starting your database might now throw an error:

    FATAL:  could not create shared memory segment: Invalid argument
    DETAIL:  Failed system call was shmget(key=5432001, size=4390912, 03600).
    HINT:  This error usually means that PostgreSQL's request for a
    shared memory segment exceeded your kernel's SHMMAX parameter.

    You can either reduce the request size or reconfigure the kernel
    with larger SHMMAX. To reduce the request size (currently
    4390912 bytes), reduce PostgreSQL's shared memory usage, perhaps
    by reducing shared_buffers or max_connections.

    If the request size is already small, it's possible that it is
    less than your kernel's SHMMIN parameter, in which case raising
    the request size or reconfiguring SHMMIN is called for.

You can locally test this by running the following:

    sudo sysctl -w kern.sysv.shmall=65536
    sudo sysctl -w kern.sysv.shmmax=16777216

To permantly add this to your computer (OS X), add the following to your /etc/sysctl.conf. Create the file if you don't allready have it.

      kern.sysv.shmall=65536
      kern.sysv.shmmax=16777216

## Git

Unngå unødvendige "Merge branch ..." commits i historien.  Kjør denne kommandoen én gang:

    git config branch.master.rebase true

Alternativet er å huske å bruke 'git pull --rebase' hver gang.

Andre anbefalte konfigurasjoner:

    git config --global alias.co checkout
    git config --global color.ui auto
    git config --global core.pager less -+S

## Migration

### Avoid 'Error geocoding - OVER\_QUERY\_LIMIT' problem

It happens when you run 'drush uib-sebra-places' which does a few hundreds geocoding requests to Google in a short period of time.

Geocoding is currently performed by accessing Google API. Varnish (with a looong expire cache time) that caches all results from Google locally. To utilize this you have to override your DNS/hosts config.

Add this line to your /etc/hosts file:
    
    2001:700:200:6::66 maps.googleapis.com
### Avoid getting PHP nesten level error running with xdebug

    ini_set('xdebug.max_nesting_level', 200);

