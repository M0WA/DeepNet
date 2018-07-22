#!/bin/bash

source settings.env

mkdir -p ${LOCAL_INSTALL_DIR}
rm -rf ${LOCAL_INSTALL_DIR}/*

source settings.env
cat Dockerfile.template | envsubst > Dockerfile
docker build -t imagebuilder:latest .
docker run -v ${LOCAL_INSTALL_DIR}:${INSTALL_DIR} imagebuilder:latest /opt/install_apps.sh "${RELEASE_TYPE}" "${INSTALL_DIR}" "${CHECKOUT_DIR}"