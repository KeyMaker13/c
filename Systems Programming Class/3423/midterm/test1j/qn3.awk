#/^maynard[ 	]/{
($1 == "maynard"){
	StpTime += $3
	StrtTime += $2
	Bin += $4
	Bout += $5
}

#/^\*storage\*\tmaynard[ 	]/{
($1 == "*storage*" && $2 == "maynard"){
	strg += $3
}

END{

cnnTime = StpTime-StrtTime

if (cnnTime > 10000 || Bout > 10000000000 || strg > 10000000){
	print "maynard"
	print "\tConnect Time\t=", cnnTime
	print "\tBandwidth In\t=", Bin
	print "\tBandwidth Out\t=", Bout
	print "\tStorage\t\t=", strg "\n"
}
}
