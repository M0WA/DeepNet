#!/bin/bash

source settings.env

for APP in "${FASTCGI_SERVICES[@]}"; do
	echo "${APP}: building image"
	export FCGI_SERVICE=${APP}
	cat Dockerfile.template | envsubst > Dockerfile
	docker build -t "deepnet/${APP}fcgi:latest" .
done