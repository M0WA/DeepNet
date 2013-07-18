/**
 * @file OrderByClause.h
 * @author Moritz Wagner
 * @date 22.05.2012
 */

#include "OrderByClause.h"
#include <sstream>

#include "TableColumnDefinition.h"
#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

OrderByClause::OrderByClause() {
}

OrderByClause::~OrderByClause() {

	std::vector<OrderByColumn>::iterator iter = orderByFields.begin();
	for(;iter != orderByFields.end();++iter) {
		delete iter->colDef;}
	orderByFields.clear();
}

bool OrderByClause::AddColumn(TableColumnDefinition* colDef, const OrderByClauseDirection& dir) {

	OrderByColumn col;
	col.colDef      = colDef;
	col.dir         = dir;
	col.tableAlias  = "";
	col.columnAlias = "";
	orderByFields.push_back(col);
	return true;
}

bool OrderByClause::AddColumn(
		TableColumnDefinition* colDef,
		const OrderByClauseDirection& dir,
		const std::string& tableAlias,
		const std::string& columnAlias) {

	OrderByColumn col;
	col.colDef      = colDef;
	col.dir         = dir;
	col.tableAlias  = tableAlias;
	col.columnAlias = columnAlias;
	orderByFields.push_back(col);
	return true;
}

std::string OrderByClause::ToString(database::DatabaseConnection* db) const {

	if(orderByFields.size() == 0)
		return "";

	std::stringstream ssSQL;
	ssSQL << " ORDER BY ";
	std::vector<OrderByColumn>::const_iterator iterFields = orderByFields.begin();
	for(int i = 0;iterFields != orderByFields.end(); i++,++iterFields) {

		std::string op;
		switch(iterFields->dir)
		{
		case ASCENDING:
			op = " ASC ";
			break;
		case DESCENDING:
			op = " DESC ";
			break;
		default:
			THROW_EXCEPTION(DatabaseInvalidOperatorTypeException);
			break;
		}
		if(i)
			ssSQL << " , ";

		//TODO: use aliases if neccessary
		ssSQL << " " << iterFields->colDef->GetColumnName() << op;
	}
	return ssSQL.str();
}

}
