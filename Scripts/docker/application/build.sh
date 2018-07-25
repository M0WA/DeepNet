#!/bin/bash

export APPLICATION="$1"
export APPLICATION_LC=$(echo "${APPLICATION}" | tr '[:upper:]' '[:lower:]')

TEMPLATE_FILE=Dockerfile.template
if [ -f "Dockerfile.${APPLICATION}.template" ]; then
	TEMPLATE_FILE="Dockerfile.${APPLICATION}.template"
fi

cat "${TEMPLATE_FILE}" | envsubst > Dockerfile
docker build -t deepnet/${APPLICATION_LC}:intermediate .
docker run --name ${APPLICATION_LC}_intermediate --entrypoint=/usr/bin/env -v ${LOCAL_INSTALL_DIR}/${APPLICATION}:/opt/${APPLICATION}Install:ro deepnet/${APPLICATION_LC}:intermediate cp -r /opt/${APPLICATION}Install /opt/${APPLICATION}
docker commit ${APPLICATION_LC}_intermediate deepnet/${APPLICATION_LC}:latest
docker rm -f ${APPLICATION_LC}_intermediate
docker rmi deepnet/${APPLICATION_LC}:intermediate