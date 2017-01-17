#!/bin/sh
# renames all files using lower case letters
files=`ls`
for name in $files
do
  newname=`echo $name | tr "[:upper:]" "[:lower:]" `
  if [ "$newname" != "$name" ]; then
    mv "$name" "$newname"
  fi
done
