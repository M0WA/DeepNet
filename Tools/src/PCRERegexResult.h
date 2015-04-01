/**
 * @file PCRERegexResult.h
 * @author Moritz Wagner
 * @date 15.11.2012
 */

#pragma once

#include <vector>
#include "PCRERegexGroup.h"

namespace tools {

/**
 * @brief container for a result of a pcre regex.
 * @see tools::PCRERegex
 */
class PCRERegexResult {
public:
	PCRERegexResult();
	virtual ~PCRERegexResult();

	/**
	 * dumps result to string.
	 * @param pszTarget target.
	 * @return dumped result.
	 */
	std::string Dump(const char* pszTarget) const;

	/**
	 * start position in target.
	 */
	int begin;

	/**
	 * end position in target.
	 */
	int end;

	/**
	 * successful regex.
	 */
	bool success;

	/**
	 * regex groups.
	 */
	std::vector<PCRERegexGroup> groups;
};

}

