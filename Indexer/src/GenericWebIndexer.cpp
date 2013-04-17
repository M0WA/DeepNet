/*
 * GenericWebIndexer.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebIndexer.h"
#include "GenericWebIndexerThread.h"

namespace indexing {

GenericWebIndexer::GenericWebIndexer() {
}

GenericWebIndexer::~GenericWebIndexer() {
}

IndexerThread* GenericWebIndexer::CreateIndexerThread()
{
	return dynamic_cast<IndexerThread*>(new GenericWebIndexerThread());
}

}
