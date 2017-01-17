#!/usr/local/bin/perl
#
# demonstrate lists in perl
#
@gg=<*>;
@filenames=('hall','book','tree','frog');
@ff=qw(hall book frog turtle);
print "@ff\n";
print "@filenames\n";
print "@gg\n";
$count=@gg;
print "There are $count files\n";
