/*
 * DataminingIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingIndexerThread.h"
#include "DataminingContentIndexer.h"

namespace indexing {

DataminingIndexerThread::DataminingIndexerThread() {
}

DataminingIndexerThread::~DataminingIndexerThread() {
}

ContentIndexer* DataminingIndexerThread::CreateContentIndexer()
{
	return dynamic_cast<ContentIndexer*>(new DataminingContentIndexer(DB().Connection(),indexing::IndexerBase::BODY_CONTENT));
}

}
