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

class QueryCriteria {

	friend class QueryFactory;

public:
	typedef enum {
		CRITERIA_UNKNOWN = 0,

		CRITERIA_ALL     = 1,

		CRITERIA_META    = 2,
		CRITERIA_DOMAIN  = 4,
		CRITERIA_CONTENT = 16,
		CRITERIA_PATH    = 32,
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

