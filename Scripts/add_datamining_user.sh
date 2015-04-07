#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

if [ $# -ne 2 ]; then
  echo ""
  echo "usage: ./add_datamining_user.sh <username> <password> [--debug]"
  echo ""
  echo "please enter valid username and password:"
  echo "  i.e. ./add_datamining_user.sh \"dummy_customer@mo-sys.de\" \"areallyreallysecurepassword\""
  echo ""
  exit 1
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
