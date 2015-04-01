#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

TMP=`pwd`
cd ../DeepNetTool/Debug
#  --track-origins=yes
nohup valgrind --log-file=valgrind_htmlparser.log --num-callers=30 --read-var-info=yes --leak-check=full --error-limit=no --undef-value-errors=no --show-reachable=yes -v ./DeepNetTool --configfile ../../Scripts/conf/deepnet.tool.conf --htmlUnitTestPath ../../Scripts/tests/html/ &
cd ${TMP}