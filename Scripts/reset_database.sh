#!/bin/bash

cd ../DatabaseTool
./create.sh --nogenerate --mysql
cd ../Scripts
./insert_common_pages.sh --debug