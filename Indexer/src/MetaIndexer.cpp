/*
 * MetaIndexer.cpp
 *
 *  Created on: 13.03.2012
 *      Author: Moritz Wagner
 */

#include "MetaIndexer.h"
#include <cstring>

#include "../generated/meta_parser.tab.hpp"

namespace indexing {

MetaIndexer::MetaIndexer(database::DatabaseConnection* database,const IndexerBase::IndexerType type)
: IndexerBase(database,type)
{
	ctx = new MetaIndexerCtx(this);
}

MetaIndexer::~MetaIndexer()
{
	delete ctx;
	ctx = 0;
}

MetaIndexer* MetaIndexer::CreateIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type)
{
	return 0;
	//return new MetaIndexer(database,type);
}

void MetaIndexer::OnParse(const long long paragraph)
{
	MetaIndexerHelper::ParseFromContext(reinterpret_cast<MetaIndexerCtx*>(ctx));
}

}
