#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
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

