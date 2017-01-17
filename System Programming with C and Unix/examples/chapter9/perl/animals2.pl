#!/usr/local/bin/perl
#
# demonstrate the chomp operator in perl (pg 321)
#
print "Name an animal: ";
chomp($a1=<STDIN>);
print "Name another animal: ";
chomp($a2=<STDIN>);
print "A $a1 and a $a2 go for a walk ...\n";
