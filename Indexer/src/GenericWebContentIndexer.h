/*
 * GenericWebContentIndexer.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "ContentIndexer.h"
#include "GenericWebDictionary.h"

namespace indexing {

class Dictionary;

class GenericWebContentIndexer: public indexing::ContentIndexer {

	friend class IIndexerFactory;

private:
	GenericWebContentIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type);
public:
	virtual ~GenericWebContentIndexer();

public:
	virtual Dictionary& GetDictionary() { return dynamic_cast<Dictionary&>(dictionary); }

private:
	GenericWebDictionary dictionary;
};

}

