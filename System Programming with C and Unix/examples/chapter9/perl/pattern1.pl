#!/usr/local/bin/perl
#
# demonstrate pattern search and replace in perl (pg 329)
#
$a="Hello Mr. Frog, how are you?";
$a =~ s/Frog/Turtle/;
print "$a\n";
