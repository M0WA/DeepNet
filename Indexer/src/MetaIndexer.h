/*
 * MetaIndexer.h
 *
 *  Created on: 13.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "IndexerBase.h"

namespace indexing {

class MetaIndexer;

}

struct MetaIndexerCtx : public IndexerCtx
{
	MetaIndexerCtx()
	: IndexerCtx(0)
	, indexer(0)
	{}

	MetaIndexerCtx(indexing::MetaIndexer* indexerMeta)
	: IndexerCtx((indexing::IndexerBase*)indexerMeta)
	, indexer(indexerMeta)
	{}

	indexing::MetaIndexer* indexer;

};

namespace indexing {

class MetaIndexer: public IndexerBase {

private:
	MetaIndexer(database::DatabaseConnection* database,const IndexerBase::IndexerType type);
public:
	virtual ~MetaIndexer();

public:
	static MetaIndexer* CreateIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type);

	void OnFactFinder() {}
	void OnGoogleAnalytics() {}

private:
	virtual void OnParse(const long long paragraph);
};

}
