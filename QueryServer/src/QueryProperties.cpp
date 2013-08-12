/**
 *
 * @file QueryProperties.cpp
 * @author Moritz Wagner
 * @date Aug 12, 2013
 *
 */

#include "QueryProperties.h"

#include <TimeTools.h>

namespace queryserver {

QueryProperties::QueryProperties()
: queryContent(true)
, queryMeta(true)
, querySecondLevelDomain(true)
, querySubdomain(true)
, queryUrlPath(true)
, caseSensitive(false)
, limitSecondLevelDomainID(-1)
, limitSubDomainID(-1) {
	tools::TimeTools::InitTm(minAge);
	tools::TimeTools::NowUTCAdd(maxAge,10);
}

QueryProperties::~QueryProperties() {
}

}
