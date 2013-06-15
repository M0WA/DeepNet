/*
 * GenericWebIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebIndexerThread.h"

#include "IndexerFactory.h"

namespace indexing {

GenericWebIndexerThread::GenericWebIndexerThread() {
}

GenericWebIndexerThread::~GenericWebIndexerThread() {
}

void GenericWebIndexerThread::OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent) {

	//TODO: make indexer type configurable via file config
	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::OWN_GENERIC,indexerContent);
	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::OWN_GENERIC,indexerMeta);
}

}
