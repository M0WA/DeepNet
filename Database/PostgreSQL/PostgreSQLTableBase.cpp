/**
 *
 * @file PostgreSQLTableBase.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLTableBase.h"

#include <postgres.h>
#include <libpq-fe.h>
#include <catalog/pg_type.h>

#include <TimeTools.h>
#include <StringTools.h>
#include <Logging.h>

#include "TableColumn.h"
#include "TableDefinition.h"
#include "TableColumnDefinition.h"

#include "DatabaseInvalidTypeException.h"
#include "DatabaseNoColumnsException.h"
#include "DatabaseInvalidColumnNameException.h"

namespace database {

PostgreSQLTableBase::PostgreSQLTableBase(TableDefinition* definition)
: TableBase( definition ){
}

PostgreSQLTableBase::~PostgreSQLTableBase() {
}

PostgreSQLTableBase* PostgreSQLTableBase::CreateInstance(PGresult* res, const int curRow) {

	std::string dbName("deepnet"),tblName;
	//
	//TODO:table and database name
	//
	// Oid tblOid = PQftable(res, 0);
	// SELECT * FROM pg_class WHERE tblOid = tblOid

	TableDefinitionCreateParam tblParam(dbName,tblName);

	PostgreSQLTableBase::CreateTableDefinition( res, tblParam );
	PostgreSQLTableBase* pTbl = new PostgreSQLTableBase(TableDefinition::CreateInstance(tblParam));
	pTbl->SetColumnValues(res,curRow);
	return pTbl;
}

void PostgreSQLTableBase::CreateTableDefinition(PGresult* res,TableDefinitionCreateParam& paramIn) {

	int noCol = PQnfields(res);
	if(noCol <= 0) {
		log::Logging::LogWarn("no columns in resultset for statement");
		THROW_EXCEPTION(database::DatabaseNoColumnsException);
		return; }

	for(int i = 0; i < noCol; i++) {
		char* colName = PQfname(res, i);

		TableColumnDefinitionCreateParam colCreateParam;
		colCreateParam.columnName = colName;

		Oid colType = PQftype(res, i);
		switch(colType)
		{
		case FLOAT8OID:
		case FLOAT4OID:
			colCreateParam.columnType = DB_TYPE_DOUBLE;
			break;

		case INT8OID:
		case OIDOID:
		case INT2OID:
		case INT4OID:
		case CHAROID:
		case BOOLOID:
			colCreateParam.columnType = DB_TYPE_INTEGER;
			break;

		case TEXTOID:
		case BYTEAOID:
			colCreateParam.columnType = DB_TYPE_VARCHAR;
			break;

		case ABSTIMEOID:
			colCreateParam.columnType = DB_TYPE_TIMESTAMP;
			break;

		default:
			THROW_EXCEPTION(database::DatabaseInvalidTypeException);
			break;
		}

		colCreateParam.isNullable = true;

		TableColumnDefinition* colDef = TableColumnDefinition::CreateInstance(colCreateParam);
		paramIn.columnDefinitions.push_back(colDef);
	}
}

void PostgreSQLTableBase::SetColumnValues(PGresult* res, const int curRow) {

	int noCol = PQnfields(res);
	if(noCol <= 0) {
		log::Logging::LogWarn("no columns in resultset for statement");
		THROW_EXCEPTION(database::DatabaseNoColumnsException);
		return; }

	for(int curCol = 0; curCol < noCol; curCol++) {

		char* colName = PQfname(res, curCol);
		TableColumn* tblCol = GetColumnByName(colName);
		if(!tblCol) {
			THROW_EXCEPTION(database::DatabaseInvalidColumnNameException);
			return; }

		if(PQgetisnull(res,curRow,curCol)) {
			tblCol->SetNull();
		}
		else {

			switch(tblCol->GetConstColumnDefinition()->GetColumnType()) {

			case DB_TYPE_DOUBLE:
			case DB_TYPE_INTEGER:
			case DB_TYPE_VARCHAR:
				tblCol->Set(PQgetvalue(res,curRow,curCol));
				break;

			case DB_TYPE_TIMESTAMP:
				{
					struct tm out;
					if(!tools::TimeTools::TryParseDate(PQgetvalue(res,curRow,curCol),out)) {
						THROW_EXCEPTION(database::DatabaseInvalidTypeException);
						return;	}
				}
				break;

			default:
				THROW_EXCEPTION(database::DatabaseInvalidTypeException);
				return;
			}
		}

		tblCol->SetClean();
	}
}

}
