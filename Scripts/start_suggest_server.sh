#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

echo "Starting SuggestServer"

TMP_PWD=`pwd`
killall -09 SuggestServer
if [[ $* == *--debug* ]]
then
  cd ../SuggestServer/Debug/
	gdb --args "SuggestServer" --configfile ../../Scripts/conf/suggestserver.de.conf
else
  cd ../SuggestServer/Release/
#	nohup ./SuggestServer --configfile ../../Scripts/conf/suggestserver.de.conf&
#	nohup ./SuggestServer --configfile ../../Scripts/conf/suggestserver.com.conf&
#	nohup ./SuggestServer --configfile ../../Scripts/conf/suggestserver.staging.se.conf&
	nohup ./SuggestServer --configfile ../../Scripts/conf/suggestserver.conf&
	rm nohup.out
	ps aux | grep SuggestServer | grep -v grep
fi
cd ${TMP_PWD}

echo ""
echo "SuggestServer started"
