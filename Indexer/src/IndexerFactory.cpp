/**
 *
 * @file IndexerFactory.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "IndexerFactory.h"

#include "GenericWebIndexer.h"
#include "DataminingIndexer.h"

namespace indexing {

IndexerFactory::IndexerFactory() {
}

IndexerFactory::~IndexerFactory() {
}

Indexer* IndexerFactory::CreateGenericWebIndexer(const IndexerParam* param){
	return new GenericWebIndexer(param);
}

Indexer* IndexerFactory::CreateDataminingIndexer(const IndexerParam* param){
	return new DataminingIndexer(param);
}


}
