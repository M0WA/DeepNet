/**
 *
 * @file Query.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "Query.h"

#include <StringTools.h>

namespace queryserver {

Query::Query()
{
}

Query::~Query() {
}

void Query::AddQueryGroup(queryserver::QueryKeywordGroup& grp) {
	keywordGroups.push_back(grp);
}

bool Query::Init(database::DatabaseConnection *db) {
	std::vector<QueryKeywordGroup>::iterator i(keywordGroups.begin());
	for(; i != keywordGroups.end(); ++i) {
		i->Init(db); }
}

}
