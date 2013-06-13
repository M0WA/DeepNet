/**
 *
 * @file IndexerFactory.h
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#pragma once

#include <Pointer.h>

namespace database {
	class DatabaseConnection;
}

namespace indexing {

class IIndexer;
class IndexerFactory {
public:
	typedef enum {
		FLEX,
		OWN,

		MAX_INDEXER_TYPE,
	} IndexerType;

private:
	IndexerFactory();
public:
	virtual ~IndexerFactory();

public:
	static bool CreateInstance(database::DatabaseConnection* db,const IndexerType& type, tools::Pointer<IIndexer>& indexer);
};

}
