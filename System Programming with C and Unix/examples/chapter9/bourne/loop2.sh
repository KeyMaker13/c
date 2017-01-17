#!/bin/sh
#
# Demonstrate while loop in shell scripting (pg 311)
#
NAME=Unknown
while [ "$NAME" != "Fred" ]
do
  echo Who are you?
  read NAME
  echo Let me see ...
done
echo Found you!
