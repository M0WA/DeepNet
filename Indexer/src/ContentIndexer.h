/*
 * ContentIndexer.h
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

#include "IndexerBase.h"

namespace indexing {

class ContentIndexer;

}

struct ContentIndexerCtx : public IndexerCtx
{
	ContentIndexerCtx()
	: IndexerCtx(0)
	, indexer(0)
	{}

	ContentIndexerCtx(indexing::ContentIndexer* indexerContent)
	: IndexerCtx((indexing::IndexerBase*)indexerContent)
	, indexer(indexerContent)
	{}

	indexing::ContentIndexer* indexer;

};

namespace indexing {

class ContentIndexer : public IndexerBase
{
protected:
	ContentIndexer(database::DatabaseConnection* database,const IndexerBase::IndexerType type);
public:
	virtual ~ContentIndexer();

public:
	virtual void OnCharacterReference(std::string* characterReference);
	virtual void OnHtmlEntity(std::string* entity);
	virtual void OnWord(std::string* word);
	virtual void TerminateWord(void);

private:
	virtual void OnParse(const long long paragraph);

private:
	std::string tmpWord;

	long long posWord;
	long long paragraph;

};

}
