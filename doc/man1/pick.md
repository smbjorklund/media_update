# Name

pick -- review & apply rts-branches to master

# Synopsis

    pick [ <rts#> | <branch> | "apply" | "abort" ]

# Description

This script helps with the task of reviewing and applying topic branches for
RTS issues that have status "Ready for review" ("Klar til kontroll" in Norwegian).
These topic branches use names on the form _rts/###_.

The **pick** command takes a single optional argument which is either the RTS
issue number or branch to review, or the words "apply" or "abort" which only
makes sense when already reviewing a specific issue.

Without argument the list of topic branches are simply listed.

To initiate review of an issue run **pick** with the RTS issue number or branch
name as argument.  This will copy the topic branch for this issue as _pick/###_
and try to rebase it against the _master_ branch.  If the rebasing fails you
will need to fix that before proceeding; alternatively just run **pick abort**
to give up on the issue.

If the rebase succeeeds then the list of changes applied for this issue is
listed on the screen.  At this point you can review the patches and use all
available tools to further review and massage the _pick_-branch.  Typical
commands used are:

    $ git log master..
    $ bin/site-upgrade
    $ tig
    $ git rebase -i master
    $ git commit --amend

When happy with the state of this branch just run **pick apply** and the current
state of the _pick_-branch will be prepended on master and pushed, and the
original version of the branch (before rebasing and massaging) will be saved
under the name _origin/picked/###_ and the remote _origin/rts/###_ will be deleted. On
OSX a text message describing the cherry picks that took place is automatically
added to your clipboard and the RTS issue is opened in the browser.  Just
update and paste the text into the comment field and set the issue status to
"Reviewed".

You can work with multiple _pick_-branches at once.  Just use the `git checkout
<branch>` command to move between them and other work.

If the amount of massaging you are willing to do can't save the branch just run
**pick abort** to restore everything to the original state, and write down your
complains in the RTS issue.


# See also

[rts](rts.html)

