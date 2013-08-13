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

namespace queryserver {

	class Query;

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
	QueryThreadParam(database::DatabaseConnection* dbConn, const Query& query);
	virtual ~QueryThreadParam();

	/**
	 * database connection
	 */
	database::DatabaseConnection* dbConn;

	/**
	 * current query
	 */
	const Query& query;
};

}

