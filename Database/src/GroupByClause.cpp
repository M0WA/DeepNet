/**
 * @file GroupByClause.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "GroupByClause.h"

#include <sstream>

namespace database {

GroupByClause::GroupByClause() {
}

GroupByClause::~GroupByClause() {
}

bool GroupByClause::AddGroupByFieldname(const std::string& fullTableName, const std::string& field)
{
	GROUPBY_CLAUSE clause;
	clause.first  = fullTableName;
	clause.second = field;
	groupByFields.push_back(clause);
	return true;
}

std::string GroupByClause::ToString(database::DatabaseConnection* db) const {

	if(groupByFields.size() == 0)
		return "";

	std::stringstream ssGroupBy;
	std::vector< GROUPBY_CLAUSE >::const_iterator iterFields = groupByFields.begin();
	for(int i = 0;iterFields != groupByFields.end();++iterFields,i++){
		if(i)
			ssGroupBy << ",";
		if(!iterFields->first.empty())
			ssGroupBy << iterFields->first << ".";
		ssGroupBy << iterFields->second;
	}

	std::string groupByClauseString = ssGroupBy.str();
	if(groupByClauseString.length() > 0) {
		groupByClauseString = " GROUP BY " + groupByClauseString;
	}
	return groupByClauseString;
}

}
