#!/bin/bash

source settings.env

echo "building db"
( cd percona && ./build.sh )

echo "building software"
( cd buildsystem && ./build.sh )

echo "building fastcgi servers"
( cd nginx && ./build.sh )

for APP in "${APPLICATIONS[@]}"; do
	echo "${APP}: building image"
	( cd application && ./build.sh "${APP}" )
done
