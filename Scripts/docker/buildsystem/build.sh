#!/bin/bash

source settings.env

echo "local install dir: ${LOCAL_INSTALL_DIR}"
mkdir -p "${LOCAL_INSTALL_DIR}"
#rm -rf ${LOCAL_INSTALL_DIR}/*

cat Dockerfile.template | envsubst > Dockerfile
docker build -t deepnet/imagebuilder:latest .
docker run -v ${LOCAL_INSTALL_DIR}:${INSTALL_DIR} deepnet/imagebuilder:latest /opt/install_apps.sh "${RELEASE_TYPE}" "${INSTALL_DIR}" "${CHECKOUT_DIR}" "dbsvc.deepnet" "root" "${MYSQL_ROOT_PASSWORD}"