#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

watch "ps aux| grep -i server | grep -i bot | grep -v grep ; echo "===================" ; ps aux | grep -i mysql | grep -v grep ; echo "==================="; ifconfig eth0;  echo "==================="; free -m;  echo "==================="; df -h"
