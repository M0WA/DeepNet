/**
 *
 * @file QueryProperties.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <ctime>
#include <string>

namespace queryserver {

/**
 * @brief encapsulates all properties of a query
 * @see queryserver::Query
 */
class QueryProperties {
public:
	QueryProperties();
	virtual ~QueryProperties();

public:
	/**
	 * dump queryproperties into human readable string
	 * @param dump string to dump to
	 */
	void Dump(std::string& dump) const;

	/**
	 * return hard limit for results per query
	 */
	size_t GetMaxResultHardLimit(void) const;

public:
	/**
	 * query id
	 */
	long long queryId;

	/**
	 * min age of webpage
	 */
	struct tm minAge;

	/**
	 * max age of webpage
	 */
	struct tm maxAge;

	/**
	 * limit search to a certain secondlevel domain id (-1 to disable)
	 */
	long long limitSecondLevelDomainID;

	/**
	 * limit search to a certain subdomain id (-1 to disable)
	 */
	long long limitSubDomainID;

	/**
	 * relevance factor for content matches (0.0 to disable)
	 */
	double relevanceContent;

	/**
	 * relevance factor for meta content matches (0.0 to disable)
	 */
	double relevanceMeta;

	/**
	 * relevance factor for subdomain matches (0.0 to disable)
	 */
	double relevanceSubdomain;

	/**
	 * relevance factor for secondlevel domain matches (0.0 to disable)
	 */
	double relevanceSecondLevelDomain;

	/**
	 * relevance factor for matches in path part of the url (0.0 to disable)
	 */
	double relevanceUrlPath;

	/**
	 * group by secondlevel domain
	 */
	bool groupBySecondLevelDomain;

	/**
	 * maximum number of results (0 to set to maximum)
	 */
	size_t maxResults;

	/**
	 * maximum number of results in totoal (0 to set to maximum)
	 */
	size_t maxTotalResults;

	/**
	 * webpage language (empty to allow all)
	 */
	std::string language;

	/**
	 * page number for this request
	 */
	size_t pageNo;
};

}

