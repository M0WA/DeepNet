#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
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
	nohup ./WorkerBot --configfile ../../Scripts/conf/worker.se.conf&
	rm nohup.out
	ps aux | grep WorkerBot | grep -v grep
fi
cd $PWD

echo ""
echo "WorkerBot started"
