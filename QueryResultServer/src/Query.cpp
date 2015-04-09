/**
 *
 * @file Query.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "Query.h"

#include <sstream>

#include <TimeTools.h>
#include <StringTools.h>
#include <HashTools.h>

namespace queryserver {

Query::Query()
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

const QueryProperties& Query::GetQueryProperties() const {
	return properties;
}

const std::string& Query::GetQueryIdentifier() const {
	return queryIdentifier;
}

void Query::RecalculateIdentifier() {

	std::stringstream uniqueIdentifier;
	std::vector<QueryKeyword>::const_iterator i(queryKeywords.begin());
	for(;i!=queryKeywords.end();++i) {
		uniqueIdentifier << i->GetKeyword() << i->GetPosition() << i->IsCaseSensitive(); }

	uniqueIdentifier <<
		tools::TimeTools::DumpTm(properties.minAge) <<
		tools::TimeTools::DumpTm(properties.maxAge) <<
		properties.limitSecondLevelDomainID <<
		properties.limitSubDomainID <<
		properties.relevanceContent <<
		properties.relevanceMeta <<
		properties.relevanceSubdomain <<
		properties.relevanceSecondLevelDomain <<
		properties.relevanceUrlPath <<
		properties.groupBySecondLevelDomain <<
		properties.maxResults <<
		properties.language;

	queryIdentifier = tools::HashTools::GetMD5(uniqueIdentifier.str());
}

}
