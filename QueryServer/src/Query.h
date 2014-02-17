/**
 *
 * @file Query.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <vector>
#include <string>

#include "QueryProperties.h"
#include "QueryKeywordGroup.h"

namespace queryserver {

class QueryFactory;

/**
 * @brief encapsulates query keywords and their properties
 * please have a look at queryserver::QueryFactory to construct
 * instances of this class
 */
class Query {

	friend class QueryFactory;

private:
	Query();
public:
	virtual ~Query();

public:
	/**
	 * gets query's properties
	 * @return query's properties
	 */
	const queryserver::QueryProperties& GetQueryProperties(void) const { return properties; }

	/**
	 * gets list of all keyword groups of this query
	 * @return list of all keyword groups
	 */
	const std::vector<queryserver::QueryKeywordGroup>& GetKeywordGroups(void) const { return keywordGroups; }

	/**
	 * gets the current raw query string
	 * @return
	 */
	const std::string& GetRawQueryString(void) const { return query; }

private:
	/**
	 * adds a keyword group to this query
	 * used only during initialization phase
	 * @param grp keyword group to add
	 */
	void AddQueryGroup(queryserver::QueryKeywordGroup& grp);

private:
	/**
	 * query's properties
	 */
	queryserver::QueryProperties properties;

	/**
	 * query's keywords
	 */
	std::vector<queryserver::QueryKeywordGroup> keywordGroups;

	/**
	 * raw query string
	 */
	std::string query;
};

}

