#!/bin/bash

source settings.env


echo "building db"
( cd percona && ./build.sh )

echo "applications software"
( cd buildsystem && ./build.sh )

APPLICATIONS=("QueryServer" "SyncServer" "WorkerBot" "DeepNetTool" "SuggestServer" "DatabaseTool")
for APP in "${APPLICATIONS[@]}"; do
	echo "${APP}: building image"
	( cd application && ./build.sh "${APP}" )
done
