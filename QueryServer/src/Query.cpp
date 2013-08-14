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

void Query::AppendKeyword(const long long& position,const std::string& keyword,const bool caseSensitive) {

	queryKeywords.insert(queryKeywords.end(),QueryKeyword(position,keyword,caseSensitive));
	keywords.insert(keywords.end(),keyword);

	if(caseSensitive) {
		lowerKeywords.insert(lowerKeywords.end(),tools::StringTools::ToLowerNP(keyword)); }
}

size_t Query::GetPositionByKeyword(const std::string& keyword) const {

	std::vector<std::string>::const_iterator i(keywords.begin());
	for(size_t pos(0);i!=keywords.end();++i,++pos){
		if(i->compare(keyword) == 0) {
			return pos; }
	}

	i=lowerKeywords.begin();
	for(size_t pos(0);i!=lowerKeywords.end();++i,++pos){
		if(i->compare(keyword) == 0) {
			return pos; }
	}

	//
	//TODO: throw exception
	//
	return 0;
}

}
