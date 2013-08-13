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

namespace queryserver {

/**
 * @brief encapsulates query keywords and their properties
 */
class Query {
public:
	Query();
	Query(const std::vector<std::string>& keywords);
	virtual ~Query();

	/**
	 * query's keywords
	 */
	std::vector<std::string> keywords;

	/**
	 * query's properties
	 */
	QueryProperties properties;
};

}

