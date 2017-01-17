#!/usr/bin/perl -w
open(FILE,"$ARGV[0]") or die "Error in opening file\n";

while (<FILE>){
	chop($_);
	#print `find "$_"`;
	print `find "$_" -printf "%h\n"`;	
}


close(FILE);


