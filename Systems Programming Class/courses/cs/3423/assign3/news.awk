#this is for adding addgroup to the start of the line
BEGIN { addgroup = "addgroup"; space = " "; }


#so i am going to use this one
{print addgroup, $1 , $4; }


#not going to use this one at all then
#{sub(/ [0-9]* [0-9]*)/," ");   print "addgroup", $0; } 

#second atempt for changing getting rid of long numbers
#this one works but will duplicate the line below will be plugging it in into the top block statement of code { code in this block  }
#{sub(/ [0-9]* [0-9]*/," ");}1

# first atempt for trying to get rid of long numbers
#have the regular expression below to match the string
#{/ [0-9]* [0-9]*/ { NR  = "testing";   }



#naw these don't work learning awk 
#$1 =  addgroup, "test ";
#$1 = $addgroup + $1 
