/**
 *
 * @file QueryKeyword.h
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#pragma once

#include <string>

#include "KeywordMatchType.h"

namespace queryserver {

/**
 * @brief encapsulates a single keyword in a Query
 */
class QueryKeyword {

public:

public:
	QueryKeyword(const long long& position,const long long& groupID,const std::string& keyword,const bool& caseSensitive,const bool& occuranceMandatory,const bool& exactMatch);
	virtual ~QueryKeyword();

public:
	/**
	 * gets position of this keyword in the query string
	 * @return position of this keyword
	 */
	const size_t GetPosition(void) const { return position; }

	/**
	 * gets group id (-1 if not in grouped keyword)
	 * @return position of this keyword
	 */
	const long long GetGroupID(void) const { return groupID; }

	/**
	 * gets the keyword
	 * @return keyword
	 */
	const std::string& GetKeyword(void) const { return keyword; }

	/**
	 * true if occurance of the keyword in result is mandatory
	 * @return true if occurance is mandatory
	 */
	bool IsOccuranceMandatory(void) const { return occuranceMandatory; }

	/**
	 * gets match type for keyword
	 * @return true if needs to match exactly
	 */
	const KeywordMatchType& GetMatchType(void) const { return type; }

	/**
	 * dump keyword into human readable string
	 * @param dump string to dump to
	 */
	void Dump(std::string& dump) const;

private:
	static std::string KeywordMatchTypeToString(const KeywordMatchType& type);

private:
	long long position;
	long long groupID;

	std::string keyword;

	KeywordMatchType type;
	bool occuranceMandatory;
};

}

