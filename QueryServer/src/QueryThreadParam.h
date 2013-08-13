/**
 *
 * @file QueryThreadParam.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

namespace database {
	class DatabaseConfig;
}

namespace queryserver {

	class Query;

class QueryThreadParam {
public:
	QueryThreadParam(const database::DatabaseConfig* config, const Query& query);
	virtual ~QueryThreadParam();

	const database::DatabaseConfig* config;
	const Query& query;
};

}

