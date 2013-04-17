/*
 * PageInfo.h
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <list>

namespace queryserver {

class PageInfo
{
public:
	const std::string& Description() const { return description; }
	const std::string& Title()       const { return title;       }

public:
	std::string description;
	std::string title;
};

}
