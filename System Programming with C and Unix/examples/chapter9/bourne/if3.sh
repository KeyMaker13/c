#!/bin/sh
#
# Demonstrate that test and [ are same program (aliases) (pg 312)
#
NAME="Joe"
if test $NAME = "Fred" ; then
  echo Hello Fred
fi
if [ $NAME = "Joe" ]; then
  echo Hello Joe
fi
