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

echo "Running unit-tests for pcre regexes"
tests/./test_pcre_processor.sh ${DEBUG}
if [ $? -ne 0 ]; then
  echo "ERROR: unit-tests for pcre regexes exited unsuccessful"
  exit 1
fi

echo "Running unit-tests for indexer"
tests/./test_indexer.sh ${DEBUG}
if [ $? -ne 0 ]; then
  echo "ERROR: unit-tests for indexer exited unsuccessful"
  exit 1
fi

echo "Running unit-tests for url-parser"
tests/./test_url_parser.sh ${DEBUG}
if [ $? -ne 0 ]; then
  echo "ERROR: unit-tests for url-parser exited unsuccessful"
  exit 1
fi

echo "Running unit-tests for html-parser"
tests/./test_html_parser.sh ${DEBUG}
if [ $? -ne 0 ]; then
  echo "ERROR: unit-tests for html-parser exited unsuccessful"
  exit 1
fi

echo "Running unit-tests for http client"
tests/./test_http_client.sh ${DEBUG}
if [ $? -ne 0 ]; then
  echo "ERROR: unit-tests for http client exited unsuccessful"
  exit 1
fi

exit 0