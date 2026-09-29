#!/bin/sh
# Title: writer.sh
# Author: justinp

if [ $# != 2 ]
then
    echo "Invalid number of arguments!"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "${writefile}")" && echo "${writestr}" > "${writefile}"

