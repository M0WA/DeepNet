/**
 *
 * @file IIndexerFactory.h
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#pragma once

#include <Pointer.h>

namespace database {
	class DatabaseConnection;
}

namespace indexing {

class IIndexer;

/**
 * @brief factory class for IIndexer interfaces
 * @see indexing::IIndexer
 */
class IIndexerFactory {
public:
	/**
	 * @enum IndexerType
	 */
	typedef enum {
		/**
		 * generic parser based on flex
		 */
		FLEX_GENERIC,

		/**
		 * own implementation of a simple parser
		 */
		OWN_GENERIC,

		/**
		 * datamining parser based on flex
		 */
		FLEX_DATAMINING,

		/**
		 * do not use
		 */
		MAX_INDEXER_TYPE,
	} IndexerType;

private:
	IIndexerFactory();
public:
	virtual ~IIndexerFactory();

public:
	/**
	 * creates an instance of an IIndexer
	 * @param db database connection
	 * @param type indexer type
	 * @param indexer created indexer
	 * @return true if successful, false if unsuccessful
	 */
	static bool CreateInstance(database::DatabaseConnection* db,const IndexerType& type, tools::Pointer<IIndexer>& indexer);
};

}
