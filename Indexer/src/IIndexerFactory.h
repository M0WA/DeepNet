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

	/**
	 * @enum IndexerOptions
	 * generic option flags for indexing::IIndexer
	 */
	typedef enum {
		/**
		 * no options
		 */
		IDX_OPT_NONE   = 0x0,

		/**
		 * do not index word positions
		 */
		IDX_OPT_NO_POS = 0x1,
	} IndexerOptions;

private:
	IIndexerFactory();
public:
	virtual ~IIndexerFactory();

public:
	/**
	 * creates an instance of an IIndexer
	 * @param db database connection
	 * @param type indexer type
	 * @param opts indexer options
	 * @param indexer created indexer
	 * @return true if successful, false if unsuccessful
	 */
	static bool CreateInstance(database::DatabaseConnection* db,const IndexerType& type, const IndexerOptions& opts, tools::Pointer<IIndexer>& indexer);
};

}
