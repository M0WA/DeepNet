#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

XML_STRUCTURE_FILE="xml/structure.xml"

rm -f sql/*.sql
rm -f src/*.cpp src/*.h
scripts/helper/./compile_perl_modules.sh
scripts/./generate_ddl.pl ${XML_STRUCTURE_FILE}
scripts/./generate_cpp.pl ${XML_STRUCTURE_FILE}

chmod a+w -R ../Database/generated/*.cpp ../Database/generated/*.h
rm -f ../Database/generated/*.h ../Database/generated/*.cpp
cp src/*.h   ../Database/generated
cp src/*.cpp ../Database/generated
chmod a-w -R ../Database/generated/*.cpp ../Database/generated/*.h
