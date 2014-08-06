# Workflow

## Developer

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

## Reviewer

Code on the rts/\* branches require review before it's cherry-picked or merged
to the master branch.

_\*\*\* TODO Describe how it‘s done._

## Tester

_\*\*\* TODO_
