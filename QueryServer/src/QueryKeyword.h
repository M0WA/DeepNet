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

class QueryKeyword {
public:
	QueryKeyword(const long long& position,const std::string& keyword,const bool caseSensitive);
	virtual ~QueryKeyword();

	operator const std::string& () const {
		return GetKeyword(); }

public:
	const size_t GetPosition() const { return position; }
	const std::string& GetKeyword() const { return keyword; }
	bool IsCaseSensitive() const { return caseSensitive; }

private:
	const long long position;
	const std::string keyword;
	const bool caseSensitive;
};

}

