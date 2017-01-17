#!/bin/sh
NAME=Unknown
while test $NAME != "Fred"
do
  echo Who are you?
  read NAME
  echo Let me see ...
done
echo Found you!
