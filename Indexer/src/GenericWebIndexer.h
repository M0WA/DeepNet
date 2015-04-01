/*
 * GenericWebIndexer.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Indexer.h"

namespace indexing {

class IndexerFactory;
class IndexerThread;
class GenericWebIndexer: public indexing::Indexer {

	friend class IndexerFactory;

private:
	GenericWebIndexer(const IndexerParam* param);
public:
	virtual ~GenericWebIndexer();

private:
	virtual IndexerThread* CreateIndexerThread();
};

}

