BEGIN {lone["cs.d"]=0;lone["cs"]=0;lone["ar"];lone["gr"]=0 ; one =0.0
run["cs.d"]=0;run["cs"]=0;run["ar"];run["gr"]=0 ; two =0.0
rin["cs.d"]=0;rin["cs"]=0;rin["ar"];rin["gr"]=0 ; three =0.0
rins["cs.d"]=0;rins["cs"]=0;rins["ar"];rins["gr"]=0 ; four =0.0
sta="";sto=""
}
$6 == "lonestar.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413.d" {
lone["cs.d"]=+$9
}

$6 == "lonestar.jpl.utsa.edu" && $7 == "group" && $8 == "utsa.cs.2413" {
lone["cs"]=+ $9
}
$6 == "lonestar.jpl.utsa.edu" && $7 == "exit" && $8=="articles" {
lone["ar"]=lone["ar"] + $9
lone["gr"]=lone["gr"] +  $11

}

$6 == "lonestar.jpl.utsa.edu" && $7 == "times" && $8=="user"{
one = one  + $13

}
####################
$6 == "runner.jpl.utsa.edu" && $7 =="group" && $8 == "utsa.cs.2413.d"{
 run["cs.d"]= run["cs.d"]+$9
}
$6 == "runner.jpl.utsa.edu" && $7 =="group" && $8 == "utsa.cs.2413" {
run["cs"] = run["cs"] + $9
} 
$6 == "runner.jpl.utsa.edu" && $7 =="exit" && $8 =="articles"{
run["ar"]= run["ar"]+$9
run["gr"]= run["gr"]+$11
}
$6 == "runner.jpl.utsa.edu" && $7 =="times" && $8=="user"{
two=two + $13
}

############################

$6 == "ringer.cs.utsa.edu" && $7 =="group" && $8 == "utsa.cs.2413.d"{
 rin["cs.d"]= rin["cs.d"]+$9
}
$6 == "ringer.cs.utsa.edu" && $7 =="group" && $8 == "utsa.cs.2413" {
rin["cs"] = rin["cs"] + $9
} 
$6 == "ringer.cs.utsa.edu" && $7 =="exit" && $8 =="articles"{
rin["ar"]= rin["ar"]+$9
rin["gr"]= rin["gr"]+$11
}
$6 == "ringer.cs.utsa.edu" && $7 =="times" && $8=="user"{
three=three + $13
}


###########

$6 ~/ring[0-9][0-9].cs.utsa.edu/{
 if($7=="group" && $8 == "utsa.cs.2413.d")
 rins["cs.d"]= rins["cs.d"]+$9
}
$6 ~/ring[0-9][0-9].cs.utsa.edu/ {
if($7 =="group" && $8 == "utsa.cs.2413")
rins["cs"] = rins["cs"] + $9
} 
$6 ~/ring[0-9][0-9].cs.utsa.edu/{
if($7=="exit" && $8=="articles"){
rins["ar"]= rins["ar"]+$9
rins["gr"]= rins["gr"]+$11
}
}i
$6 ~/ring[0-9][0-9].cs.utsa.edu/{
if($7 =="times"&& $8 =="user")
four=four + $13
}

NR == 1 {
sta = $1 " " $2 " "$3
}

NR == NR {
sto = $1 " "$2 " "$3
}

END{
print "\t\t lonestar \t runner \t ringer \t rings"
print ""  
print"Articles:" "\t " lone["ar"] "\t\t"  run["ar"] "\t\t"  rin["ar"] "\t\t"  rins["ar"]
print"Groups:" "\t\t " lone["gr"] "\t\t"  run["gr"] "\t\t"  rin["gr"] "\t\t"  rins["gr"]
print"Cs2413:" "\t\t " lone["cs"] "\t\t"  run["cs"] "\t\t"  rin["cs"] "\t\t"  rins["cs"]
print"Cs2412.d: " "\t " lone["cs.d"] "\t\t" run["cs.d"] "\t\t" rin["cs.d"] "\t\t" rins["cs.d"]
print"User Time: " "\t " one "\t\t" two "\t\t" three "\t\t" four
print ""
print "Start Time = " sta "\t\t" "End Time = "  sto
}

 


