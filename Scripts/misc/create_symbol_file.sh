#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo Usage: stripfile symbolfile
    exit
fi

stripfile=$1
symbolfile=$2

objcopy --only-keep-debug $stripfile $symbolfile
strip --strip-debug --strip-unneeded $stripfile
objcopy --add-gnu-debuglink=$symbolfile $stripfile
