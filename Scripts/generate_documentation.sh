#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
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
rm -f webif/deepnet/doxygen/doxygen.tgz
tar -zcf webif/deepnet/doxygen/doxygen.tgz -C doc/html .
echo "please use ./update_doxygen_for_deepnet_webif.sh to update doxygen documentation on your server"
