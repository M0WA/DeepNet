#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

./start_worker_bot.sh
./start_query_server.sh
./start_inspector_server.sh
./start_suggest_server.sh
./start_webif_server.sh
