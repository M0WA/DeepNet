/**
 *
 * @file QueryKeyword.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryKeyword.h"

#include <StringTools.h>
#include <ContainerTools.h>

#include <sstream>

namespace queryserver {

QueryKeyword::QueryKeyword(const long long& position,const long long& groupID,const std::string& keyword,const bool& caseSensitive,const bool& occuranceMandatory,const bool& exactMatch)
: position(position)
, groupID(groupID)
, keyword(keyword)
, type(SIMILAR_MATCH)
, occuranceMandatory(occuranceMandatory){

	if(caseSensitive) {
		type = CASEINSENSITIVE_MATCH;
	}
	if(exactMatch) {
		type = EXACT_MATCH;
	}
}

QueryKeyword::~QueryKeyword() {
}

std::string QueryKeyword::KeywordMatchTypeToString(const KeywordMatchType& type) {

	std::string out;

	switch(type) {
	case EXACT_MATCH:
		out = "EXACT_MATCH";
		break;
	case CASEINSENSITIVE_MATCH:
		out = "CASEINSENSITIVE_MATCH";
		break;
	case SIMILAR_MATCH:
		out = "SIMILAR_MATCH";
		break;
	default:
		out = "INVALID";
		break;
	}

	return out;
}

void QueryKeyword::Dump(std::string& dump) const {
	std::ostringstream ss;

	ss <<
    "----------------------------------------------" << std::endl <<
	"keyword            : " << keyword << std::endl <<
	"position           : " << position << std::endl <<
	"groupID            : " << groupID << std::endl <<
	"type               : " << KeywordMatchTypeToString(type) << std::endl <<
	"occuranceMandatory : " << occuranceMandatory << std::endl <<
    "----------------------------------------------" << std::endl;

	dump = ss.str();
}

}
