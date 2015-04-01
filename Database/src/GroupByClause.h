/**
 * @file GroupByClause.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>

namespace database {

class DatabaseConnection;

/**
 * @brief implements generic sql "GROUP BY" parts.
 * implements generic sql "GROUP BY" parts for sql statements.
 */
class GroupByClause {
private:
	typedef std::pair<std::string,std::string> GROUPBY_CLAUSE;

public:
	GroupByClause();
	virtual ~GroupByClause();

	/**
	 * adds a new field to group by.
	 * group by fields are added in the order they were inserted.
	 * @param fullTableName table name or alias.
	 * @param field field name.
	 * @return false on error, true on success.
	 */
	bool AddGroupByFieldname(const std::string& fullTableName, const std::string& field);

	/**
	 * gets sql equivalent of this group by part.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToString(database::DatabaseConnection* db) const;

private:
	std::vector< GROUPBY_CLAUSE > groupByFields;
};

}

