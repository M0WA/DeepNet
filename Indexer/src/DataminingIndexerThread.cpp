/*
 * DataminingIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingIndexerThread.h"

#include "IIndexerFactory.h"

namespace indexing {

DataminingIndexerThread::DataminingIndexerThread() {
}

DataminingIndexerThread::~DataminingIndexerThread() {
}

void DataminingIndexerThread::OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent) {

	IIndexerFactory::CreateInstance(DB().Connection(),IIndexerFactory::FLEX_DATAMINING,IIndexerFactory::IDX_OPT_NONE,indexerContent);
	IIndexerFactory::CreateInstance(DB().Connection(),IIndexerFactory::FLEX_DATAMINING,IIndexerFactory::IDX_OPT_NONE,indexerMeta);
}

}
