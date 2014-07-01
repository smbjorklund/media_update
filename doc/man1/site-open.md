# Name

site-open -- open browser window with current site

# Synopsis

    site-open [path]

# Description

The **site-open** command prints the URL of the current site and then opens up
a browser window with the current site (Mac OS X only).

If _path_ is provided append it to the site URL.  If the _path_ doesn't have
a language prefix `nb/` is inserted.

If a full URL is provided as _path_, then the scheme and domainname part is
stripped off first. This allow you to just cut&paste URLs from external
website, staging server, etc.  Handy when trying to follow URLs in bug reports.

# See also

[site-init](site-init.html)

