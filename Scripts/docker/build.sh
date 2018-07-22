#!/bin/bash

source settings.env

echo "building software"
( cd buildsystem && ./build.sh )

echo "building db"
( cd percona && ./build.sh )

echo "building workerbot"
( cd application && ./build.sh WorkerBot )

echo "building queryserver"
( cd application && ./build.sh QueryServer )

echo "building suggestserver"
( cd application && ./build.sh SuggestServer )

echo "building syncserver"
( cd application && ./build.sh SyncServer )

echo "building deepnettool"
( cd application && ./build.sh DeepNetTool )

echo "building databasetool"
( cd application && ./build.sh DatabaseTool )