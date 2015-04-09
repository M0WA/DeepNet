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
#include "QueryKeyword.h"

namespace queryserver {
	class QueryXmlRequest;
}

namespace querylib {

/**
 * @brief encapsulates query keywords and their properties
 */
class Query {
	friend class queryserver::QueryXmlRequest;

public:
	Query();
	virtual ~Query();

public:
	/**
	 * gets all keywords
	 * @param keywords vector of keywords to fill
	 */
	void GetKeywords(std::vector<std::string>& keywords) const;

	/**
	 * gets all keywords in lowered form
	 * @param keywords vector of keywords to fill
	 */
	void GetLoweredKeywords(std::vector<std::string>& keywords) const;

	/**
	 * gets queries properties
	 * @return QueryProperties
	 */
	const QueryProperties& GetQueryProperties() const;

	/**
	 * gets a unique identifier for query to be able
	 * to compare two queries
	 * @return query identifier
	 */
	const std::string& GetQueryIdentifier() const;

private:
	/**
	 * appends a keyword at a given position
	 * @param position position of keyword to append
	 * @param keyword keyword to append
	 * @param caseSensitive true if keyword is case sensitive
	 */
	void AppendKeyword(const long long& position,const std::string& keyword,const bool caseSensitive);

	/**
	 * recalculates identifier
	 */
	void RecalculateIdentifier();

private:
	/**
	 * query's properties
	 */
	QueryProperties properties;

	/**
	 * query's keywords
	 */
	std::vector<QueryKeyword> queryKeywords;

	/**
	 * an identifier to be able to detect similiar queries
	 */
	std::string queryIdentifier;
};

}

