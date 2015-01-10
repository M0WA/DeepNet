/**
 *
 * @file QueryCriteria.h
 * @author Moritz Wagner
 * @date 23.02.2014
 *
 */

#pragma once

#include "Relevance.h"

#include <map>

namespace queryserver {

class QueryFactory;

/**
 * @brief encapsulates all criterias for a query
 * @see queryserver::Query queryserver::QueryProperties
 */
class QueryCriteria {

	friend class QueryFactory;

public:
	typedef enum {
		CRITERIA_UNKNOWN = 0,

		/**
		 * special case, enable all criterias
		 */
		CRITERIA_ALL     = 1,

		/**
		 * meta information criteria
		 */
		CRITERIA_META    = 2,

		/**
		 * domain based criteria
		 */
		CRITERIA_DOMAIN  = 4,

		/**
		 * content based criteria
		 */
		CRITERIA_CONTENT = 16,

		/**
		 * url path based criteria
		 */
		CRITERIA_PATH    = 32,

		/**
		 * backlink based criteria
		 */
		CRITERIA_LINKS   = 64,

		CRITERIA_MAX     = 0xFF,
	} QueryCriteriaFlag;

public:
	QueryCriteria();
	virtual ~QueryCriteria();

public:
	/**
	 * gets relevance by criteria type
	 * @return relevance of criteria type
	 */
	const Relevance& GetRelevanceByCriteria(const QueryCriteria::QueryCriteriaFlag& type) const;

	/**
	 * returns all enabled flags
	 * @return enabled flags
	 */
	QueryCriteria::QueryCriteriaFlag GetEnabledFlags(void) const;

	/**
	 * checks if certain criteria type is enabled
	 * @param type criteria type to check
	 * @return true if enabled, false if disabled
	 */
	bool IsCriteriaEnabled(const QueryCriteria::QueryCriteriaFlag& type) const;

private:
	std::map<QueryCriteriaFlag,Relevance> relevance;
};

}

