BEGIN{
cntr1 = 0
cntr2 = 0
cntr3 = 0
cntr4 = 0
cntr5 = 0
}

/Ascend-Data-Rate/{
if ($3>=0 && $3<=14400)
	cntr1 ++;
else if ($3>=14400 && $3<=19200)
        cntr2 ++;
else if ($3>=19201 && $3<=28800)
        cntr3 ++;
else if ($3>=28801 && $3<=33600)
        cntr4 ++;
else if ($3>33600)
        cntr5 ++;
}
END{print "0-14400\t\t"cntr1"\n14401-19200\t"cntr2"\n19201-28800\t"cntr3"\n28801-33600\t"cntr4"\nabove 33600\t"cntr5}
