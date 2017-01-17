#!/bin/sh
#
# Demonstrate if-else in shell scripting (pg 312)
#
NAME="Joe"
if [ $NAME = "Fred" ]; then
  echo Matches
else
  echo No match
fi
