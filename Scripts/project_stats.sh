#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################


DIRS="../Database ../DOMParser ../Tools ../DeepNetTool ../DatabaseTool ../Networking ../Indexer ../Caching ../QueryServer ../Crawler ../Bot ../FastCGIServer ../Parser ../HtmlParser ../LibXMLParser ../Logging ../WorkerBot ../InspectorServer ../Threading ../SuggestServer"

sloccount --multiproject --details ${DIRS}
sloccount --multiproject ${DIRS}
rm -rf ../top_dir
