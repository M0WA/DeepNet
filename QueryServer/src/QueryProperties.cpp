/**
 *
 * @file QueryProperties.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryProperties.h"

#include <TimeTools.h>

namespace queryserver {

QueryProperties::QueryProperties()
: caseSensitive(false)
, limitSecondLevelDomainID(-1)
, limitSubDomainID(-1)
, relevanceContent(0.0)
, relevanceMeta(0.0)
, relevanceSubdomain(0.0)
, relevanceSecondLevelDomain(0.0)
, relevanceUrlPath(0.0)
, maxResults(0){
	tools::TimeTools::InitTm(minAge);
	tools::TimeTools::NowUTCAdd(maxAge,10);
}

QueryProperties::~QueryProperties() {
}

}
