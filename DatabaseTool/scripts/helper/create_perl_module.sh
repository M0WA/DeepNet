#!/bin/bash

MODULE_NAME=$1

cd scripts/modules
h2xs -b 5.6.1 -AX $MODULE_NAME
cd ../..
