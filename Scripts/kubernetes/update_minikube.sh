#!/bin/bash

source settings.env

if [ ! -z "$1" ]; then
	export APPLICATIONS=("$1")
fi

./cleanup.sh $1

kubectl create namespace "${NAMESPACE}" >/dev/null 2>&1

./export_to_minikube.sh $1

echo "db: creating service"
kubectl create -f "db/service.yaml"

echo "db: creating deployment"
kubectl create -f "db/deployment.yaml"

sleep 60

echo "initializing database"
./init_database.sh

for APP in "${APPLICATIONS[@]}"; do
	if [[ "${APP}" == "db" ]]; then
		continue;
	fi

	if [ -f "${APP}/service.yaml" ]; then
		echo "${APP}: creating service"
		kubectl create -f "${APP}/service.yaml"
	fi

	if [ -f "${APP}/deployment.yaml" ]; then
		echo "${APP}: creating deployment"
		kubectl create -f "${APP}/deployment.yaml"
	fi
done