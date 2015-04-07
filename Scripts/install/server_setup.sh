#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

source rename_example_conf_files.shlib
source init_websites.shlib

BASE_DIR="/opt/DeepNet"

# Complete Install:
# 1. Reset and install Debian-minimal in hetzner-webinterface

# waiting for raid to be initialized completely
watch "cat /proc/mdstat && echo ctrl+c to continue when discs are synced completely"

# upgrade os
apt-get update
apt-get upgrade
apt-get install subversion

# checkout, prerequirements and compile
mkdir -p ${BASE_DIR}
svn co https://svn.siridia.de/DeepNet ${BASE_DIR}
cd ${BASE_DIR}/Scripts
chmod u+x *.sh
./install_prerequirements.sh
./update_and_compile_release.sh

# initializing database
RenameExampleFile ${BASE_DIR}/Scripts/conf/db.generator.conf
cd ${BASE_DIR}/DatabaseTool
./create.sh --mysql --nogenerate

# initializing DeepNetTool for unit-tests and recompile it, this time with successful unit tests
RenameExampleFile ${BASE_DIR}/Scripts/conf/deepnet.tool.conf
cd ${BASE_DIR}/Scripts
./update_and_compile_release.sh

# initializing WorkerBot
RenameExampleFile ${BASE_DIR}/Scripts/conf/worker.se.conf
RenameExampleFile ${BASE_DIR}/Scripts/conf/worker.dm.conf
RenameExampleFile ${BASE_DIR}/Scripts/conf/worker.cs.conf

# initializing SuggestServer
RenameExampleFile ${BASE_DIR}/Scripts/conf/suggestserver.staging.se.conf

# initializing InspectorServer
RenameExampleFile ${BASE_DIR}/Scripts/conf/inspectorserver.staging.se.conf

# initializing QueryServer
RenameExampleFile ${BASE_DIR}/Scripts/conf/queryserver.staging.se.conf

# inserting starting pages for search engine indexes
RenameExampleFile ${BASE_DIR}/Scripts/conf/common.pages.conf
cd ${BASE_DIR}/Scripts
./insert_common_pages.sh

# initializing lighttpd
killall -09 lighttpd  # bäm,wixa ;)
InitWebsites ${BASE_DIR}

# initializing webinterface
RenameExampleFile ${BASE_DIR}/Scripts/webif/search/de/.lib/.db.conf.php

# initializing mysql
/etc/init.d/mysql stop
RenameExampleFile ${BASE_DIR}/Scripts/mysql/siridia.cnf
cd /etc/mysql/conf.d/
ln -s ${BASE_DIR}/Scripts/mysql/siridia.cnf
rm -f /var/lib/mysql/ib_logfile* # prevent mysql to cry over its own stupidity, grmlgrmlgrml...

# done, reboot now to apply eventual os updates
echo "DONE, DeepNet System installed, return to reboot..."
read
reboot