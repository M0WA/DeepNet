/**
 *
 * @file QueryProperties.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryProperties.h"

#include <TimeTools.h>

#include <sstream>
#include <string>

#define RESULTS_PER_REQUEST_HARDLIMIT 10000

namespace queryserver {

QueryProperties::QueryProperties()
: queryId(-1)
, limitSecondLevelDomainID(-1)
, limitSubDomainID(-1)
, relevanceContent(0.0)
, relevanceMeta(0.0)
, relevanceSubdomain(0.0)
, relevanceSecondLevelDomain(0.0)
, relevanceUrlPath(0.0)
, groupBySecondLevelDomain(false)
, maxResults(25)
, maxTotalResults(0)
, pageNo(0){

	//TODO: do not hardcode this limit,move to config file
	if(maxTotalResults <= 0 || maxTotalResults > GetMaxResultHardLimit()) {
		maxTotalResults = GetMaxResultHardLimit(); }

	if(maxResults <= 0 || maxResults > maxTotalResults) {
		maxResults = maxTotalResults; }

	tools::TimeTools::InitTm(minAge);
	tools::TimeTools::InitTm(maxAge);
}

QueryProperties::~QueryProperties() {
}

size_t QueryProperties::GetMaxResultHardLimit(void) const {
	return RESULTS_PER_REQUEST_HARDLIMIT;
}

void QueryProperties::Dump(std::string& dump) const {
	std::ostringstream ss;

	ss <<
    "----------------------------------------------" << std::endl <<
    "| query properties"                             << std::endl <<
    "----------------------------------------------" << std::endl <<
	"queryId                    : " << queryId << std::endl <<
	"limitSecondLevelDomainID   : " << limitSecondLevelDomainID << std::endl <<
	"limitSubDomainID           : " << limitSubDomainID << std::endl <<
	"relevanceContent           : " << relevanceContent << std::endl <<
	"relevanceMeta              : " << relevanceMeta << std::endl <<
	"relevanceSubdomain         : " << relevanceSubdomain << std::endl <<
	"relevanceSecondLevelDomain : " << relevanceSecondLevelDomain << std::endl <<
	"relevanceUrlPath           : " << relevanceUrlPath << std::endl <<
	"groupBySecondLevelDomain   : " << groupBySecondLevelDomain << std::endl <<
	"maxResults                 : " << maxResults << std::endl <<
	"pageNo                     : " << pageNo << std::endl;

	dump = ss.str();
}

}
