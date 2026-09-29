#!/bin/sh
# Title: finder.sh
# Author: justinp

if [ $# != 2 ]
then
    echo "Invalid number of arguments!"
    exit 1
fi

if [ -d $1 ]
then
   filesdir=$1
   searchstr=$2
   file_count=$(find -L $1 -type f | wc -l)
   line_count=$(grep -r $2 $1 | wc -l)
   echo "The number of files are ${file_count} and the number of matching lines are ${line_count}"
else
   echo "Invalid directory!"
   exit 1
fi


