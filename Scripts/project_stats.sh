#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################


DIRS="../Database ../DOMParser ../Tools ../DeepNetTool ../DatabaseTool ../Networking ../Indexer ../Caching ../QueryServer ../Crawler ../Bot ../FastCGIServer ../Parser ../HtmlParser ../LibXMLParser ../Logging ../WorkerBot ../InspectorServer ../Threading ../SuggestServer"

sloccount --multiproject --details ${DIRS}
sloccount --multiproject ${DIRS}
rm -rf ../top_dir
