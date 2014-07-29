# Coding standards

This documents our rules for naming things and the code layout to use.

## Naming

We use English words as basis for naming stuff.  The [terminology list](terms.html)
might be helpful for translating names if you only know what it’s called in Norwegian.

The site specific modules (those we write ourself) all get `uib_` as prefix.
An exception is the `uibx` module.

All these modules should have the `package` set to the value `"UiB"`.  This
ensures that they are listed together on the modules page.

The `uib_` modules should be placed in the *modules/* directory (linked from *drupal/sites/all/modules/uib*).
Other contributes modules are installed under *drupal/sites/all/modules* (the standard install location
for `drush dl <mod>`).

Resources that our modules create that need _machine names_ should all get `uib_` as prefix.
This includes bundles, fields and views.

PHP functions use names on the form `foo_bar_baz()`.

PHP constants use names on the form `FOO_BAR_BAZ`.

PHP classes use names on the form `FooBarBaz`.  If _UiB_ is one of the words in the class name, then we write it as `Uib`.  This makes the identifier easier to read as it’s no ambiguity where the next word starts.

PHP attributes (class members) use names on the form `$foo_bar_baz`.

Helper functions in modules get the module name followed by `__` (double underscore) as prefix.
For instance the module `uib_foo` will use function names like `uib_foo__helper`.
The double underscore ensures that we don’t end up defining hooks by accident.

## PHP, JS, CSS (SASS)

We follow the [Drupal core coding standard](http://drupal.org/coding-standards).

* Indent of 2 *&lt;spaces>*.  Avoid *&lt;tab>* and trailing whitespace in the source files.
* PHP source files starts with `<?php` on a separate line, but we don’t terminate the files
  with a matching `?>`.  This is good practice as it avoids that any trailing whitespace
  would then be printed when the file is loaded.
* Comments on a line start with `//` (not `#`).
* Strings are quoted with `'...'`.  Only use `"..."` when there are variables to be
  interpolated in the string.

Hooks are always witten on the form:

    /**
     * Implements hook_foo().
     */
    function uib_xxx_foo(...) {
      ...
    }

Large literal arrays are written in this format:

    $foo = array(
      'first' => 1,
      'second' => 2,
      'third' => array(
        '#foo' => 'xxx',
        '#bar' => 'yyy',
      ),
      'fourth' => 4,
    );

## Git commit message format

What’s most important about a commit message is that it describes *why* the change was made.
Even if the message reference some RTS issue, don’t let readers have to look up the
issue to understand what the benefit of this change is.

You normally will not have to explain what was done if it’s obvious from the
source file diff. Write the commit message assuming that the reader also see
the diff at the same time.

The lines of a commit message should not be longer than 72 characters. The
first line should preferably be even shorter. Write clear, short and concise
text.

If you need longer descriptions use this format:

    Short summary of change
    (empty line)
    Explain why this change was made and other details about the change.
    yadayada, bla, bla.

All commit messages should be written in English.

Commits should in general be justified by and related to some
[RTS](https://rts.uib.no/projects/w3) issue.
The convention is that you prefix the commit message with `RTS-####`
to connect them.  The commit message will then have this form:

    RTS-#### Short summary of change
    (empty line)
    ...

Replace `####` with the issue number ;-)
