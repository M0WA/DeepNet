#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
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
	nohup ./SuggestServer --configfile ../../Scripts/conf/suggestserver.staging.se.conf&
	rm nohup.out
	ps aux | grep SuggestServer | grep -v grep
fi
cd ${TMP_PWD}

echo ""
echo "SuggestServer started"
