#!/bin/sh
#
# adds up the size of all files (pg 318)
#
sizes=`ls -l | cut -b 30-32`   # adjust the cut columns as necessary
total=0
for i in $sizes
do
  total=`expr "$total" + "$i"`
  echo $i
done
echo $total
