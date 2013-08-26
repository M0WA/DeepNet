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
	 * gets position of a certain keyword in a query
	 * @param keyword keyword to get position for
	 * @return keyword position
	 */
	size_t GetPositionByKeyword(const std::string& keyword) const;

	/**
	 * appends a keyword at a given position
	 * @param position position of keyword to append
	 * @param keyword keyword to append
	 * @param caseSensitive true if keyword is case sensitive
	 */
	void AppendKeyword(const long long& position,const std::string& keyword,const bool caseSensitive);

public:
	/**
	 * raw keyword strings
	 */
	std::vector<std::string> keywords;

	/**
	 * lowered keyword strings
	 */
	std::vector<std::string> lowerKeywords;

	/**
	 * query's properties
	 */
	QueryProperties properties;

	/**
	 * query id
	 */
	long long queryId;

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

