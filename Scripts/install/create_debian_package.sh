#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

./update_and_compile_release.sh
if [ $? -ne 0 ]; then
    echo "ERROR: unsuccessful build, aborting..."
    exit 1
fi

rm -rf debian-pkg/binary/debian
mkdir -p debian-pkg/binary/debian
cd debian-pkg/binary/debian

mkdir -p deepnet/DEBIAN
cp ../tmpl/deepnet_control.tmpl deepnet/DEBIAN/control

mkdir -p usr/bin
cd usr/bin
cp ../../../../../../DeepNetTool/Release/DeepNetTool      .
cp ../../../../../../WorkerBot/Release/WorkerBot          .
cp ../../../../../../QueryServer/Release/QueryServer      .
cp ../../../../../../SuggestServer/Release/SuggestServer  .
cd ../..

mkdir -p etc/deepnet
cd etc/deepnet
cp ../../../../../conf/common.pages.conf.example      .
cp ../../../../../conf/worker.se.conf.example         worker.conf.example
cp ../../../../../conf/queryserver.com.conf.example   queryserver.conf.example
cp ../../../../../conf/deepnet.tool.conf.example      deepnet.tool.conf.example
cd ../..

dpkg-deb --build deepnet
mv deepnet.deb ..
cd ..
rm -rf debian
