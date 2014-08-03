# W3 Developer Documentation

The w3 site is the 3rd generation implementation of [www.uib.no](http://www.uib.no).
It was introduced in 2013 and by fall 2014 it had replaced all of w2.
The site is implemented in [Drupal 7](http://drupal.org).

These pages documents the system from a developer perspective.
If you want to use the system and manage content you’re better off reading the
[User and Editor Documentation Site](http://w3docs.h.uib.no/).

## Understanding the content structures

<a href="model.html"><img src="img/model-simple.svg" alt="Diagram showing a simplified view of main content types" style="float: right; width: 120px; padding-left: 2ex; padding-bottom: 1ex;"></a>
To be able to make sense of the code you should first understand the structure
of the content that makes up the web site.
The simplified view is shown here.
The central concepts are _areas_, _articles_ and _OUs (organisational units)_.
All of these represented as nodes.

The site is divided into sub-sites, but instead of _sub-site_ we say _area_.
It’s at least shorter. Each area get their own page on the web, their own set
of articles, and their own menu.

The OUs represent the organisational structure of university as seen by the
official systems (originates in the personnel system Paga). Areas are always
connected to the OU that own them.  Many areas are the site of the OU itself,
which make it tempting to conflate these two concepts.  Don't do that.

Articles contains the textual content of the site, and appear in the form of
news articles, pages, events, and others.  Articles belong to an area and are
presented using the area’s header, side-bar and footer.  Articles also get URLs
that make them appear as subordinates of an area.

The [details of the content structures](model.html) is of course more complex than this and
is explained in a separate document.  The [terminology of this
project](terms.html) should also be understood.

<br style="clear: both;">

## Understanding the code

To understand the code you need to understand [Drupal 7](http://drupal.org)
and the principles of its [API](http://api.drupal.org).

Our source code is managed by Git in two repositories.  The root repository
contains our code and a separate sub-repository tracks the version of Drupal
and contributed modules we use.
[Details of the repository layout](repo.html) is explained in
a separate document.
You can browse the git repository on the web from either
[RTS w3 repository](https://rts.uib.no/projects/w3/repository) or
[cgit w3 repository](https://git.uib.no/cgit/site/w3.uib.no.git/tree/).

The configuration managed and used by Drupal comes from the database. We use
the [features module](http://drupal.org/project/features) to capture this
configuration as code and to restore configuration from code. This allow us to
manage versions and releases from Git. We also write our own code, and all of
this is organized in a set of [site specific Drupal modules](modules.html).

## Changing code

Development involves changing code to improve it.
Every proposed change should first have an [RTS issue](https://rts.uib.no/projects/w3/issues)
describing a new feature, a bug, or an improvement to the structure of the code.
For new features, the issue should explain the rationale for the proposed
new function and suggest how it might be implemented.  A bug report
should explain how somebody would go about verifying that the bug is no more.
Screen shots are valuable.

The registered issues in RTS is our backlog of things to do.

Before changing anything should should be familiar with [our naming and coding
style guide](style.html).  The main point of it is to use English identifiers,
add uib\_ as prefix to machine names, and otherwise follow the code layout
style that the Drupal core uses.  If you have not established your [development
environment for w3](development-setup.html) yet do it.

_\*\*\* TODO_ Describe these steps:

* How to decide on what to do.
  Issues assigned to the current release have priority.
* Decide to work on some issue; set the status of the issue to "In progress".

* Checkout the master branch and and make sure you still have a running w3
  application.
* Create an rts/\* branch.
* Commit the fixes to the branch.
* Push the branch back to the server.
* Set the status of the issue to "Ready for review".
* If the issue after review is set back to "In progress" it means that
  something is wrong.  Fix the problem and set the issue back to "Ready for
  review".

Special concerns:

* Changes to configuration (capture new setting by features, update features).
* Changes that are small enough to not require an RTS issue.
* Documentation


## Reviewing code

Code on the rts/\* branches require review before it's cherry-picked or merged
to the master branch.

_\*\*\* TODO Describe how it‘s done._


## Releases

The current [release process](release-process.html) (documented in Norwegian)
is to aim for new releases every 14 days as documented in our [release
notes](release-notes.html) (also in Norwegian).  The [release notes for the
current version](http://w3.uib.no/webdesk/release-notes) is published by the w3
site itself.

## Guides

* [Coding style](style.html)
* [Terminology](terms.html)
* [Development setup](development-setup.html)
* [Reder Arrays](render-array.html)
* [Hints that’s good to know](hints.html)
* [Git hints](git.html)
* [fs-pres](fs-pres.html)


## Reference

* [Manpages  for commands](man1/index.html)
* [Repo README](repo-readme.html)
* [Git](https://rts.uib.no/projects/w3/repository) and [cgit](https://git.uib.no/cgit/site/w3.uib.no.git/tree/)
* [API docs](api/files.html) generated by Doxygen
* [RTS](https://rts.uib.no/projects/w3)

### Stats and Logs

* [404-list and errorlogs](http://overvakning.app.uib.no/w3_logs/)
* [Staging log](http://attilatest.uib.no/status/drupal-daily-staging.last.txt)
* [Piwik stats](http://stats.uib.no/)
* [Awstats](http://overvakning.app.uib.no/awstats/awstats.pl?output=main&config=www.uib.no)
* [Munin](http://overvakning.app.uib.no/w3_hist.php?limit=2)

## Operational concerns

* [Deploy Drupal into production](drupal-deploy.html)
* [How to upgrade Drupal on w3.uib.no](drupal-update.html)
* [Production server layout](w3_server_layout.html)
* [Production setup](server-setup.html)
* [Course server setup](course_site-w3-kurs.uib.no.html)
  and [syncing](drupal-sync-course-site.html)


## Historic specifications

* [Initial spesification](spec.html) as of early 2012
* [Release 1](release1.html) med [innspill fra pilotfakultetene](doc/pilot-ny-funksjonalitet.pdf)
* [Area regions and fields](area.html)
* [Mockups](mockups/)
