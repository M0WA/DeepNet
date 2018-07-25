#!/bin/bash

source settings.env

unset DOCKER_TLS_VERIFY
unset DOCKER_HOST
unset DOCKER_CERT_PATH
unset DOCKER_API_VERSION

mkdir -p "${LOCAL_IMAGE_DIR}"

for APP in "${APPLICATIONS[@]}"; do
	echo "${APP}: export image to tar"
	docker save "deepnet/${APP}:latest" -o "${LOCAL_IMAGE_DIR}/${APP}.tar"
done

eval $(${MINIKUBE} docker-env)

for APP in "${APPLICATIONS[@]}"; do
	echo "${APP}: import image to minikube"
	docker load -i "${LOCAL_IMAGE_DIR}/${APP}.tar"
done

echo "done"

unset DOCKER_TLS_VERIFY
unset DOCKER_HOST
unset DOCKER_CERT_PATH
unset DOCKER_API_VERSION