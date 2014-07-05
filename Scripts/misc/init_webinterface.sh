#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

echo "Fixing permissions for commerce search webinterface (DE)"
chown -R www-data. webif/search/de/
chmod ug+rx webif/search/de/
