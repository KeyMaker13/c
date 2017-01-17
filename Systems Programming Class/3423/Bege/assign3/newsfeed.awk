BEGIN {sacc = 0 ;srec = 0 ;scan = 0; nacc =0;nrec=0;ncan=0; acc=0 ; rec=0 ; can=0}
NR ==1 {

sta= $1 " " $2 " " $3
}
NR == NR{
sto = $1 " " $2 " " $3
} 

$5 == "swrinde"  && $4 =="+"  {
  
sacc++;
}

$5 == "swrinde" && $4 =="-"{
srec ++;
}

$5 == "swrinde" && $4 == "c" {
scan++;
sacc++;
}

$5 == "swrinde" && $4 == "j"{
sacc++;
} 
##############################

$5 == "news.cais.net" && $4 == "+"{
nacc++;
}

$5 == "news.cais.net"  && $4 == "-"{
nrec++;
}

$5 == "news.cais.net" && $4 == "c"{
ncan++;
nacc++;
}
$5 == "news.cais.net" && $4== "j"{
nacc++;
}

$5 == "?" && $4== "+"{
acc++;
}

$5 == "?" && $4 =="-"{
rec++;
}
$5 == "?" && $4== "c"{
can++;
acc++;
}
$5 == "?" && $4 == "j"{
acc++;
}






END {
print "\t\taccepted\trejected\tcanceled"
print "swrinde: \t"  sacc,"\t\t" srec ,"\t\t", scan
print "news.cais.net: \t" nacc,"\t\t" nrec ,"\t\t", ncan
print"?:\t        " acc,"\t\t" rec ,"\t\t", can
print ""
print"Start Time = "  sta "\t End Time = " sto
}
