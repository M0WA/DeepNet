#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

PROJECT_NAMES="Database Caching Logging Bot Threading Networking HtmlParser Crawler Indexer Parser FastCGIServer WorkerBot InspectorServer SuggestServer QueryServer DeepNetTool"

INTERN_CALL=$1

if [ "${INTERN_CALL}" == 'intern_call' ]; then

  BASE_DIR_TMP=`pwd`
  cd ..
  svn up
  BASE_DIR=`pwd`
  cd $BASE_DIR_TMP

  echo "Fixing script permissions"
  chmod u+x ./*.sh
  chmod u+x ./misc/init_webinterface.sh
  
  ./update_and_compile_release.sh clean_projects

  for PROJECT in $PROJECT_NAMES; do

    echo "Compiling project ${PROJECT}"

    cd ${BASE_DIR}/${PROJECT}/Release
    if [ "${PROJECT}" == 'Indexer' ]; then
          echo ""
          echo "generating flex bison files for indexer"
          .././generate.sh release
	fi

    make -j all
    if [ $? -ne 0 ]; then
        echo "Error while comiling ${PROJECT}"
        exit 1
    fi

	echo "stripping symbols from ${PROJECT}"
	if [ -e "lib${PROJECT}.a" ]; then
		  ../../Scripts/misc/./create_symbol_file.sh lib${PROJECT}.a lib${PROJECT}.symbols
	else
		  ../../Scripts/misc/./create_symbol_file.sh ${PROJECT} ${PROJECT}.symbols
	fi
	echo "${PROJECT} built successful."
  done;

  cd $BASE_DIR_TMP
  
  echo "Running unit-tests"
  ./run_all_unit_tests.sh
  if [ $? -ne 0 ]; then
    ./update_and_compile_release.sh clean_projects
    echo "ERROR: unit-tests exited unsuccessful, aborting..."
    exit 1
  fi

  echo "Fixing script permissions again"
  chmod a+x ./*.sh

  ./reset_database.sh
  misc/./init_webinterface.sh
  
  echo "Done"

elif [ "${INTERN_CALL}" == 'clean_projects' ]; then

  echo "Cleaning projects"

  BASE_DIR_TMP=`pwd`
  cd ..
  BASE_DIR=`pwd`

  for PROJECT in $PROJECT_NAMES; do
    cd ${BASE_DIR}/${PROJECT}/Release
    make clean &> /dev/null
  done;

  cd ${BASE_DIR_TMP}

else

  echo "Updating update_and_compile_release.sh script itself"
  svn up update_and_compile_release.sh
  
  echo "Updating..."
  ./update_and_compile_release.sh intern_call
  if [ $? -ne 0 ]; then
    ./update_and_compile_release.sh clean_projects
    echo "ERROR: update process exited unsuccessful, aborting..."
    exit 1
  fi
  
fi

exit 0