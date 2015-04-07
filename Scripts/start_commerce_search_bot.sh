#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

echo "Starting WorkerBot for CommerceSearch"

PWD=`pwd`
if [[ $* == *--debug* ]]
then
	echo "==> DEBUG MODE IS NOT IMPLEMENTED <=="
	echo "exiting"
else
	cd ../WorkerBot/Release/
	nohup ./WorkerBot --configfile ../../Scripts/conf/worker.cs.conf&
	rm nohup.out
	ps aux | grep WorkerBot | grep -v grep
fi
cd $PWD

echo ""
echo "WorkerBot for CommerceSearch started"
