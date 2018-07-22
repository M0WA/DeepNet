#!/bin/bash

RELEASE_TYPE=$1
INSTALL_DIR=$2
CHECKOUT_DIR=$3

APPLICATIONS=("QueryServer" "SyncServer" "WorkerBot" "DeepNetTool" "SuggestServer")

if [ "${RELEASE_TYPE}" == "release" ]; then
	RELEASE_DIR="Release"
else
	RELEASE_DIR="Debug"
fi

for PROG in "${APPLICATIONS[@]}"; do
	echo "${PROG}: creating directories"
	mkdir -p "${INSTALL_DIR}/${PROG}/bin" "${INSTALL_DIR}/${PROG}/etc";

	echo "${PROG}: copy binaries"
	cp "${CHECKOUT_DIR}/${PROG}/${RELEASE_DIR}/${PROG}" "${INSTALL_DIR}/${PROG}/bin/${PROG}";

	find "${CHECKOUT_DIR}/Scripts/conf" -iname "*${PROG}*" | xargs -L1 -I{} cp {} "${INSTALL_DIR}/${PROG}/etc/";
done

echo "installing DatabaseTool"
mkdir -p "${INSTALL_DIR}/DatabaseTool/bin/" "${INSTALL_DIR}/DatabaseTool/etc/"
cp -r "${CHECKOUT_DIR}/DatabaseTool" "${INSTALL_DIR}/DatabaseTool/bin"
cp -r "${CHECKOUT_DIR}/Scripts/conf/db.generator.conf.example" "${INSTALL_DIR}/DatabaseTool/etc/"
cp -r "${CHECKOUT_DIR}/Scripts/conf/common.pages.conf.example" "${INSTALL_DIR}/DatabaseTool/etc/"

echo "installing configurations"
cp "${CHECKOUT_DIR}/Scripts/conf/deepnet.tool.conf.example" "${INSTALL_DIR}/DeepNetTool/etc/"
find "${CHECKOUT_DIR}/Scripts/conf" -name "worker.*.conf.example" | xargs -L1 -I{} cp {} "${INSTALL_DIR}/WorkerBot/etc/";