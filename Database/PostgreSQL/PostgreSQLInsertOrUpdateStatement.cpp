/**
 *
 * @file PostgreSQLInsertOrUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 13.07.2013
 *
 */

#include "PostgreSQLInsertOrUpdateStatement.h"

#include <StringTools.h>
#include <Logging.h>

#include "InsertOrUpdateStatement.h"

#include "TableBase.h"
#include "TableDefinition.h"
#include "TableColumn.h"
#include "TableColumnDefinition.h"

#include "DatabaseNoColumnsException.h"
#include "DatabaseNoPrimaryKeyException.h"

#include "PostgreSQLUniqueKeyIsSumColumnException.h"
#include "PostgreSQLInvalidStatementException.h"

#include <NotImplementedException.h>

namespace database {

PostgreSQLInsertOrUpdateStatement::PostgreSQLInsertOrUpdateStatement(const InsertOrUpdateStatement& stmt)
: orgStatement(stmt){
}

PostgreSQLInsertOrUpdateStatement::~PostgreSQLInsertOrUpdateStatement() {
}

std::string PostgreSQLInsertOrUpdateStatement::UpdateByPrimaryKey( DatabaseConnection* db ) const {
	//
	//TODO
	//
	THROW_EXCEPTION(errors::NotImplementedException,"PostgreSQLInsertOrUpdateStatement::UpdateByPrimaryKey()");
	return "";
}

std::string PostgreSQLInsertOrUpdateStatement::UpdateOrInsertByUniqueKeys( DatabaseConnection* db ) const {

	//example:
	/*
	WITH new_values
	  (domain)
	AS
	  (VALUES ('domainname') ),
	upsert AS
	(
	  UPDATE deepnet.public.secondleveldomains m
	  SET
		domain = nv.domain
	  FROM new_values nv
	  WHERE
		m.domain = nv.domain
	  RETURNING m.*
	)
	INSERT INTO deepnet.public.secondleveldomains (domain)
	SELECT
	  domain
	FROM new_values
	WHERE NOT EXISTS
	(
	  SELECT
		1
	  FROM
		upsert up
	  WHERE
		domain = new_values.domain
	)
	*/

	std::vector<std::string>
		newValuesColumnNames, newValuesColumnValues,
		setNewValuesColumnNames, whereNewValuesColumnNames,
		whereInsertColumnNames;

	const TableBase* tableBase(orgStatement.GetConstTableBase());
	const TableDefinition* tblDef(tableBase->GetConstTableDefinition());

	const std::vector<TableColumn*>& cols(tableBase->GetConstColumns());
	std::vector<TableColumn*>::const_iterator iCols(cols.begin());
	for(;iCols != cols.end();++iCols) {

		const TableColumn* pCurCol(*iCols);
		const std::string& curColName(pCurCol->GetColumnName());
		const TableColumnDefinition* pCurColDef(tblDef->GetConstColumnDefinitionByName(curColName));

		/*
		if(orgStatement.IsSumColumn(curColName)) {
			THROW_EXCEPTION(errors::NotImplementedException,"PostgreSQLInsertOrUpdateStatement::UpdateOrInsertByUniqueKeys() for sum columns"); }
		*/

		//ignore primary keys, should be NULL anyway
		//otherwise UpdateOrInsertByUniqueKeys() would
		//not have been called in first place
		if(pCurColDef->IsPrimaryKey()) {
			if(!tableBase->GetConstColumnByName(curColName)->IsNull()) {
				THROW_EXCEPTION(PostgreSQLInvalidStatementException,0,"primary key cannot be NULL but it is"); }
			continue;}

		const TableColumnDefinition* pColDef(pCurCol->GetConstColumnDefinition());
		bool allowNullColumn = pColDef->HasDefaultValue() || pColDef->IsAutoGenerated();
		if(pCurCol->IsNull() && !allowNullColumn && !pCurCol->IsDirty()) {
			THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,0,curColName + " must contain value, column is not nullable and has no default value");}
		if(pCurCol->IsNull() && pCurCol->IsDirty()) {
			continue;}

		newValuesColumnNames.push_back(curColName);
		newValuesColumnValues.push_back(pCurCol->GetForSQL(db));
		if(orgStatement.IsSumColumn(curColName)) {
			setNewValuesColumnNames.push_back(curColName+"= m."+curColName +" + "+pCurCol->GetForSQL(db));
		}
		else {
			setNewValuesColumnNames.push_back(curColName+"=nvu."+curColName);

			if(pCurCol->IsDirty() && pCurColDef->IsUniqueKey() ){
				whereNewValuesColumnNames.push_back("m."+curColName+"=nvu."+curColName);}
			else if(pCurColDef->IsUniqueKey()) {
				log::Logging::LogTrace("unset unique key in update or insert statement: %s",curColName.c_str()); }

			//add unique columns to where clauses for non-sum columns matching requirements below
			bool test  = pCurCol->IsDirty() || (pCurColDef->IsNullable() && pCurCol->IsNull());
			bool test2 = pCurColDef->IsUniqueKey() && !pCurColDef->IsPrimaryKey();
			if(test || test2) {
				whereInsertColumnNames.push_back(curColName+"=nvi."+curColName);}
		}
	}

	if(whereNewValuesColumnNames.size() == 0){
		THROW_EXCEPTION(PostgreSQLInvalidStatementException,0,"statement has no unique key for insert or update"); }

	std::string newValuesColumnNamesString,newValuesColumnValuesString,setNewValuesColumnNamesString,whereNewValuesColumnNamesString,whereInsertColumnNamesString;
	tools::StringTools::VectorToString(newValuesColumnNames,newValuesColumnNamesString,",");
	tools::StringTools::VectorToString(newValuesColumnValues,newValuesColumnValuesString,",");
	tools::StringTools::VectorToString(setNewValuesColumnNames,setNewValuesColumnNamesString,",");
	tools::StringTools::VectorToString(whereNewValuesColumnNames,whereNewValuesColumnNamesString," OR ");
	tools::StringTools::VectorToString(whereInsertColumnNames,whereInsertColumnNamesString," OR ");

	std::string fullQualifiedTableName(tblDef->GetFullQualifiedTableName());
	std::stringstream ssQuery;
	ssQuery <<
" \
WITH vals \
	(" << newValuesColumnNamesString << ") \
AS \
	(VALUES (" << newValuesColumnValuesString << ") ), \
upsert AS \
( \
	UPDATE " << fullQualifiedTableName << " m \
	SET " << setNewValuesColumnNamesString << " \
	FROM vals nvu \
	WHERE " << whereNewValuesColumnNamesString << " \
	RETURNING m.* \
) \
INSERT INTO " << fullQualifiedTableName << " (" << newValuesColumnNamesString << ") \
SELECT " << newValuesColumnNamesString << " \
FROM vals nvi \
WHERE NOT EXISTS \
( \
	SELECT 1 \
	FROM upsert up \
	WHERE " << whereInsertColumnNamesString << " \
) \
RETURNING " << fullQualifiedTableName << "." << tblDef->GetConstPrimaryKeyColumnDefinition()->GetColumnName();
	return ssQuery.str();
}

std::string PostgreSQLInsertOrUpdateStatement::ToSQL( DatabaseConnection* db ) const {

	std::stringstream ssQuery;

	const TableBase* tableBase = orgStatement.GetConstTableBase();
	const TableDefinition* tblDef = tableBase->GetConstTableDefinition();

	if(tableBase->GetConstColumns().size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	const std::string& primaryKeyName = tblDef->GetConstPrimaryKeyColumnDefinition()->GetColumnName();
	const TableColumn* primaryKeyCol = tableBase->GetConstColumnByName(primaryKeyName);
	if(!primaryKeyCol) {
		THROW_EXCEPTION(DatabaseNoPrimaryKeyException); }

	if(!primaryKeyCol->IsNull()) {
		ssQuery << UpdateByPrimaryKey(db); }
	else {
		ssQuery << UpdateOrInsertByUniqueKeys(db); }

	return ssQuery.str();
}

}
