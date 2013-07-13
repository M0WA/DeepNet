#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

rm -rf webif/deepnet/doxygen/html
mkdir -p webif/deepnet/doxygen/html
tar -zxvf doxygen/doxygen.tgz -C webif/deepnet/doxygen/html
echo "done"