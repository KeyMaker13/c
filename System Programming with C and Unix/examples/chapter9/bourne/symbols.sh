#!/bin/sh
#
# Special symbols in shell scripting (pg 308)
#
# This is a comment
# Special symbols include # $ \ ' {}
HI=Hello
echo HI        # displays HI
echo $HI       # displays Hello
echo \$HI      # displays $HI
echo '\$HI'    # displays \$HI
echo "$HIJ"    # displays nothing?
echo "${HI}J"  # displays HelloJ
