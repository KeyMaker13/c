#!/bin/sh
#
# Demonstrate use of expr program to evaluate expressions (pg 315)
#
i=3
j=7
a=`expr $i + $j`
b=`expr $j / $i`
echo "$a $b"
