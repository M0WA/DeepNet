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
: pageNo(0)
{
}

Query::~Query() {
}

void Query::AppendKeyword(const long long& position,const std::string& keyword,const bool caseSensitive) {

	queryKeywords.insert(queryKeywords.end(),QueryKeyword(position,keyword,caseSensitive));
}

void Query::GetKeywords(std::vector<std::string>& keywordsOut) const {
	std::vector<QueryKeyword>::const_iterator i(queryKeywords.begin());
	for(;i!=queryKeywords.end();++i) {
		keywordsOut.push_back(i->GetKeyword());	}
}

void Query::GetLoweredKeywords(std::vector<std::string>& keywordsOut) const {
	std::vector<QueryKeyword>::const_iterator i(queryKeywords.begin());
	for(;i!=queryKeywords.end();++i) {
		keywordsOut.push_back(i->GetLoweredKeyword());	}
}

}
