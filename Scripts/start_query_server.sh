#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

echo "Starting QueryServer"

TMP_PWD=`pwd`
killall -09 QueryServer
if [[ $* == *--debug* ]]
then
  cd ../QueryServer/Debug/
	gdb --args "QueryServer" --configfile ../../Scripts/conf/queryserver.de.conf
else
  cd ../QueryServer/Release/
#	nohup ./QueryServer --configfile ../../Scripts/conf/queryserver.de.conf&
#	nohup ./QueryServer --configfile ../../Scripts/conf/queryserver.com.conf&
	nohup ./QueryServer --configfile ../../Scripts/conf/queryserver.conf&
#	nohup ./QueryServer --configfile ../../Scripts/conf/queryserver.staging.cs.conf&
	rm nohup.out
	ps aux | grep QueryServer | grep -v grep
fi
cd ${TMP_PWD}

echo ""
echo "QueryServer started"
