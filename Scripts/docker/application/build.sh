#!/bin/bash

APPLICATION=$1
APPLICATION_LC=$(echo "${APPLICATION}" | tr '[:upper:]' '[:lower:]')

cat Dockerfile.template | envsubst > Dockerfile
docker build -t deepnet/${APPLICATION_LC}:intermediate .
docker run --name ${APPLICATION_LC}_intermediate -v ${LOCAL_INSTALL_DIR}/${APPLICATION}:/opt/${APPLICATION}Install:ro deepnet/${APPLICATION_LC}:intermediate cp -r /opt/${APPLICATION}Install /opt/${APPLICATION}
docker commit ${APPLICATION_LC}_intermediate deepnet/${APPLICATION_LC}:latest
docker rm -f ${APPLICATION_LC}_intermediate
docker rmi deepnet/${APPLICATION_LC}:intermediate