/*
 * DataminingIndexer.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Indexer.h"
#include "DataminingIndexerThread.h"

namespace indexing {

class IndexerThread;
class DataminingIndexer: public indexing::Indexer {
public:
	DataminingIndexer();
	virtual ~DataminingIndexer();

private:
	virtual IndexerThread* CreateIndexerThread();
};

}

