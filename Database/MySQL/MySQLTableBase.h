/**
 * @file MySQLTableBase.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include <mysql.h>
#include "TableBase.h"

namespace database {

class MySQLConnection;
class TableDefinitionCreateParam;
class TableDefinition;

/**
 * @brief implementation of database::TableBase for MySQL servers
 */
class MySQLTableBase : public TableBase {

	friend class MySQLConnection;

private:
	MySQLTableBase(TableDefinition* definition);
public:
	virtual ~MySQLTableBase();

public:
	static MySQLTableBase* CreateInstance(
	  		const MYSQL_ROW& row,
	  		const MYSQL_FIELD* fieldNames,
	  		const unsigned int fieldCount);

private:
	static void CreateTableDefinition(
			const MYSQL_FIELD* fieldNames,
			const unsigned int fieldCount,
			TableDefinitionCreateParam& paramIn);

private:
	void SetColumnValues(
			const MYSQL_ROW& row,
			const MYSQL_FIELD* fieldNames,
			const unsigned int fieldCount);
};

}

