BEGIN {
	Tincome = 0
	
}
/^Income/{Tincome += $3}
/^Interest/{Tinterest += ($2 + $4)}
/Expense$/{Texp += $3}

END{
	print "Income: $" Tincome, "Interest: $" Tinterest, "Expenses: $" Texp
	print "Total = $" Tincome + Tinterest - Texp
}
