#!/usr/bin/perl

use strict;

open(my $fh, "Makefile") || die;
while (<$fh>) {
    print;
    if (/^HTML =/) {
	for (glob('*.md */*.md')) {
	    (my $html = $_) =~ s/\.md$/.html/;
	    print "  $html \\\n";
	}
	print "\n";

	# skip the old entries
	while (<$fh>) {
	    last if /^$/;
	}
    }
}
