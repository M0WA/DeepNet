/*
 * GenericWebIndexer.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Indexer.h"

namespace indexing {

class IndexerThread;
class GenericWebIndexer: public indexing::Indexer {
public:
	GenericWebIndexer();
	virtual ~GenericWebIndexer();

private:
	virtual IndexerThread* CreateIndexerThread();
};

}

