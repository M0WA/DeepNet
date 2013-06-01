/**
 * @file PCRERegexGroup.h
 * @author Moritz Wagner
 * @date 15.11.2012
 */

#pragma once

#include <string>

namespace tools {

/**
 * @brief container for a group of a tools::PCRERegex
 */
class PCRERegexGroup {
public:
	PCRERegexGroup();
	virtual ~PCRERegexGroup();

	/**
	 * begin of group in target.
	 */
	int begin;

	/**
	 * end of group in target.
	 */
	int end;

	/**
	 * group value.
	 */
	std::string groupValue;
};

}

