#!/bin/bash

source settings.env

if [ ! -z "$1" ]; then
	export APPLICATIONS=("$1")
fi

echo "cleaning up"
./cleanup.sh $1 >/dev/null 2>&1

echo "creating namespace up"
kubectl create namespace "${NAMESPACE}" >/dev/null 2>&1

#./export_to_minikube.sh $1

echo "create database"
app_command "create" "db"

echo "wait for db"
sleep 30

echo "initializing database"
./init_database.sh

echo "initializing database urls"
./init_pages.sh

for APP in "${APPLICATIONS[@]}"; do
	if [[ "${APP}" == "db" ]]; then
		continue;
	fi

	app_command "create" "${APP}"
done