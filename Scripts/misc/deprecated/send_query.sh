#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

echo "==> DEPRECATED, USE WEBINTERFACE TO SEND QUERIES <=="
exit 0

#if [ $# -ne 1 ]; then
#  echo "please enter request xml file";
#  echo "usage: ./send_query.sh <xmlfile>";
#  echo "  i.e. ./send_query.sh doc/webif/query_request.xml 20";
#  exit
#fi

if [[ $* == *--debug* ]]
then
	wget --post-file=doc/webif/query_request.xml debug.query/queryserver
else
	wget --post-file=doc/webif/query_request.xml http://query.mo-sys.de/queryserver
fi
