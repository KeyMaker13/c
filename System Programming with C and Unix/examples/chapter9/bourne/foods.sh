#!/bin/sh
#
# Demonstrate basic I/O in shell scripting (pg 306)
#
echo Name a fruit?
read FRUIT
echo Vegetable?
read VEGGIE
echo $FRUIT and $VEGGIE are healthy foods
