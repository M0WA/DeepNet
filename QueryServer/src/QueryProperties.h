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

#include "QueryCriteria.h"
#include "QueryLimitations.h"

namespace queryserver {

enum QueryGroupingFlag
{
	GROUPING_UNKNOWN = 0,
	GROUPING_DOMAIN  = 1,

	GROUPING_MAX     = 0xFF,
};


class QueryFactory;

/**
 * @brief encapsulates all properties of a query
 * @see queryserver::Query
 */
class QueryProperties {

	friend class QueryFactory;

public:
	QueryProperties();
	virtual ~QueryProperties();

public:
	/**
	 * checks if result should be groupped by secondlevel domain
	 * @return true if set, false if unset
	 */
	const bool& GetGroupBySecondLevelDomain(void) const { return groupBySecondLevelDomain; }


    /**
     * hardlimit for the number of search results
     * @return max number of search results
     */
    const size_t& GetMaxResults(void) const { return maxResults; }

    /**
     * gets requested page number
     * @return requested page number
     */
    const size_t& GetPageNo(void) const { return pageNo; }

    /**
     * gets id of this query
     * @return query id
     */
    const long long& GetQueryId(void) const { return queryId; }

    /**
     * gets all criterias for this query
     * @return all criterias for this query
     */
    const QueryCriteria& GetCriteria(void) const { return criteria; }

    /**
     * gets all limitations for this query
     * @return all limitations for this query
     */
    const QueryLimitations& GetLimitations(void) const { return limitations; }

private:
	/**
	 * query id
	 */
	long long queryId;

	/**
	 * group by secondlevel domain
	 */
	bool groupBySecondLevelDomain;

	/**
	 * maximum number of results (0 to set to maximum)
	 */
	size_t maxResults;

	/**
	 * page number for this request
	 */
	size_t pageNo;

	/**
	 * query criteria
	 */
	QueryCriteria criteria;

	/**
	 * query limitations
	 */
	QueryLimitations limitations;
};

}

