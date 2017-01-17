s/[ 	]*//g
s/^\([0-9]\).*$/\1/
/^$/d


#Exam Ans
#sed -e 's/[ \t]*//g' -e 's/^\([0-9]\).*$/\1/' -e '/^$/d' test1.txt > test1.out
#sed -e 's/[ \t]*\([0-9]\).*$/\1/' test1.txt > test1.out
#sed -e 's/[ \t]*\([0-9][0-9]*\)[ \t]*.*$/\1/' test1.txt
