/**
 *
 * @file IIndexerFactory.cpp
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#include "IIndexerFactory.h"

#include "IndexerEx.h"
#include "GenericWebContentIndexer.h"
#include "DataminingContentIndexer.h"

namespace indexing {

IIndexerFactory::IIndexerFactory() {
}

IIndexerFactory::~IIndexerFactory() {
}

bool IIndexerFactory::CreateInstance(database::DatabaseConnection* db,const IndexerType& type, const IndexerOptions& opts, tools::Pointer<IIndexer>& indexer) {
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
