#!/usr/bin/perl -w

use strict;

my %pick_functions;
for my $f (qw(
    menu_parent_options
    _menu_get_options
    _menu_parents_recurse
    menu_form_node_form_alter))
{
    my $to = $f;
    $to =~ s/^(_?)menu_/$1uib_menuparents_/;
    $pick_functions{$f} = $to;
}

open(my $in, "../../drupal/modules/menu/menu.module") || die;
open(my $out, ">uib_menuparents.module") || die;

print $out <<EOT;
<?php
/**
 * This code was copied from menu.module, namely the functions:
EOT

print $out " *   $_\n" for sort keys %pick_functions;

print $out <<EOT;
 *
 *  The reason was to be able to override a hard-coded setting in _menu_parents_recurse(),
 *  which truncates parent menu item titles to 30 characters.
 *  Cf. http://drupal.org/node/1166282
 */

EOT

while (<$in>) {
    next unless (/^function (\w+)/ && $pick_functions{$1}) .. /^}/;
    s/(\w+)/$pick_functions{$1} || $1/ge;
    s/\b30\b/94/ if /truncate_utf8/;
    print $out $_;
}
