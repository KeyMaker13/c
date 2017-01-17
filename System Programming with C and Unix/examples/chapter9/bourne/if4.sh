#!/bin/sh
#
# Demonstrate condition tests using shell scripting (pg 313)
#
NAME="Fred"
GHOST=""
if [ "$NAME" != "Joe" ]; then
  echo Where\'s Joe?
fi
if [ -z "$GHOST" ]; then
  echo Boo!
fi
if [ -n "$GHOST" ]; then
  echo Boo too!
fi

