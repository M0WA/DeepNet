#!/bin/bash

source settings.env

if [ ! -z "$1" ]; then
	export APPLICATIONS=("$1")
fi

kubectl create namespace "${NAMESPACE}" >/dev/null 2>&1

for APP in "${APPLICATIONS[@]}"; do
	if [ -f "${APP}/service.yaml" ]; then
		echo "${APP}: removing existing services"
		kubectl delete --namespace="${NAMESPACE}" service ${APP}svc >/dev/null 2>&1

		echo "${APP}: creating service"
		kubectl create -f "${APP}/service.yaml"
	fi

	if [ -f "${APP}/deployment.yaml" ]; then
		echo "${APP}: removing existing deployments"
		kubectl delete --namespace="${NAMESPACE}" deployment ${APP} >/dev/null 2>&1

		echo "${APP}: creating deployment"
		kubectl create -f "${APP}/deployment.yaml"
	fi
done