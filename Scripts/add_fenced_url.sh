#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################
if [ $# -ne 2 ]; then
  echo ""
  echo "usage: ./$0 <username> <url> [--debug]"
  echo ""
  echo "please enter valid username and password:"
  echo "  i.e. ./$0 \"dummy_customer@siridia.de\" \"google.de\""
  echo ""
  exit 1
fi

USERNAME=$1
URL=$2

TMP=`pwd`
if [[ $* == *--debug* ]]
then
  cd ../DeepNetTool/Debug/
else
  cd ../DeepNetTool/Release/
fi

./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.conf --dmAddFencedUrl $URL --dmFencedDataminingUsername ${USERNAME}
cd ${TMP}
