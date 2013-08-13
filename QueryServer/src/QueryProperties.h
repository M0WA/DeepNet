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

	bool caseSensitive;

	struct tm minAge;
	struct tm maxAge;

	long long limitSecondLevelDomainID;
	long long limitSubDomainID;

	double relevanceContent;
	double relevanceMeta;
	double relevanceSubdomain;
	double relevanceSecondLevelDomain;
	double relevanceUrlPath;
};

}

