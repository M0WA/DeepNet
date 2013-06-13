/*
 * GenericWebIndexerThread.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "IndexerThread.h"

namespace indexing {

class IIndexer;
class GenericWebIndexerThread : public indexing::IndexerThread {
public:
	GenericWebIndexerThread();
	virtual ~GenericWebIndexerThread();

private:
	virtual IIndexer* CreateIndexer();
};

}

