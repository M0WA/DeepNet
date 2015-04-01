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
class IndexerFactory;
class DataminingIndexer: public indexing::Indexer {

	friend class IndexerFactory;

private:
	DataminingIndexer(const IndexerParam* param);
public:
	virtual ~DataminingIndexer();

private:
	virtual IndexerThread* CreateIndexerThread();
};

}

