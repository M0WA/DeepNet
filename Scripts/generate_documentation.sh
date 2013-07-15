#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

echo "cleaning old documentation"
rm -rf doc
mkdir -p doc

echo "generating documentation" 
cd ..
doxygen Scripts/doxygen/Doxyfile
cd Scripts

echo "creating doxygen archive for deepnet website"
rm -rf doxygen/doxygen.tgz
tar -zcf doxygen/doxygen.tgz -C doc/html .
echo "please use ./update_doxygen_for_deepnet_webif.sh to update doxygen documentation on your server"
