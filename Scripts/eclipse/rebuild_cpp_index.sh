#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

killall eclipse
rm ../../.metadata/.plugins/org.eclipse.cdt.core/*
nohup eclipse&
rm nohup.out