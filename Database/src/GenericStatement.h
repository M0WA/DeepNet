/**
 * @file GenericStatement.h
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#pragma once

#include "Statement.h"

namespace database {

/**
 * @brief implements generic sql statement.
 */
class GenericStatement : public Statement {
public:
	/**
	 * construct by type and an existing sql query string.
	 * @param typeIn statement type.
	 * @param query sql query string.
	 */
	GenericStatement(const StatementType typeIn, const std::string& query);

	virtual ~GenericStatement();

public:
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL(database::DatabaseConnection* db) const;

private:
	std::string query;
};

}
