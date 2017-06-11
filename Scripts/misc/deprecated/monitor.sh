#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

watch "ps aux| grep -i server | grep -i bot | grep -v grep ; echo "===================" ; ps aux | grep -i mysql | grep -v grep ; echo "==================="; ifconfig eth0;  echo "==================="; free -m;  echo "==================="; df -h"
