/**
 *
 * @file IndexerFactory.cpp
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#include "IndexerFactory.h"

#include "IndexerEx.h"
#include "GenericWebContentIndexer.h"
#include "DataminingContentIndexer.h"

namespace indexing {

IndexerFactory::IndexerFactory() {
}

IndexerFactory::~IndexerFactory() {
}

bool IndexerFactory::CreateInstance(database::DatabaseConnection* db,const IndexerType& type, tools::Pointer<IIndexer>& indexer) {
	switch(type)
	{
	case OWN_GENERIC:
		indexer.Set(new IndexerEx(db),true);
		return true;

	case FLEX_GENERIC:
		indexer.Set(new GenericWebContentIndexer(db,indexing::IndexerBase::BODY_CONTENT),true);
		return true;

	case FLEX_DATAMINING:
		indexer.Set(new DataminingContentIndexer(db,indexing::IndexerBase::BODY_CONTENT),true);
		return true;

	default:
		return false;
	}
}

}
