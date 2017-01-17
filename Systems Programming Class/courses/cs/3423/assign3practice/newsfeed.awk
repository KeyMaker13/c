#newsfeed.awk

#Ivan Capistran

#needs to output the following 

			  #Incoming News Feed Summary
		#accepted	rejected	cancled
#swrindle:	9123321 	1233212 	0
#news.cais.net:	13313		240 		3
#?: 		3		0		3

#Start Time = Feb 13 21:23:23.497	End Time = Feb 14 20:45:32:421

BEGIN{
swrindeaa = 0;	
swrindear = 0;	
swrindeac = 0; 
newscalaa = 0; 	
newscalar = 0; 	
newscalac = 0; 	
qmarkaa = 0; 	
qmarkar = 0; 	
qmarkac = 0;
firstentry;
print "\t\t\tIncoming News Feed Summary ";
print "\t\taccepted	rejected	canceled "; 
}

#tried using functions the functions work

#but seems like the right answer is produced when AND operator is used in the if statement
function articlesaccepted(token)
{
	if (token == "+"  || token = "j" || token == "c" )
	{
		
		return 1;
	}
	else 
	{
		return 0;
	}	

}

function articlesrejected(token)
{
	if (token == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

function articlescanceled(token)
{
	if (token == "c")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

{ 

	if (NR == 1)
	{
		firstentry = $1" "$2" "$3;
	}


}


{ 
if ( ($5 == "swrinde" && ($4 == "+")) ){
	swrindeaa++;	
}
if ( ($5 == "swrinde" && ($4 == "j")) ){
	swrindeaa++;
}

if ( ($5 == "swrinde" && ($4 == "c")) ){
	swrindeac++;
	swrindeaa++; 
}

if ( ($5 == "swrinde" && ($4 == "-")) ){
 	swrindear++;
}


if ( ($5 == "news.cais.net" && ($4 == "+")) ){
	newscalaa++;	
}
if ( ($5 == "news.cais.net" && ($4 == "j")) ){
	newscalaa++;
}

if ( ($5 == "news.cais.net" && ($4 == "c")) ){
	newscalac++;
	newscalaa++; 
}

if ( ($5 == "news.cais.net" && ($4 == "-")) ){
 	newscalar++;
}

if ( ($5 == "?" && ($4 == "+")) ){
	qmarkaa++;	
}
if ( ($5 == "?" && ($4 == "j")) ){
	qmarkaa++;
}

if ( ($5 == "?" && ($4 == "c")) ){
	qmarkac++;
	qmarkaa++; 
}

if ( ($5 == "?" && ($4 == "-")) ){
 	qmarkar++;
}

}



END { 
 
	
	print "swrinde: 	",swrindeaa, "		",swrindear, "		",swrindeac;
	print "news.cais.net: 	",newscalaa, "		",newscalar, "		",newscalac;
	print "?: 		",qmarkaa, "		",qmarkar, "		",qmarkac;   
	print "\n";
	print "Start Time = ",firstentry, "	","End Time = ",$1, $2, $3;
 }
