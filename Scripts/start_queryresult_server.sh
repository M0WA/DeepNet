#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

echo "Starting QueryResultServer"

TMP_PWD=`pwd`
killall -09 QueryResultServer
if [[ $* == *--debug* ]]
then
  cd ../QueryResultServer/Debug/
	gdb --args "QueryResultServer" --configfile ../../Scripts/conf/queryresultserver.de.conf
else
  cd ../QueryResultServer/Release/
	nohup ./QueryResultServer --configfile ../../Scripts/conf/queryresultserver.conf&
	rm nohup.out
	ps aux | grep QueryResultServer | grep -v grep
fi
cd ${TMP_PWD}

echo ""
echo "QueryResultServer started"
