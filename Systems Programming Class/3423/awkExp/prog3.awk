BEGIN {time == 0}
/Acct-Session-Time/{time += $3}
END{print "Total User Session Time = "time}
