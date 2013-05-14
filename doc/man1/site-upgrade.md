# Name

site-upgrade -- upgrade the state of the application to match the code in git

# Synopsis

    site-upgrade [<branch>]

# Description

The **site-upgrade** command will upgrade the w3 application to the given
branch/tag.  This involves checking out the code, recompiling the SASS files,
and updating the database.

Without argument **site-upgrade** will upgrade to the tip of `master` branch.

# See also

[site-prod-reset](site-prod-reset.html)

