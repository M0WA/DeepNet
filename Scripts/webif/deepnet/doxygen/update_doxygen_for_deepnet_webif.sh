#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

rm doxygen.tgz
svn up doxygen.tgz
rm -rf html
mkdir -p html
tar -zxvf doxygen.tgz -C html
echo "done"
