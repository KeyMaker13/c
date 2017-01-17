#!/usr/bin/perl -w
open(INFILE,"file.txt");
open(OUTFILE,"file2.txt");
while ( <INFILE> ){
	print OUTFILE $_, "\n";
}
