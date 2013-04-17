#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

if [ $# -ne 1 ]; then
  echo ""
  echo "usage: ./insert_page.sh <domain>";
  echo ""
  echo "please enter valid domain name:";
  echo "  i.e. ./insert_page.sh dummy.siridia.de";
  echo ""
  exit 1
fi

DOMAIN_NAME=$1

TMP=`pwd`
if [[ $* == *--debug* ]]
then
  cd ../DeepNetTool/Debug/
else
  cd ../DeepNetTool/Release/
fi

./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.conf --insertUrl ${DOMAIN_NAME}
cd ${TMP}
