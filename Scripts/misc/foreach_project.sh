#!/bin/bash

BASE_DIR_TMP=`pwd`  
PROJECT_NAMES="Database Caching Logging Bot Threading Networking HtmlParser Crawler Indexer Parser FastCGIServer Tools DOMParser LibXMLParser InspectorServer SuggestServer QueryServer DeepNetTool WorkerBot"


for PROJECT in $PROJECT_NAMES; do

  echo "Executing for project ${PROJECT}"
  cd ../${PROJECT}
  $1
  cd $BASE_DIR_TMP
  
done;