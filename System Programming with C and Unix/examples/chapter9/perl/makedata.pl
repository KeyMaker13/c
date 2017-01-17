#!/usr/local/bin/perl
#
# demonstrate open and close in perl (pg 322-323)
# running this creates a file named data.txt
#
$n=42;
open DATA, ">data1.txt";
print DATA "History of the world\n";
printf DATA "Answer: %d\n",$n;
close DATA;
