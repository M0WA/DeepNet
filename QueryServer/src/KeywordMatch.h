/*
 * KeywordMatch.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Moritz Wagner
 */

#pragma once

#include "KeywordMatchType.h"

#include <map>
#include <vector>

namespace queryserver {

class QueryKeyword;

/**
 * @brief contains information about a match of a keyword from query string
 */
class KeywordMatch {
public:
	/**
	 * @brief contains dictionary ids by match-type
	 */
	typedef std::map<KeywordMatchType, std::vector<long long> > KeywordMatchEntry;

public:
	KeywordMatch(const QueryKeyword* keyword);
	virtual ~KeywordMatch();

public:
	/**
	 * returns all available dictionary ids of this keyword
	 * @param dictIDs container for dictionary ids
	 */
	void GetAllDictIDs(std::vector<long long>& dictIDs) const;

public:
	/**
	 * query keyword for this match
	 */
	const QueryKeyword* keyword;

	/**
	 * contains dictionary ids by match-type
	 */
	KeywordMatchEntry entry;
};

}
