#!/bin/bash

#./update_and_compile_release.sh
#if [ $? -ne 0 ]; then
#    echo "ERROR: unsuccessful build, aborting..."
#    exit 1
#fi

rm -rf debian-pkg/binary/debian
mkdir -p debian-pkg/binary/debian
cd debian-pkg/binary/debian

mkdir -p deepnet/DEBIAN
cp ../deepnet_control.tmpl deepnet/DEBIAN/control

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



#PACKAGE_NAME="deepnet"
#PACKAGE_VERSION="1.0-1"

#mkdir -p debian-pkg/source/debian/source/
#cd debian-pkg/source

# control file
#equivs-control ${PACKAGE_NAME}-src

#changelog
#dch --create -v ${PACKAGE_VERSION} --package ${PACKAGE_NAME}-src

#compat
#echo -n "8" > debian/compat

#copyright
#touch debian/copyright

#rules
#echo -n " \
#!/usr/bin/make -f \
#%: \
#	dh $@ \
#EOF" > debian/rules

#echo -n "3.0 (quilt)" debian/source/format

#cd debian-pkg
#equivs-build deepnet
#lintian deepnet_1.0_all.deb
#dch --create -v 1.0-1 --package deepnet
