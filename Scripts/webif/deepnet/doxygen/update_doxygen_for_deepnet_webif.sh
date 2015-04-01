#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

rm doxygen.tgz
svn up doxygen.tgz
rm -rf html
mkdir -p html
tar -zxvf doxygen.tgz -C html
echo "done"
