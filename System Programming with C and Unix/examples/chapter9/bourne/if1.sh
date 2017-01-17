#!/bin/sh
#
# Demonstrate if statement in shell scripting (pg 311)
#
NAME="Fred"
i=7
j=9
if [ $NAME = "Fred" ]; then
  echo Matches
fi
if [ $i -ge $j ]; then
  echo Lesser
fi
