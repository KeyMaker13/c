BEGIN {swaccpt = 0 ;swrjct = 0 ;swcncl = 0; nwaccpt =0; nwrjct=0; nwcncl=0; accpt=0 ; rjct=0 ; cncl=0}

NR ==1 {startT= $1" "$2" "$3}

NR == NR{stopT = $1" "$2" "$3}

$5 == "swrinde"  && $4 =="+"{swaccpt++}

$5 == "swrinde" && $4 =="-"{swrjct ++}

$5 == "swrinde" && $4 == "c"{swcncl++; swaccpt++}

$5 == "swrinde" && $4 == "j"{swaccpt++}

$5 == "news.cais.net" && $4 == "+"{nwaccpt++}

$5 == "news.cais.net"  && $4 == "-"{nwrjct++}

$5 == "news.cais.net" && $4 == "c"{nwcncl++; nwaccpt++}

$5 == "news.cais.net" && $4== "j"{nwaccpt++}

$5 == "?" && $4== "+"{accpt++}

$5 == "?" && $4 =="-"{rjct++}

$5 == "?" && $4== "c"{cncl++; accpt++}

$5 == "?" && $4 == "j"{accpt++}


END {
print "\t\t\tIncoming News Feed Summary\n\n"
print "\t\taccepted\trejected\tcanceled"
print "swrinde:\t"  swaccpt,"\t\t" swrjct ,"\t\t", swcncl
print "news.cais.net:\t" nwaccpt,"\t\t" nwrjct ,"\t\t", nwcncl
print"?:\t        " accpt,"\t\t" rjct ,"\t\t", cncl "\n"
print"Start Time = "  startT "\tEnd Time = " stopT "\n"
}
