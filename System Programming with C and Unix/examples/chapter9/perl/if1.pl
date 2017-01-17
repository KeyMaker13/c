#!/usr/local/bin/perl
#
# demonstrate if statements in perl (pgs 328-329)
#
foreach (1,2,"turtle","frog")
  {
  if ($_ >= 2)
    {
    print "number\n";
    }
  if ($_ eq "frog")
    {
    print "animal\n";
    }
  }
