/**
 *
 * @file IndexerFactory.cpp
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#include "IndexerFactory.h"

#include "IndexerEx.h"

namespace indexing {

IndexerFactory::IndexerFactory() {
}

IndexerFactory::~IndexerFactory() {
}

bool IndexerFactory::CreateInstance(database::DatabaseConnection* db,const IndexerType& type, tools::Pointer<IIndexer>& indexer) {
	switch(type)
	{
	case OWN:
		indexer.Set(new IndexerEx(db),true);
		return true;

	default:
		return false;
	}
}

}
