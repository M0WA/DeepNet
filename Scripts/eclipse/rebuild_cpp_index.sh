#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

killall eclipse
rm ../../.metadata/.plugins/org.eclipse.cdt.core/*
nohup eclipse&
rm nohup.out