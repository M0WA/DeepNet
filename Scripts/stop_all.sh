#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
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
