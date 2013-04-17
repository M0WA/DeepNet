/**
 * @file Statement.h
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#pragma once

#include <string>

namespace database {

class TableBase;
class TableDefinition;
class DatabaseConnection;
class InnerJoinCondition;

/**
 * @brief implements generic sql statement.
 * acts as a base class for all sql statements.
 */
class Statement {
public:
	/**
	 * @enum StatementType
	 * @brief type of sql statement.
	 */
	enum StatementType {
		/**
		 * insert statement.
		 * @see database::InsertStatement
		 */
		INSERT_STMT,

		/**
		 * insert or update (if duplicate).
		 * @see database::InsertOrUpdateStatement
		 */
		INSERT_OR_UPDATE_STMT,

		/**
		 * update statement.
		 * @see database::UpdateStatement
		 */
		UPDATE_STMT,

		/**
		 * select statement.
		 * @see database::SelectStatement
		 */
		SELECT_STMT,

		/**
		 * delete statement.
		 * @see database::DeleteStatement
		 */
		DELETE_STMT,
	};

private:
	Statement(const Statement& stmt);

protected:
	/**
	 * construct by type and table definition.
	 * @param typeIn statement type.
	 * @param tableDefinition table definition.
	 */
	Statement(const StatementType typeIn, TableDefinition* tableDefinition);

	/**
	 * construct by type and table definition using an alias name for the table.
	 * @param typeIn statement type.
	 * @param tableDefinition table definition.
	 * @param tableAlias alias name.
	 */
	Statement(const StatementType typeIn, TableDefinition* tableDefinition, const std::string& tableAlias);

	/**
	 * construct by type and using an existing table's table definition.
	 * @param typeIn statement type.
	 * @param tableBase existing table.
	 */
	Statement(const StatementType typeIn, TableBase* tableBase);

public:
	virtual ~Statement();

public:
	/**
	 * gets table alias of this statement's table.
	 * @return empty if no alias specified, otherwise alias name for this statement's table.
	 */
	const std::string& TableAlias  (void) const;

	/**
	 *  gets table name of this statement's table.
	 * @return table name.
	 */
	const std::string& TableName   (void) const;

	/**
	 *  gets database name of this statement's table.
	 * @return database name.
	 */
	const std::string& DatabaseName(void) const;

public:
	/**
	 * gets inner join condition for this statement.
	 * @return inner join condition.
	 */
	virtual InnerJoinCondition& InnerJoin()=0;

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	virtual std::string ToSQL(database::DatabaseConnection* db) const=0;

	/**
	 * sets the LIMIT part of the sql statement
	 * @param limit maximum number of returned rows (0 to disable).
	 */
	void SetLimit(unsigned int limit);

protected:
	/**
	 * gets the fully qualified name of this statement's table.
	 * i.e. database_name.table_name.
	 * @return fully qualified name.
	 */
	std::string GetFullQualifiedTableName() const;

protected:
	/**
	 * definition of this statement's table.
	 */
	TableDefinition* tableDefinition;

	/**
	 * table alias, empty if disabled.
	 */
	std::string tableAlias;

	/**
	 * maximum number of rows returned
	 * @see database::Statement::SetLimit
	 */
	unsigned int limit;

	/**
	 * type of this statement.
	 */
	StatementType typeStmt;

private:
	bool deleteDefinition;
};

}
