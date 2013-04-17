#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

TMP=`pwd`
cd ../QueryServer/Debug
#  --track-origins=yes
nohup valgrind --log-file=valgrind.log --num-callers=30 --read-var-info=yes --leak-check=full --error-limit=no --undef-value-errors=no --show-reachable=yes -v ./QueryServer --configfile ../../Scripts/conf/queryserver.conf &
cd ${TMP}