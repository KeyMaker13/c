#!/usr/local/bin/perl
#
# demonstrate for and while loops in perl (pg 326)
#
for ($i=0; $i<5; $i++)
  {
  $t=$t+$i;
  }
print "$t\n";
$j=0;
while ($j < 5)
  {
  $t=$t+$j;
  $j++;
  }
print "$t\n";
