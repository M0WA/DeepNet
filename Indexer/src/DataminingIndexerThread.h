/*
 * DataminingIndexerThread.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "IndexerThread.h"

namespace indexing {

class IIndexer;
class DataminingIndexerThread: public indexing::IndexerThread {
public:
	DataminingIndexerThread();
	virtual ~DataminingIndexerThread();

private:
	virtual void OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent);
};

}

