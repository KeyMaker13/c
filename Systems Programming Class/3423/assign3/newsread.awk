BEGIN{
lnstrA = 0; lnstrG = 0; lnstrCs = 0; lnstrCsd = 0; lnstrT = 0.0;
rnrA = 0; rnrG = 0; rnrCs = 0; rnrCsd = 0; rnrT = 0.0;
rngrA = 0; rngrG = 0; rngrCs = 0; rngrCsd = 0; rngrT = 0.0;
rngsA = 0; rngsG = 0; rngsCs = 0; rngsCsd = 0; rngsT = 0.0;
}

#lonestar column

$6 == "lonestar.jpl.utsa.edu" && $7 == "exit"{
lnstrA = lnstrA + $9;
lnstrG = lnstrG + $11;
}

$6 == "lonestar.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413"{
lnstrCs = lnstrCs + $9;
}

$6 == "lonestar.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413.d"{
lnstrCsd = lnstrCsd + $9;
}

$6 == "lonestar.jpl.utsa.edu" && $7 == "times"{
lnstrT = lnstrT + $13;
}

#runner column

$6 == "runner.jpl.utsa.edu" && $7 == "exit"{
rnrA = rnrA + $9;
rnrG = rnrG + $11;
}

$6 == "runner.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413"{
rnrCs = rnrCs + $9;
}

$6 == "runner.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413.d"{
rnrCsd = rnrCsd + $9;
}

$6 == "runner.jpl.utsa.edu" && $7 == "times"{
rnrT = rnrT + $13;
}

#ringer column


$6 == "ringer.cs.utsa.edu" && $7 == "exit"{
rngrA = rngrA + $9;
rngrG = rngrG + $11;
}

$6 == "ringer.cs.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413"{
rngrCs = rngrCs + $9;
}

$6 == "ringer.cs.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413.d"{
rngrCsd = rngrCsd + $9;
}

$6 == "ringer.cs.utsa.edu" && $7 == "times"{
rngrT = rngrT + $13;
}

#rings column

$6 ~/ring[0-9][0-9].cs.utsa.edu/{
	if($7=="exit" && $8=="articles"){
		rngsA = rngsA + $9
		rngsG = rngsG + $11
	}
}i

$6 ~/ring[0-9][0-9].cs.utsa.edu/ {
	if($7 =="group" && $8 == "utsa.cs.2413")
		rngsCs = rngsCs + $9
}


$6 ~/ring[0-9][0-9].cs.utsa.edu/{
	if($7=="group" && $8 == "utsa.cs.2413.d")
 		rngsCsd= rngsCsd + $9
}

$6 ~/ring[0-9][0-9].cs.utsa.edu/{
	if($7 =="times"&& $8 =="user")
		rngsT = rngsT + $13
}

#Start Time and Stop Time

NR ==1 {startT= $1" "$2" "$3}

NR == NR{stopT = $1" "$2" "$3}

END{
print "\t\t\tNews Reader Summary\n\n"
print "\t\tlonestar\trunner\t\tringer\t\trings"
print "\nArticles:\t"lnstrA"\t\t"rnrA"\t\t"rngrA"\t\t"rngsA
print "Groups:\t\t"lnstrG"\t\t"rnrG"\t\t"rngrG"\t\t"rngsG
print "Cs2413:\t\t"lnstrCs"\t\t"rnrCs"\t\t"rngrCs"\t\t"rngsCs
print "Cs2413.d:\t"lnstrCsd"\t\t"rnrCsd"\t\t"rngrCsd"\t\t"rngsCsd
print "User Time:\t"lnstrT"\t\t"rnrT"\t\t"rngrT"\t\t"rngsT
print "\nStart Time = " startT "\t\t" "End Time = "  stopT "\n"
}
