#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

echo "Starting WorkerBot"

PWD=`pwd`
if [[ $* == *--debug* ]]
then
	echo "==> DEBUG MODE IS NOT IMPLEMENTED <=="
	echo "exiting"
else
	cd ../WorkerBot/Release/
	nohup ./WorkerBot --configfile ../../Scripts/conf/worker.conf&
	rm nohup.out
	ps aux | grep WorkerBot | grep -v grep
fi
cd $PWD

echo ""
echo "WorkerBot started"
