The problem with user stubs was caused by migrate and the user synch 
with Sebra. These are not aware of each other, and one or the other
will add users regardless of the other's book-keeping data.

The userfix script will look for "User stubs" inserted during migration and 
will attempt to find the user if it has been added by the Sebra synch, and
joins the two, moving any article content etc. 

These two scripts are supposed to be copied into the "drupal" directory (where
the index.php file is), and run from the web browser:

Example:

http://w3.uib.local/check_stubs.php

and

http://w3.uib.local/userfix.php

Inside the script, the variable $be_verbose is by default set to TRUE, which 
results in some information ouput along the way.

The scripts are very similar, except that check_stubs does not change 
anything, it just checks the current status. It may be a good idea to run 
the check before the userfix.
