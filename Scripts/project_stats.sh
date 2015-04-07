#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################


DIRS="../Database ../DOMParser ../Tools ../DeepNetTool ../DatabaseTool ../Networking ../Indexer ../Caching ../QueryServer ../Crawler ../Bot ../FastCGIServer ../Parser ../HtmlParser ../LibXMLParser ../Logging ../WorkerBot ../InspectorServer ../Threading ../SuggestServer ../Syncing ../SyncServer"

sloccount --multiproject --details ${DIRS}
sloccount --multiproject ${DIRS}
rm -rf ../top_dir
