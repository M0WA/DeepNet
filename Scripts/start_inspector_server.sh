#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

echo "Starting InspectorServer"

TMP_PWD=`pwd`
killall -09 InspectorServer
if [[ $* == *--debug* ]]
then
  cd ../InspectorServer/Debug/
	gdb --args "InspectorServer" --configfile ../../Scripts/conf/inspectorserver.de.conf
else
  cd ../InspectorServer/Release/
#	nohup ./InspectorServer --configfile ../../Scripts/conf/inspectorserver.de.conf&
#	nohup ./InspectorServer --configfile ../../Scripts/conf/inspectorserver.com.conf&
	nohup ./InspectorServer --configfile ../../Scripts/conf/inspectorserver.staging.se.conf&
	rm nohup.out
	ps aux | grep InspectorServer | grep -v grep
fi
cd ${TMP_PWD}

echo ""
echo "InspectorServer started"
