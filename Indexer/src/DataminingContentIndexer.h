/*
 * DataminingContentIndexer.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "ContentIndexer.h"
#include "DataminingDictionary.h"

namespace indexing {

class IndexerFactory;
class DataminingContentIndexer: public indexing::ContentIndexer {

	friend class IIndexerFactory;

private:
	DataminingContentIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type);
public:
	virtual ~DataminingContentIndexer();

public:
	virtual Dictionary& GetDictionary() { return dynamic_cast<Dictionary&>(dictionary); }

private:
	DataminingDictionary dictionary;
};

}

