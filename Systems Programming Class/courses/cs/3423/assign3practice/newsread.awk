#newsread.awk

BEGIN {
startday;
lonestar_a = 0;
lonestar_g = 0;
lonestar_cs2413 = 0;
lonestar_cs2413_d = 0;
lonestar_usertime = 0;
ringer_a = 0;
ringer_g = 0;
ringer_cs2413 = 0;
ringer_cs2413_d = 0;
ringer_usertime = 0;
runner_a = 0;
runner_g = 0;
runner_cs2413 = 0;
runner_cs2413_d = 0;
runner_usertime = 0;
rings_a = 0;
rings_g = 0;
rings_cs2413 = 0;
rings_cs2413_d = 0;
rings_usertime = 0;



print "\t\t\tNews Reader Summary";
print "\t\t lonestar \trunner \tringer \trings";
}

{ if (NR == 1) {startday = $1" "$2" "$3; } }
# CRAAAAPPPPPP
#But I wanna be fancy and use a nice little function to return me all the stuff
#function runar (token7,token8,token9,token10,token11){	
#	if (token7 == "group")
#	{
#		if (token8 != ""){  return token9;  }else {return 13;  }
#	
#	}			
#
#	return 0;
#
#}
   
 


#checks for articles read 
#ring[0-9][0-9].cs.utsa.edu/&&(($7=="group") || ($7 == "exit"))&&($9 > 0) { 
/ring[0-9][0-9].cs.utsa.edu/{
        if ( ($7 == "group")  && ($9)) {   rings_a += $9; }
	else if ($7 == "exit" ) { rings_g += $11;  }
	
	if ($8 == "utsa.cs.2413") { rings_cs2413 += $9;  }
	if ($8 == "utsa.cs.2413.d") { rings_cs2413_d += $9; }
}

($6 == "lonestar.jpl.utsa.edu") {
	

	if (($7 == "group" ) )   { lonestar_a += $9;   }
	else if ( ($7 == "exit")){ lonestar_g += $11;    } 


	if ($8 == "utsa.cs.2413") { lonestar_cs2413 += $9;   }
	if ($8 == "utsa.cs.2413.d") { lonestar_cs2413_d += $9;    }	
}

($6 == "runner.jpl.utsa.edu"){
	
	if ($7 == "group" ) { runner_a += $9; }
	else if ($7 == "exit") { runner_g += $11;  }
	if ($8 == "utsa.cs.2413") { runner_cs2413 += $9; }
	if ($8 == "utsa.cs.2413.d") { runner_cs2413_d += $9;  }
}

($6 == "ringer.cs.utsa.edu") { 
	if ($7 == "group" ) {ringer_a += $9;}
	else if (($7 == "exit")  ){ringer_g += $11;}

	if ($8 == "utsa.cs.2413") { ringer_cs2413 += $9; }
	if ($8 == "utsa.cs.2413.d") { ringer_cs2413_d += $9;  }
}	

#checks for exit but counts articles read
#/ring[0-9][0-9].cs.utsa.edu/&&($7=="exit")&&($9) {
#	rings_a += $9;
#	if ($11) {
#	rings_g += $11;
#	}	
#}




#USER TIMES
#checks for usertime for rings
#seems to work so far so will be 
/ring[0-9][0-9].cs.utsa.edu/&&($7=="times")&&($13){
	rings_usertime += $13;
}

#checks for usertime for ringer
($6 == "ringer.cs.utsa.edu")&&($7 == "times")&&($13){
	ringer_usertime += $13;
}

#checks for usertime for runner
($6 == "runner.jpl.utsa.edu")&&($7 == "times")&&($13){
	 runner_usertime += $13;
}	

#checks for usertime for lonestar
($6 == "lonestar.jpl.utsa.edu")&&($7 == "times")&&($13){
	lonestar_usertime += $13;
}

#





END {
print "Articles:  \t",lonestar_a,        " \t",runner_a,        " \t",ringer_a,        " \t", rings_a;
print "Groups:	  \t",lonestar_g,        " \t",runner_g,        " \t",ringer_g,        " \t",rings_g;
print "Cs2413:    \t",lonestar_cs2413,   " \t",runner_cs2413,   " \t",ringer_cs2413,   " \t",rings_cs2413;
print "Cs2413.d:  \t",lonestar_cs2413_d, " \t",runner_cs2413_d, " \t",ringer_cs2413,   " \t", rings_cs2413_d;
print "User Time: \t",lonestar_usertime, " \t",runner_usertime, " \t",ringer_usertime, " \t",rings_usertime;
print "\n";
print "Start Time = ", startday," \t""End Time = "$1" "$2" "$3;
}
