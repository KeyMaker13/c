BEGIN {

contime = 0;
bandwidth = 0;
storage = 0;

}

/^(maynard)/ {
	contime = ($3 - $2);
	bandwidth = ($4 + $5);
} 

/(\*storage\*)[ \t]*(maynard)/ {
	storage = $3;

} 


END {

print "maynard";
print "Connect Time = "contime;
print "\t Bandwitch = "bandwidth;
print "\t Storage   = "storage;
}
