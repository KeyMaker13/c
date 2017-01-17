#!/bin/sh
#
# Demonstrate variables in shell scripting (pg 308)
#
ROCKS=4
echo Price?
read PRICE
echo $ROCKS rocks for sale, $PRICE each
