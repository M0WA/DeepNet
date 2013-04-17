#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

echo "Fixing permissions for commerce search webinterface (DE)"
chown -R www-data. webif/search/de/
chmod ug+rx webif/search/de/
