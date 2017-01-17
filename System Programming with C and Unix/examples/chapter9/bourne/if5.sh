#!/bin/sh
#
# Demonstrate numeric tests using shell scripting (pg 313-314)
#
i=7
j=9
if [ "$i" -lt "$j" ]; then
  echo Lesser
fi
if [ "$i" -gt "$j" ]; then
  echo Greater
fi

