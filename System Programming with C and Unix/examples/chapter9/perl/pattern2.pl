#!/usr/local/bin/perl
#
# demonstrate shorthand notation for search and replace in perl (pg 330)
#
while (<STDIN>)
  {
  s/Frog/Turtle/;
  print;
  }
