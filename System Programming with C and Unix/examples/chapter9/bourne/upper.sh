#!/bin/sh
#
# renames all files using upper-case letters (pg 317)
#
files=`ls`
for name in $files
do
  newname=`echo $name | tr "[:lower:]" "[:upper:]" `
  if [ "$newname" != "$name" ]; then
    mv "$name" "$newname"
  fi
done
