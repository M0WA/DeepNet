/*
 * QueryServerConfig.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: momo
 */

#include "QueryServerConfig.h"

namespace queryserver {

QueryServerConfig::QueryServerConfig()
: hardlimit_meta(0)
, hardlimit_secondleveldomain(0)
, hardlimit_urlpathpart(0) {
}

QueryServerConfig::~QueryServerConfig() {
}

const unsigned long long& QueryServerConfig::GetHardLimitMeta() const {
	return hardlimit_meta;
}

const unsigned long long& QueryServerConfig::GetHardLimitSecondLevelDomain() const {
	return hardlimit_secondleveldomain;
}

const unsigned long long& QueryServerConfig::GetHardLimitUrlPathPart() const {
	return hardlimit_urlpathpart;
}

}
