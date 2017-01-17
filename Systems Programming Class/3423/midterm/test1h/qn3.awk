#/^maynard[ 	]/{
($1 == "maynard"){
	StpTime += $3
	StrtTime += $2
	Bin += $4
	Bout += $5
}

/^\*storage\*\tmaynard/{
	strg += $3
}

END{
	print "maynard"
	print "Connect Time =", StpTime-StrtTime
	print "\tBandwidth\t=", Bin + Bout
	print "\tStorage =", strg "\n"
}
