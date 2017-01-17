#!/bin/sh
#
# Quotes can be used to work with strings containing spaces (pg 307)
#
echo Name a fruit?
read FRUIT
echo Vegetable?
read VEGGIE
echo "$FRUIT and $VEGGIE are healthy foods"
