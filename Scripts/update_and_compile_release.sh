#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

function print_usage {
  echo "$0 [-d] [-w]"
  echo "-d reset database"
  echo "-w init webinterface"
  echo "-U skip unittests"
}

PROJECT_NAMES="Database Caching Logging Bot Threading Networking HtmlParser Crawler Indexer Parser FastCGIServer Tools DOMParser LibXMLParser WorkerBot InspectorServer SuggestServer QueryServer DeepNetTool"

UNITTESTS=1
CLEAN_DB=0
MAKE_WEBIF=0

function clean_projects {

  echo "Cleaning projects"

  BASE_DIR_TMP=`pwd`
  cd ..
  BASE_DIR=`pwd`

  for PROJECT in $PROJECT_NAMES; do
    cd ${BASE_DIR}/${PROJECT}/Release
    make clean &> /dev/null
  done;

  cd ${BASE_DIR_TMP}
}

function intern_call {  

  BASE_DIR_TMP=`pwd`
  cd ..
  svn up
  BASE_DIR=`pwd`
  cd $BASE_DIR_TMP

  echo "Fixing script permissions"
  chmod u+x ./*.sh
  chmod u+x ./tests/*.sh
  chmod u+x ./misc/init_webinterface.sh
  
  clean_projects

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
        echo "Error while compiling ${PROJECT}"
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

  echo "Fixing script permissions again"
  chmod a+x ./*.sh
  chmod u+x ./tests/*.sh
  
  if [ ${UNITTESTS} -ne 0 ]; then
    echo "Running unit-tests"
    ./run_all_unit_tests.sh
    if [ $? -ne 0 ]; then
      echo "ERROR: unit-tests exited unsuccessful, aborting..."
      exit 0
      # exit 1 #commented out to prevent cleaning of projects
               #when "only" the unit tests fail
    fi
  else
    echo "Skipping Unittests"
  fi

  if [ ${CLEAN_DB} -ne 0 ]; then
    echo "Resetting database"
    ./reset_database.sh
  fi

  if [ ${MAKE_WEBIF} -ne 0 ]; then
    misc/./init_webinterface.sh
  fi
  
  echo "Done"
}

######################################################################

while getopts "dwUh" opt; do
  case $opt in
    d)
      ${CLEAN_DB}=1
      ;;
    w)
      ${MAKE_WEBIF}=1
      ;;
    U)
      ${UNITTESTS}=0
      ;;
    h)
      print_usage
      exit 0
      ;;
    \?)
      print_usage
      echo "Invalid option: -$OPTARG"
      exit 1
      ;;
  esac
done

echo "Updating update_and_compile_release.sh script itself"
svn up update_and_compile_release.sh

echo "Updating..."
intern_call
if [ $? -ne 0 ]; then
  clean_projects
  echo "ERROR: update process exited unsuccessful, aborting..."
  exit 1
fi

exit 0
