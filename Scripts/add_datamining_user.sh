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
  echo "usage: ./add_datamining_user.sh <username> <password>"
  echo ""
  echo "please enter valid username and password:"
  echo "  i.e. ./add_datamining_user.sh \"dummy_customer@siridia.de\" \"areallyreallysecurepassword\""
  echo ""
fi

USERNAME=$1
PASSWORD=$2

TMP=`pwd`
if [[ $* == *--debug* ]]
then
  cd ../DeepNetTool/Debug/
else
  cd ../DeepNetTool/Release/
fi

./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.conf --dmAddDataminingUser 1 --dmDataminingUsername ${USERNAME} --dmDataminingPassword ${PASSWORD}
cd ${TMP}
