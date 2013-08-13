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

class QueryThreadParam {
public:
	QueryThreadParam(database::DatabaseConnection* dbConn, const Query& query);
	virtual ~QueryThreadParam();

	database::DatabaseConnection* dbConn;
	const Query& query;
};

}

