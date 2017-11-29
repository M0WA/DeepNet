#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

DEBUG=""

if [[ $* == *--debug* ]]; then
DEBUG="--debug"
echo "WARNING: enabling debug version of unit tests"
fi

function run_unittest() {

SCRIPT_NAME="tests/./$1 ${DEBUG}"
TEST_NAME=$2

  echo "Running unit-test: ${TEST_NAME}"
  $SCRIPT_NAME
  if [ $? -ne 0 ]; then
    echo "ERROR: unit-test: ${TEST_NAME} exited UNSUCCESSFUL"
    exit 1
  fi
}

run_unittest "test_pcre_processor.sh" "pcre regex"
run_unittest "test_indexer.sh" "indexer"
run_unittest "test_url_parser.sh" "url parser"
run_unittest "test_html_parser.sh" "html parser"
run_unittest "test_dom_parser.sh" "DOM parser"
run_unittest "test_http_client.sh" "http client"
run_unittest "test_syncing.sh" "crawler syncronisation"

echo "all unit-tests exited SUCCESSFULLY"
exit 0
