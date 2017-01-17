#!/bin/sh
#
# Another example of shell scripting using expr (pg 316)
#
files=`ls`
i=1
for name in $files
do
  echo "File $i is $name"
  i=`expr $i + 1`
done
