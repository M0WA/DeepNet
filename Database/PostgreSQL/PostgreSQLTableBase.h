/**
 *
 * @file PostgreSQLTableBase.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include "TableBase.h"

#include <libpq-fe.h>


namespace database {

class TableDefinitionCreateParam;
class TableDefinition;
class PostgreConnection;

/**
 * @brief implementation of database::TableBase for PostgreSQL servers
 */
class PostgreSQLTableBase: public database::TableBase {

private:
	PostgreSQLTableBase(TableDefinition* definition);
public:
	virtual ~PostgreSQLTableBase();

public:
	static PostgreSQLTableBase* CreateInstance(PGresult* res, const int curRow);

private:
	static void CreateTableDefinition(PGresult* res,TableDefinitionCreateParam& paramIn);

private:
	void SetColumnValues(PGresult* res, const int curRow);
};

}
