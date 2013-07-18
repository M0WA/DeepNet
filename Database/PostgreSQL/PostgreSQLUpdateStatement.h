/**
 *
 * @file PostgreSQLUpdateStatement.h
 * @author Moritz Wagner
 * @date 18.07.2013
 *
 */

#pragma once

#include <string>

namespace database {

class DatabaseConnection;
class UpdateStatement;

class PostgreSQLUpdateStatement {
public:
	PostgreSQLUpdateStatement(const UpdateStatement& stmt);
	virtual ~PostgreSQLUpdateStatement();

public:
	std::string ToSQL(database::DatabaseConnection* db) const;

private:
	const UpdateStatement& orgStmt;
};

}
