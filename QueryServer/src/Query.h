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
	size_t GetPositionByKeyword(const std::string& keyword) const;

public:
	/**
	 * query's keywords
	 */
	std::vector<QueryKeyword> queryKeywords;

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
};

}

