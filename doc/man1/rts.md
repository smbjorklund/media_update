# Name

rts -- script frontend to the rts.uib.no service

# Synopsis

    rts update [--full]
    rts [show] [--json] <id>...
    rts release
    rts release <rid> [--patches]
    rts list [--open] [--patches]
    rts branches
    rts merge-status <id>
    rts extract

# Description

The **rts** command provides an interface for reporting on the issues belonging
to the w3 project in RTS.

## Subcommands

The following subcommands are recongnized:

### rts update

Download information about the issues of the w3 project from <http://rts.uib.no>.
All the other commands only consult the internal cache of issues.

### rts show

Display information about the given issue

### rts release

Display the issues belonging the the given release.  Without any given release, display
list of releases available.

### rts list

Display list of all the issues of the w3 project

### rts branches

Show the RTS-branches available in git.

### rts merge-status

Display the merge-status for the given issue.  This can be useful for pin-pointing
the reason for merge conflicts against the master branch.

### rts extract

Reads text on stdin and recognizes references to RTS-issues.
In the end it lists those issues.

## Options 

The following options are recognized:

### --full

Only used together with the **rts update** command.
Sync both opened and closed issues.  The default is to only sync
the opened issues.

### --json

Generate output in [JSON](http://www.json.org) format.

### --patches

Show what patches are available for the given issue.

# See also

[patches](patches.html)

