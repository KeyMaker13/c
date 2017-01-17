#!/usr/local/bin/perl
#
# demonstrate basic I/O in perl (pg 321)
#
print "Name an animal: ";
$a1=<STDIN>;
print "Name another animal: ";
$a2=<STDIN>;
print "A $a1 and a $a2 go for a walk ...\n";
