#!/bin/bash

source settings.env

if [ ! -z "$1" ]; then
	export APPLICATIONS=("$1")
fi

for APP in "${APPLICATIONS[@]}"; do
	app_command "delete" "${APP}"
done