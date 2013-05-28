# Name

site-prod-reset -- restore database state from production

# Synopsis

    site-prod-reset [ <release> ]

# Description

The **site-prod-reset** command will sync the files area and the database content
from the latest copy of the production state found at *vengeance.uib.no*, thus the command
requires that you have an account on vengeance.  The copy should never be more than 1 hour
old.

You might also select a given release to sync with.  This will sync with the
last dump generated for that release before it was upgraded to the next.
Releases are identified by a release number (like "1.4") or a date (in YYYY-MM-DD format).
The available releases can be listed by running the **release-dumps** command.
Note that the *site/files* are still restored to the latest version, as we don't
store away snapshots of them when upgrading —
let's hope that files collection only grows so this doesn't really matter.

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

