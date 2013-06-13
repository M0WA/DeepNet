/*
 * DataminingIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingIndexerThread.h"

#include "IndexerFactory.h"

namespace indexing {

DataminingIndexerThread::DataminingIndexerThread() {
}

DataminingIndexerThread::~DataminingIndexerThread() {
}

void DataminingIndexerThread::OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent) {

	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::FLEX_DATAMINING,indexerContent);
	IndexerFactory::CreateInstance(DB().Connection(),IndexerFactory::FLEX_DATAMINING,indexerMeta);
}

}
