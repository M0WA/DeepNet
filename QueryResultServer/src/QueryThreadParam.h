/**
 *
 * @file QueryThreadParam.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

namespace database {
	class DatabaseConnection;
}

namespace querylib {
	class Query;
}

namespace queryserver {

	class DictionaryInfoThread;

/**
 * @brief encapsulates thread parameters for a queryserver::QueryThread
 */
class QueryThreadParam {
public:
	/**
	 * creates parameters from database connection and a query
	 * @param dbConn database connection
	 * @param query query to process
	 */
	QueryThreadParam(database::DatabaseConnection* dbConn, const querylib::Query& query);
	virtual ~QueryThreadParam();

	/**
	 * database connection
	 */
	database::DatabaseConnection* dbConn;

	/**
	 * current query
	 */
	const querylib::Query& query;
};

/**
 * @brief encapsulates thread parameters for a queryserver::QueryThread that also uses information from the dictionary
 */
class QueryDictionaryThreadParam : public QueryThreadParam {
public:
	/**
	 * creates parameters from database connection, a query and dictionary information
	 * @param dbConn database connection
	 * @param query query to process
	 * @param dictInfo dictionary information thread (should have ended already)
	 */
	QueryDictionaryThreadParam(database::DatabaseConnection* dbConn, const querylib::Query& query, const DictionaryInfoThread* dictInfo);
	virtual ~QueryDictionaryThreadParam() {}

public:
	/**
	 * dictionary information
	 */
	const DictionaryInfoThread* dictInfo;
};

}

