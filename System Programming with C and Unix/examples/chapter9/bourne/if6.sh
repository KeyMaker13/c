#!/bin/sh
#
# Demonstrate file tests in shell scripting (pg 314)
#
FILE=if6.sh
if [ -f "$FILE" ]; then
  echo FILE exists
fi
if [ -x "$FILE" ]; then
  echo FILE is executable
fi
