#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

TMP=`pwd`
if [[ $* == *--debug* ]]
then
  cd ../DeepNetTool/Debug/
else
  cd ../DeepNetTool/Release/
fi
# ./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.postgre.conf --urlFile ../../Scripts/conf/common.pages.conf
# ./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.mysql.conf --urlFile ../../Scripts/conf/common.pages.conf
./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.conf --urlFile ../../Scripts/conf/common.pages.conf
cd ${TMP}
