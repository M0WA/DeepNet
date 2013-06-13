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

	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::FLEX_GENERIC,indexerContent);
	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::FLEX_GENERIC,indexerMeta);
}

}
