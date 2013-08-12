/**
 *
 * @file QueryProperties.h
 * @author Moritz Wagner
 * @date Aug 12, 2013
 *
 */

#pragma once

#include <ctime>

namespace queryserver {

class QueryProperties {
public:
	QueryProperties();
	virtual ~QueryProperties();

	bool queryContent;
	bool queryMeta;
	bool querySecondLevelDomain;
	bool querySubdomain;
	bool queryUrlPath;

	bool caseSensitive;
	struct tm minAge;
	struct tm maxAge;

	long long limitSecondLevelDomainID;
	long long limitSubDomainID;
};

}

