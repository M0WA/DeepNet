/*
 * DataminingIndexer.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingIndexer.h"
#include "DataminingIndexerThread.h"

namespace indexing {

DataminingIndexer::DataminingIndexer() {
}

DataminingIndexer::~DataminingIndexer() {
}

IndexerThread* DataminingIndexer::CreateIndexerThread()
{
	return dynamic_cast<IndexerThread*>(new DataminingIndexerThread());
}

}
