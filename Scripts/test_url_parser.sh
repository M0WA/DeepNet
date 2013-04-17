#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

DEEPNETTOOL_PATH=""

TMP=`pwd`

cd ../DeepNetTool
if [[ $* == *--debug* ]]; then
	DEEPNETTOOL_PATH="Debug/"
else
	DEEPNETTOOL_PATH="Release/"
fi
${DEEPNETTOOL_PATH}./DeepNetTool --configfile ../Scripts/conf/deepnet.tool.conf --urlValidateFile ../Scripts/tests/url/unit_test.url.txt --urlInvalidateFile ../Scripts/tests/url/unit_test_invalid_url.txt
if [ $? -ne 0 ]; then
 	cd ${TMP}
    exit 1
fi
cd ${TMP}