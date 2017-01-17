#!/usr/local/bin/perl
#
# Demonstrate various operators in search and replace (pg 331)
#
$a="Hello Mr. Frog, how are you?";
$a =~ s/r./oo/g;
print "$a\n";
$a="Hello Mr. Frog, how are you?";
$a =~ s/r\./rs\./;
print "$a\n";
$a="Hello Mr. Frog, how are you?";
$a =~ s/el*o/ezo/;
print "$a\n";
$a="Hello Mr. Frog, how are you?";
$a =~ s/l+/z/;
print "$a\n";
