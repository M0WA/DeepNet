/*
 * GenericWebIndexerThread.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebIndexerThread.h"
#include "GenericWebContentIndexer.h"

namespace indexing {

GenericWebIndexerThread::GenericWebIndexerThread() {
}

GenericWebIndexerThread::~GenericWebIndexerThread() {
}

IIndexer* GenericWebIndexerThread::CreateIndexer()
{
	return dynamic_cast<IIndexer*>(new GenericWebContentIndexer(DB().Connection(),indexing::IndexerBase::BODY_CONTENT));
}

}
