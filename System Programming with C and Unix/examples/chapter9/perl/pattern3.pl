#!/usr/local/bin/perl
#
# Another example of search and replace in perl (pgs 330-331)
#
while (<STDIN>)
  {
  s/ (F|f)rog/ Turtle/;
  print;
  }
