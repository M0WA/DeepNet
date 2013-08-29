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

/**
 * @brief encapsulates query keywords and their properties
 */
class Query {
public:
	Query();
	virtual ~Query();

public:
	/**
	 * appends a keyword at a given position
	 * @param position position of keyword to append
	 * @param keyword keyword to append
	 * @param caseSensitive true if keyword is case sensitive
	 */
	void AppendKeyword(const long long& position,const std::string& keyword,const bool caseSensitive);

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

public:
	/**
	 * query's properties
	 */
	QueryProperties properties;

	/**
	 * page number for this request
	 */
	size_t pageNo;

private:
	/**
	 * query's keywords
	 */
	std::vector<QueryKeyword> queryKeywords;
};

}

