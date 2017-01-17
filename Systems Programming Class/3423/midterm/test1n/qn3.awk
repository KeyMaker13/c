BEGIN {
	nTimesM = 0
}

#/^maynard[ 	]/{
($1 == "maynard"){
	if ($3 == "129.115.203.145" && $2 == "ftp" && $5 == "Oct" && $6 == "15"){
		nTimesM ++;
		TtimeM += $10
	}
}

($3 == "129.115.203.145" && $2 == "ftp" && $5 == "Oct" && $6 == "15"){
	nTimes ++;
        Ttime += $10
}

($2 == "ftp" && $5 == "Oct" && $6 == "15"){
        nTimesA ++;
        TtimeA += $10
}

END{
	print "maynard\t129.115.203.145\t" nTimesM, "connections\t" TtimeM, "minutes"
        print "all users\t129.115.203.145\t" nTimes, "connections\t" Ttime, "minutes"
        print "all users\tall sites\t" nTimesA, "connections\t" TtimeA, "minutes"
}
