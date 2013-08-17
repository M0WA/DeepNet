/**
 *
 * @file QueryKeyword.h
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#pragma once

#include <string>

namespace queryserver {

/**
 * @brief encapsulates a single keyword in a Query
 */
class QueryKeyword {
public:
	QueryKeyword() : position(-1), keyword(""), caseSensitive(false) {}
	QueryKeyword(const long long& position,const std::string& keyword,const bool caseSensitive);
	virtual ~QueryKeyword();

public:
	/**
	 * gets position of this keyword in the query string
	 * @return position of this keyword
	 */
	const size_t GetPosition() const { return position; }

	/**
	 * gets the keyword
	 * @return keyword
	 */
	const std::string& GetKeyword() const { return keyword; }

	/**
	 * true if keyword is case sensitive
	 * @return true if case sensitive
	 */
	bool IsCaseSensitive() const { return caseSensitive; }

private:
	long long position;
	std::string keyword;
	bool caseSensitive;
};

}
