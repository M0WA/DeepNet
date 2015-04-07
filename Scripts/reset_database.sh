#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

cd ../DatabaseTool
./create.sh --nogenerate --mysql

cd ../Scripts
if [[ $* == *--debug* ]]; then
	./insert_common_pages.sh --debug
else
	./insert_common_pages.sh
fi

