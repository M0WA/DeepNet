#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

echo "maybe you have to install manually:"
echo " libmysqlclient-<version>"
echo ""
echo "installing prerequirements"

apt-get install build-essential \
libxml2 libxml2-dev \
libmysqlclient-dev mysql-server \
libpg-dev libpg \
libcurl3 libcurl3-dev \
libmagic-dev \
binutils libfcgi-dev libfcgi-perl lighttpd \
flex bison libfcgi++ libicu-dev libpcre3-dev \
libxml-dom-perl libdbd-sqlite3-perl libdbi-perl \
php5-cgi php5-curl php5-mysql perl \
sloccount \
hunspell-tools libhunspell-dev hunspell-de-de \
hunspell-ar hunspell-ko hunspell-en-us hunspell-gl-es \
hunspell-se hunspell-de-at hunspell-de-ch hunspell-de-de \
hunspell-de-med hunspell-da hunspell-en-ca hunspell-fr \
hunspell-hu hunspell-ne hunspell-ro hunspell-sh hunspell-sr \
hunspell-vi hunspell-uz hunspell-eu-es
