/*
 * GenericWebIndexerThread.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "IndexerThread.h"

namespace indexing {

class IndexerFactory;
class GenericWebIndexerThread : public indexing::IndexerThread {
public:
	GenericWebIndexerThread();
	virtual ~GenericWebIndexerThread();

private:
	virtual void OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent);
};

}

