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

class DataminingContentIndexer: public indexing::ContentIndexer {
public:
	DataminingContentIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type);
	virtual ~DataminingContentIndexer();

public:
	virtual Dictionary& GetDictionary() { return dynamic_cast<Dictionary&>(dictionary); }

private:
	DataminingDictionary dictionary;
};

}

