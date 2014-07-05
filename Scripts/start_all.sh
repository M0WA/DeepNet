#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

./start_worker_bot.sh
./start_query_server.sh
./start_inspector_server.sh
./start_suggest_server.sh
./start_webif_server.sh
