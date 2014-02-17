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

}
