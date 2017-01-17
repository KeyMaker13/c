#!/usr/local/bin/perl
#
# demonstrate reading data from a file in perl (pg 323)
#
open WORLD, "<data1.txt";
$s=<WORLD>;
print "(1) $s";
close WORLD;
