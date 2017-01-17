#!/usr/local/bin/perl
#
# A perl program that stripts HTML metatags (pg 332)
#
while (<STDIN>)
  {
  s/<.*>//;
  print;
  }
