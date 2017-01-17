#!/bin/sh
#
# Another example demonstrating I/O and expr
#
echo "Enter a number: "
read X
echo "Second number? "
read Y
Z=`expr $X + $Y`
echo "$X + $Y = $Z"
