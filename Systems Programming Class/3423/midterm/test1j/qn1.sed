/^#/!d
/^#[ 	]*$/d

#Exam Solution (can not use '!d')
#sed -e '/^[^#]/ d' -e '/^#[ \t]*$/d' test1.txt > test1.out
