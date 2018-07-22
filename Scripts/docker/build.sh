#!/bin/bash

echo "building software"
( cd buildsystem && ./build.sh )

echo "building db"
( cd percona && ./build.sh )
