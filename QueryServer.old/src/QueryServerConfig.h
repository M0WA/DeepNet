/*
 * QueryServerConfig.h
 *
 *  Created on: Sep 14, 2014
 *      Author: momo
 */

#pragma once

namespace queryserver {

class QueryServer;

/**
 * @brief represents settings for QueryServer
 */
class QueryServerConfig {

	friend class QueryServer;

public:
	QueryServerConfig();
	virtual ~QueryServerConfig();

public:
	/**
	 * gets hard limit for meta results
	 * @return hard limit for meta results.
	 */
	const unsigned long long& GetHardLimitMeta() const;

	/**
	 * gets hard limit for secondlevel domain results
	 * @return hard limit for secondlevel domain results.
	 */
	const unsigned long long& GetHardLimitSecondLevelDomain() const;

	/**
	 * gets hard limit for url path results
	 * @return hard limit for url path results.
	 */
	const unsigned long long& GetHardLimitUrlPathPart() const;

private:
	unsigned long long hardlimit_meta;
	unsigned long long hardlimit_secondleveldomain;
	unsigned long long hardlimit_urlpathpart;
};

}
