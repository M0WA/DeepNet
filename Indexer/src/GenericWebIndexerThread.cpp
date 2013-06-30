/*
 * GenericWebIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebIndexerThread.h"

#include "IIndexerFactory.h"

namespace indexing {

GenericWebIndexerThread::GenericWebIndexerThread() {
}

GenericWebIndexerThread::~GenericWebIndexerThread() {
}

void GenericWebIndexerThread::OnCreateIndexer(
			tools::Pointer<IIndexer>& indexerMeta,
			tools::Pointer<IIndexer>& indexerContent) {

	//TODO: make indexer type configurable via file config
	IIndexerFactory::CreateInstance(DB().Connection(),IIndexerFactory::OWN_GENERIC,indexerContent);
	IIndexerFactory::CreateInstance(DB().Connection(),IIndexerFactory::OWN_GENERIC,indexerMeta);
}

}
