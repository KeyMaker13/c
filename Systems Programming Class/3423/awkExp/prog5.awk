BEGIN{
inputT = 0
outputT = 0
}
/Acct-Input-Packets/{
inputT += $3
}
/Acct-Output-Packets/{
outputT += $3
}
END{
print "Total Input Bandwidth Usage  = " inputT " packets\nTotal Output Bandwidth Usage = " outputT " packets"
}
