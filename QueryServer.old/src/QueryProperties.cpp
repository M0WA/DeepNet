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
: queryId(-1)
, groupBySecondLevelDomain(false)
, maxResults(25)
, pageNo(0){
}

QueryProperties::~QueryProperties() {
}

}
