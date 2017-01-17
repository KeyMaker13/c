#!/usr/bin/perl -w
open(INFILE,"file.txt");
open(OUTFILE,"> file2.txt");
while ($line = <INFILE>){
	print OUTFILE $line, "\n";
}
