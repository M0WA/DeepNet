/**
 *
 * @file PostgreSQLInsertOrUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 13.07.2013
 *
 */

#include "PostgreSQLInsertOrUpdateStatement.h"

#include <StringTools.h>

#include "InsertOrUpdateStatement.h"

#include "TableBase.h"
#include "TableDefinition.h"
#include "TableColumn.h"
#include "TableColumnDefinition.h"

#include "DatabaseNoColumnsException.h"
#include "DatabaseNoPrimaryKeyException.h"
#include "PostgreSQLUniqueKeyIsSumColumnException.h"

#include <NotImplementedException.h>

namespace database {

PostgreSQLInsertOrUpdateStatement::PostgreSQLInsertOrUpdateStatement(const InsertOrUpdateStatement* stmt)
: orgStatement(stmt){
}

PostgreSQLInsertOrUpdateStatement::~PostgreSQLInsertOrUpdateStatement() {
}

std::string PostgreSQLInsertOrUpdateStatement::ToSQL( DatabaseConnection* db ) const {

	//example:
	/*
	WITH new_values (id, field1, field2) as (
	  values
	     (1, 'A', 'X'),
	     (2, 'B', 'Y'),
	     (3, 'C', 'Z')

	),
	upsert as
	(
	    update mytable m
	        set field1 = nv.field1,
	            field2 = nv.field2
	    FROM new_values nv
	    WHERE m.id = nv.id
	    RETURNING m.*
	)
	INSERT INTO mytable (id, field1, field2)
	SELECT id, field1, field2
	FROM new_values
	WHERE NOT EXISTS (SELECT 1
	                  FROM upsert up
	                  WHERE up.id = new_values.id)
	*/

	std::stringstream ssQuery;

	const TableBase* tableBase = orgStatement->GetConstTableBase();
	const TableDefinition* tblDef = tableBase->GetConstTableDefinition();

	const std::vector<TableColumn*>& cols = tableBase->GetConstColumns();
	if(cols.size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	std::vector<std::string> colVals,colNames, setColNames, uniqueCols, uniqueNewValueCols;
	std::vector<TableColumn*>::const_iterator iCols = cols.begin();
	for(;iCols != cols.end();++iCols) {

		TableColumn* col = (*iCols);
		const TableColumnDefinition* colDef = col->GetConstColumnDefinition();
		if(colDef->IsUniqueKey() || colDef->IsPrimaryKey()) {
			if(orgStatement->IsSumColumn(col->GetColumnName())) {
				THROW_EXCEPTION(database::PostgreSQLUniqueKeyIsSumColumnException,0,col->GetColumnName() + " is a sum column"); }

			colNames.push_back(col->GetColumnName());
			colVals.push_back(col->GetForSQL(db));
			setColNames.push_back(col->GetColumnName() + " = nv." + col->GetColumnName());

			uniqueNewValueCols.push_back(col->GetColumnName() + " = new_values." + col->GetColumnName());
			uniqueCols.push_back(col->GetColumnName() + " = nv." + col->GetColumnName());
		}

		if(orgStatement->IsSumColumn(col->GetColumnName()))	{
			//
			//TODO: handle "sum" columns
			//
			THROW_EXCEPTION(errors::NotImplementedException,"PostgreSQLInsertOrUpdateStatement::ToSQL() for sum columns");
		}
		else {
			colNames.push_back(col->GetColumnName());
			colVals.push_back(col->GetForSQL(db));

			setColNames.push_back(col->GetColumnName() + " = nv." + col->GetColumnName());
		}
	}

	std::string colNamesString,colValuesString,setColNamesString,uniqueColNamesString,uniqueNewValueColNamesString;
	tools::StringTools::VectorToString(colNames,colNamesString,",");
	tools::StringTools::VectorToString(colVals,colValuesString,",");
	tools::StringTools::VectorToString(setColNames,setColNamesString,",\n");
	tools::StringTools::VectorToString(uniqueCols,uniqueColNamesString," OR ");
	tools::StringTools::VectorToString(uniqueNewValueCols,uniqueNewValueColNamesString," OR ");

	ssQuery << " \
WITH new_values (" << colNamesString << ") as ( values (" << colValuesString << ") ), \
upsert as \
( \
    update " << tblDef->GetFullQualifiedTableName() << " m \
        set " << setColNamesString << " \
    FROM new_values nv \
    WHERE " << uniqueColNamesString << " \
    RETURNING m.* \
) \
INSERT INTO " << tblDef->GetFullQualifiedTableName() << " (" << colNamesString << ") \
SELECT " << colNamesString << " \
FROM new_values \
WHERE NOT EXISTS \
( \
  SELECT 1 \
  FROM upsert up \
  WHERE " << uniqueNewValueColNamesString <<
")";


	return ssQuery.str();
}

}
