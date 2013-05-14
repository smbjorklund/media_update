# Name

site-prod-reset -- restore database state from production

# Synopsis

    site-prod-reset

# Description

The **site-prod-reset** command will sync the files area and the database content
from the latest copy of the production state found at *vengeance.uib.no*, thus the command
requires that you have an account on vengeance.  The copy should never be more than 1 hour
old.

Before you run this command you need to invoke **site-init --postgres** to set up your local site.
After you might want to run **site-upgrade**.

You probably don't want to enter your Unix password 3 times when this command runs.
To avoid that generate an ssh key and install it at vengeance.  The command **ssh-copy-id**
makes that process easier.  On a Mac with Homebrew these steps should work:

    $ brew install ssh-copy-id
    $ ssh-keygen
    $ ssh-copy-id vengeance.uib.no


# See also

[site-init](site-init.html), [site-upgrade](site-upgrade.html)

