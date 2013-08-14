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
