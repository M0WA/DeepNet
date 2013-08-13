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

class Query {
public:
	Query();
	virtual ~Query();

	std::vector<std::string> keywords;
	QueryProperties properties;
};

}

