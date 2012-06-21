[Index](index.html)
***

## Migration workaround

#### Avoid 'Error geocoding - OVER_QUERY_LIMIT' problem
It happens when you run 'drush uib-sebra-places' which does a few hundreds geocoding requests to Google in a short period of time.

Geocoding is currently performed by accessing Google API. Varnish (with a looong expire cache time) that caches all results from Google locally. To utilize this you have to override your DNS/hosts config.

Add this line to your /etc/hosts file:
    
    2001:700:200:6::66 maps.googleapis.com

***
[Index](index.html)