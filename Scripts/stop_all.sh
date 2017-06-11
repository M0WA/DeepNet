#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

echo "Killing WorkerBot first, this may last some time..."
killall WorkerBot
echo "Please recheck ps to see if WorkerBot is still shutting down"
echo "Shutting down webservices"
killall -09 QueryServer
killall -09 InspectorServer
killall -09 SuggestServer
echo "Webservices shutdown completely"
