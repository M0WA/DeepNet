#!/bin/bash

RELEASE_TYPE=$1
INSTALL_DIR=$2
CHECKOUT_DIR=$3

DB_HOST=$4
DB_USER=$5
DB_PASS=$6

SYNC_HOST=$7
SYNC_PASS=$8

APPLICATIONS=("QueryServer" "SyncServer" "WorkerBot" "DeepNetTool" "SuggestServer")

function config_db {
	FILE=$1
	sed -i'' "s/^dbhost=.*$/dbhost=${DB_HOST}/" "${FILE}"
	sed -i'' "s/^dbuser=.*$/dbuser=${DB_USER}/" "${FILE}"
	sed -i'' "s/^dbpass=.*$/dbpass=${DB_PASS}/" "${FILE}"
}

function config_dbgenerator {
	FILE=$1
	sed -i'' "s/^DBHOST=.*$/DBHOST=${DB_HOST}/" "${FILE}"
	sed -i'' "s/^DBUSER=.*$/DBUSER=${DB_USER}/" "${FILE}"
	sed -i'' "s/^DBPASS=.*$/DBPASS=${DB_PASS}/" "${FILE}"
}

function config_workerbot {
	FILE=$1
	sed -i'' "s/^crawler_sync_url=.*$/crawler_sync_url=${SYNC_HOST}/" "${FILE}"
	sed -i'' "s/^crawler_sync_pass=.*$/crawler_sync_pass=${SYNC_PASS}/" "${FILE}"
}

function config_log {
	LEVEL=$1
	FILE=$2
	sed -i'' "s/^[#\s]*log=.*$/log=console/" "${FILE}"
	sed -i'' "s/^[#\s]*loglevel=.*$/loglevel=${LEVEL}/" "${FILE}"
}

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


echo "configure SyncServer"
cp -r "${CHECKOUT_DIR}/Scripts/conf/syncserver.conf.example" "${INSTALL_DIR}/SyncServer/etc/syncserver.conf"
config_db "${INSTALL_DIR}/SyncServer/etc/syncserver.conf"
config_log "trace" "${INSTALL_DIR}/SyncServer/etc/syncserver.conf"

echo "installing DatabaseTool"
mkdir -p "${INSTALL_DIR}/DatabaseTool/bin/" "${INSTALL_DIR}/DatabaseTool/etc/"
cp -r "${CHECKOUT_DIR}/DatabaseTool" "${INSTALL_DIR}/DatabaseTool/bin"
cp -r "${CHECKOUT_DIR}/Scripts/conf/db.generator.conf.example" "${INSTALL_DIR}/DatabaseTool/etc/db.generator.mysql.conf"
config_dbgenerator "${INSTALL_DIR}/DatabaseTool/etc/db.generator.mysql.conf"

echo "configure DeepNetTool"
cp "${CHECKOUT_DIR}/Scripts/conf/deepnet.tool.conf.example" "${INSTALL_DIR}/DeepNetTool/etc/deepnettool.conf"
cp -r "${CHECKOUT_DIR}/Scripts/conf/common.pages.conf.example" "${INSTALL_DIR}/DatabaseTool/etc/common.pages.conf"
config_db "${INSTALL_DIR}/DeepNetTool/etc/deepnettool.conf"

echo "configure WorkerBot"
find "${CHECKOUT_DIR}/Scripts/conf" -name "worker.*.conf.example" | xargs -L1 -I{} cp {} "${INSTALL_DIR}/WorkerBot/etc/";
cp "${INSTALL_DIR}/WorkerBot/etc/worker.se.conf.example" "${INSTALL_DIR}/WorkerBot/etc/workerbot.conf"
config_db "${INSTALL_DIR}/WorkerBot/etc/workerbot.conf"
config_workerbot "${INSTALL_DIR}/WorkerBot/etc/workerbot.conf"
config_log "error" "${INSTALL_DIR}/WorkerBot/etc/workerbot.conf"
