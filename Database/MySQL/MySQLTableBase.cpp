/**
 * @file MySQLTableBase.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "MySQLTableBase.h"

#include <iostream>
#include <sstream>

#include "TableDefinition.h"
#include "TableDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnType.h"
#include "TableColumn.h"

#include "DatabaseHelper.h"
#include "DatabaseInvalidTypeException.h"
#include "DatabaseInvalidTypeConversionException.h"
#include "DatabaseNoColumnsException.h"

#include <TimeTools.h>

namespace database {

MySQLTableBase::MySQLTableBase(TableDefinition* definition)
: TableBase( definition ) {
}

MySQLTableBase::~MySQLTableBase() {
}

MySQLTableBase* MySQLTableBase::CreateInstance(
	const MYSQL_ROW& row,
	const MYSQL_FIELD* fieldNames,
	const unsigned int fieldCount)
{
	if(fieldCount<=0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	TableDefinitionCreateParam tblParam(fieldNames[0].db,fieldNames[0].table);

	MySQLTableBase::CreateTableDefinition( fieldNames, fieldCount, tblParam );
	MySQLTableBase* pTbl = new MySQLTableBase(TableDefinition::CreateInstance(tblParam));
	pTbl->SetColumnValues(row, fieldNames, fieldCount);
	return pTbl;
}

void MySQLTableBase::CreateTableDefinition(
		const MYSQL_FIELD* fieldNames,
		const unsigned int fieldCount,
		TableDefinitionCreateParam& paramIn)
{
	for(unsigned int i = 0;i< fieldCount;i++)
	{
		TableColumnDefinitionCreateParam colParam;
		colParam.columnName      = fieldNames[i].name;
		colParam.isPrimaryKey    = fieldNames->flags&PRI_KEY_FLAG;
		colParam.isAutoGenerated = fieldNames->flags&AUTO_INCREMENT_FLAG;
		colParam.isUniqueKey     = fieldNames->flags&UNIQUE_KEY_FLAG;
		colParam.isIndex         = fieldNames->flags&MULTIPLE_KEY_FLAG;
		colParam.isNullable      = ( (!(fieldNames->flags&NOT_NULL_FLAG)) || (fieldNames->flags&AUTO_INCREMENT_FLAG) || !(fieldNames->flags&NO_DEFAULT_VALUE_FLAG));
		colParam.hasDefaultValue = !(fieldNames->flags&NO_DEFAULT_VALUE_FLAG);

		// foreign key can only be determined by
		// querying the database 'information_scheme' table seperately
		// which would be quiet an expensive operation.
		// we dont need this information here, so we simply ignore it
		colParam.isForeignKey    = false;

		switch(fieldNames[i].type)
		{
		case MYSQL_TYPE_BIT:
		case MYSQL_TYPE_TINY:
		case MYSQL_TYPE_SHORT:
		case MYSQL_TYPE_LONG:
		case MYSQL_TYPE_LONGLONG:
		case MYSQL_TYPE_INT24:
		case MYSQL_TYPE_ENUM:
		case MYSQL_TYPE_SET:
			colParam.columnType = DB_TYPE_INTEGER;
			break;

		case MYSQL_TYPE_DECIMAL:
		case MYSQL_TYPE_DOUBLE:
		case MYSQL_TYPE_FLOAT:
		case MYSQL_TYPE_NEWDECIMAL:
			colParam.columnType = DB_TYPE_DOUBLE;
			break;

		case MYSQL_TYPE_TIMESTAMP:
		case MYSQL_TYPE_DATE:
		case MYSQL_TYPE_TIME:
		case MYSQL_TYPE_DATETIME:
			colParam.columnType = DB_TYPE_TIMESTAMP;
			break;

		case MYSQL_TYPE_VAR_STRING:
		case MYSQL_TYPE_VARCHAR:
		case MYSQL_TYPE_STRING:
		case MYSQL_TYPE_TINY_BLOB:
		case MYSQL_TYPE_MEDIUM_BLOB:
		case MYSQL_TYPE_LONG_BLOB:
		case MYSQL_TYPE_BLOB:
			colParam.columnType = DB_TYPE_VARCHAR;
			break;

			//unsupported
		case MYSQL_TYPE_NULL:
		case MYSQL_TYPE_YEAR:
		case MYSQL_TYPE_NEWDATE:
		case MYSQL_TYPE_GEOMETRY:
		default:
			THROW_EXCEPTION(DatabaseInvalidTypeException);
			break;
		}

		paramIn.columnDefinitions.push_back(TableColumnDefinition::CreateInstance(colParam));
	}

	if( paramIn.columnDefinitions.size() == 0 ) {
		THROW_EXCEPTION(DatabaseNoColumnsException);	}
}

void MySQLTableBase::SetColumnValues(
		const MYSQL_ROW& row,
		const MYSQL_FIELD* fieldNames,
		const unsigned int fieldCount)
{
	for(unsigned int i = 0;i< fieldCount;i++) {

		std::stringstream ssConvert;
		TableColumn* col = GetColumnByName(fieldNames[i].name);

		if( row[i] == 0 ) {

			col->SetNull();
		}
		else {

			switch(col->GetConstColumnDefinition()->GetColumnType())
			{

			case DB_TYPE_VARCHAR:
			case DB_TYPE_CHAR:
			case DB_TYPE_LARGE_TEXT:
				ssConvert << row[i];
				if(ssConvert.fail())
					THROW_EXCEPTION(DatabaseInvalidTypeConversionException);
				col->Set(ssConvert.str());
				break;

			case DB_TYPE_TIMESTAMP:
				ssConvert << row[i];
				{
					struct tm out;
					if(!tools::TimeTools::ParseSQLTimestamp(ssConvert.str(),out))
						THROW_EXCEPTION(DatabaseInvalidTypeConversionException);
					col->Set(out);
				}
				break;

			case DB_TYPE_DOUBLE:
				ssConvert << std::skipws << row[i];
				{
					double out;
					ssConvert >> out;
					if(ssConvert.fail())
						THROW_EXCEPTION(DatabaseInvalidTypeConversionException);
					col->Set(out);
				}
				break;

			case DB_TYPE_BIGINT:
			case DB_TYPE_INTEGER:
				ssConvert << std::skipws << row[i];
				{
					long long out;
					ssConvert >> out;
					if(ssConvert.fail())
						THROW_EXCEPTION(DatabaseInvalidTypeConversionException);
					col->Set(out);
				}
				break;

			default:
				THROW_EXCEPTION(DatabaseInvalidTypeException);
				break;
			}
		}
	}
}

}
