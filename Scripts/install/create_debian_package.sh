#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

# generate database sql
cd ../DatabaseTool
./create.sh --mysql
./create.sh --db2
./create_release_sql.sh --mysql
./create_release_sql.sh --db2
cd ../Scripts

# update and build release binaries
./update_and_compile_release.sh
if [ $? -ne 0 ]; then
    echo "ERROR: unsuccessful build, aborting..."
    exit 1
fi

# create base directories
rm -rf debian-pkg/binary/debian
mkdir -p debian-pkg/binary/debian
cd debian-pkg/binary/debian

# create control file
mkdir -p deepnet/DEBIAN
cp ../tmpl/deepnet_control.tmpl deepnet/DEBIAN/control

# create /usr/bin/
mkdir -p usr/bin
cd usr/bin
cp ../../../../../../DeepNetTool/Release/DeepNetTool      .
cp ../../../../../../WorkerBot/Release/WorkerBot          .
cp ../../../../../../QueryServer/Release/QueryServer      .
cp ../../../../../../SuggestServer/Release/SuggestServer  .
cd ../..

# create /etc/deepnet/
mkdir -p etc/deepnet/sql/mysql
mkdir -p etc/deepnet/sql/db2
cd etc/deepnet
cp ../../../../../conf/common.pages.conf.example      .
cp ../../../../../conf/worker.se.conf.example         worker.conf.example
cp ../../../../../conf/queryserver.com.conf.example   queryserver.conf.example
cp ../../../../../conf/deepnet.tool.conf.example      deepnet.tool.conf.example
cd sql
cp ../../../../../../../DatabaseTool/release/mysql.complete.sql  .
cp ../../../../../../../DatabaseTool/release/db2.complete.sql    .
cd ../../..

# actually build the deb-file
dpkg-deb --build deepnet
mv deepnet.deb ..
cd ..

# cleanup stuff
rm -rf debian
