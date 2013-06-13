/**
 *
 * @file IndexerEx.h
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#pragma once

#include "IIndexer.h"
#include "GenericWebDictionary.h"

namespace database {
	class DatabaseConnection;
}

namespace indexing {

class IndexerFactory;
class IndexerEx : public IIndexer {

	friend class IndexerFactory;

private:
	IndexerEx(database::DatabaseConnection* database);
public:
	virtual ~IndexerEx();

public:
	virtual void Parse(const std::string& input, const long long paragraph);
	virtual Dictionary& GetDictionary() { return dictionary; }

private:
	database::DatabaseConnection* db;
	GenericWebDictionary dictionary;
};

}
