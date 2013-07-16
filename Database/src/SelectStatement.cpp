/**
 * @file SelectStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "SelectStatement.h"
#include "TableDefinition.h"

#include <sstream>

#include "TableDefinition.h"
#include "TableColumnDefinition.h"

#include "DatabaseNoColumnsException.h"
#include <NotImplementedException.h>

namespace database {

SelectStatement::SelectStatement(TableDefinition* definition)
: Statement(Statement::SELECT_STMT, definition)
{
}

SelectStatement::SelectStatement(TableDefinition* definition, const std::string& tableAlias)
: Statement(Statement::SELECT_STMT, definition, tableAlias)
{
}

SelectStatement::~SelectStatement()
{
	std::vector<SelectColumn>::iterator iterCols = selectColumns.begin();
	for(int i = 0;iterCols != selectColumns.end();++iterCols,i++) {
		if(iterCols->doDelete) {
			delete iterCols->colDef; }
	}
}

void SelectStatement::SelectAllColumns() {
	const std::vector<TableColumnDefinition*>& vecCols = GetConstTableDefinition()->GetConstColumnDefinitions();
	std::vector<TableColumnDefinition*>::const_iterator iterCols = vecCols.begin();
	for(;iterCols != vecCols.end();++iterCols) {
		SelectColumn col;
		col.colDef = *iterCols;
		col.tableAlias = TableAlias();
		col.doDelete = false;
		selectColumns.push_back( col ); }
}

void SelectStatement::SelectAddColumn(TableColumnDefinition* column) {
	SelectColumn col;
	col.colDef = column;
	selectColumns.push_back( col );
}

void SelectStatement::SelectAddColumnAlias(TableColumnDefinition* column, const std::string& columnAlias) {
	SelectColumn col;
	col.colDef = column;
	col.columnAlias = columnAlias;
	selectColumns.push_back( col );
}

void SelectStatement::SelectAddColumn(TableColumnDefinition* column, const std::string& tableAlias, const std::string& columnAlias) {
	SelectColumn col;
	col.colDef      = column;
	col.columnAlias = columnAlias;
	col.tableAlias  = tableAlias;
	selectColumns.push_back( col );
}

void SelectStatement::SelectAddCountColumn(TableColumnDefinition* column, const std::string& tableAlias, const std::string& columnAlias) {
	SelectColumn col;
	col.colDef = column;
	col.columnAlias = columnAlias;
	col.tableAlias  = tableAlias;
	col.isCountColumn = true;
	selectColumns.push_back( col );
}

std::string SelectStatement::CreateSelectColumnString() const {

	std::stringstream ssSelectCol;

	std::vector<SelectColumn>::const_iterator iterCols = selectColumns.begin();
	for(int i = 0;iterCols != selectColumns.end();++iterCols,i++) {
		if(i)
			ssSelectCol << ", ";

		std::string aliasString = iterCols->columnAlias.empty() ? " " : (" " + GetColumnAliasString(iterCols->columnAlias) + " ");

		std::string tableName = iterCols->colDef->GetTableName();
		if(!iterCols->tableAlias.empty()){
			tableName = iterCols->tableAlias;}

		if(iterCols->isCountColumn)
			ssSelectCol << " COUNT(";
		ssSelectCol << " " << tableName << "." << iterCols->colDef->GetColumnName();
		if(iterCols->isCountColumn)
			ssSelectCol << " ) ";
		ssSelectCol << aliasString;
	}

	return ssSelectCol.str();
}

std::string SelectStatement::GetColumnAliasString(const std::string& columnAlias) const {
	return " AS " + columnAlias + " ";
}

std::string SelectStatement::ToSQL(database::DatabaseConnection* db) const {

	if(selectColumns.size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	std::stringstream ssQuery;
	ssQuery << "SELECT " << CreateSelectColumnString() << " FROM "  << GetFullQualifiedTableName() << " " << tableAlias << " ";

	ssQuery << innerJoin.ToString(db);
	ssQuery << whereCondition.ToString(db);
	ssQuery << orderByClause.ToString(db);
	ssQuery << groupByClause.ToString(db);

	if(limit > 0)
		ssQuery << " LIMIT " << limit;

	return ssQuery.str();
}

}
