
## Drush

### alias d=bin/site-drush

You will grow tired of invoking `site-drush` the verbose way.


### Quick login from command line

    open $(d uli)
    open $(d uli gaa041)


### ~/.drush/drushrc.php

    <?php
    $options['yes'] = TRUE;

We use for our files and throw-away databases, so avoiding the "Are you sure?"
prompts is really handy.


## Migration

### Avoid 'Error geocoding - OVER\_QUERY\_LIMIT' problem

It happens when you run 'drush uib-sebra-places' which does a few hundreds geocoding requests to Google in a short period of time.

Geocoding is currently performed by accessing Google API. Varnish (with a looong expire cache time) that caches all results from Google locally. To utilize this you have to override your DNS/hosts config.

Add this line to your /etc/hosts file:
    
    2001:700:200:6::66 maps.googleapis.com
