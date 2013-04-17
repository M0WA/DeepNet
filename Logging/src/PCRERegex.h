/**
 * @file PCRERegex.h
 * @author Moritz Wagner
 * @date 09.09.2012
 */

#pragma once

#include <string>
#include <vector>
#include <pcre.h>

#include "Exception.h"
#include "NotImplementedException.h"

#include "PCRERegexResult.h"

namespace tools {

/**
 * @brief wrapper class for perl compatible regexes.
 */
class PCRERegex {
public:
	/**
	 * construct a regular expression.
	 * @param regexExp expression string.
	 * @param caseInsensitive true if expression is case insensitive.
	 * @param multiLine true if expression is multiline.
	 * @param utf8Mode true if expression is for UTF8.
	 */
	PCRERegex(
			const std::string& regexExp,
			const bool caseInsensitive = false,
			const bool multiLine       = false,
			const bool utf8Mode        = false);

	virtual ~PCRERegex();

private:
	PCRERegex(const PCRERegex&) {
		THROW_EXCEPTION(errors::NotImplementedException,"cannot copy PCRERegex");
    }

	PCRERegex& operator= (const PCRERegex&) {
		THROW_EXCEPTION(errors::NotImplementedException,"cannot assign PCRERegex");
		return *this;
	}

public:
	/**
	 * check if regex matches a string.
	 * @param target string to check.
	 * @return false if not a match, true if match.
	 */
	bool Match(const std::string& target);

	/**
	 * check if regex matches a string.
	 * @param target string to check.
	 * @param groups result groups.
	 * @return false if not a match, true if match.
	 */
	bool Match(
			const std::string& target,
			std::vector<std::string>& groups);

	/**
	 * check if regex matches a string returning detailed information.
	 * @param target string to check.
	 * @param offSet offset for regex.
	 * @param nMaxMatches maximum number of matches.
	 * @return result
	 */
	PCRERegexResult MatchEx(
			const char* target,
			const int offSet,
			const int nMaxMatches);

public:
	/**
	 * check if regex matches a string.
	 * @param regexExp expression string.
	 * @param target string to check.
	 * @param groups gets filled groups.
	 * @param caseInsensitive true if expression is case insensitive.
	 * @param multiLine true if expression is multiline.
	 * @param utf8Mode true if expression is for UTF8.
	 */
	static bool Match(
			const std::string& regexExp,
			const std::string& target,
			std::vector<std::string>& groups,
			const bool caseInsensitive = false,
			const bool multiLine = false,
			const bool utf8Mode = false );

private:
	static bool Compile(
			const std::string& regexExp,
			const bool caseInsensitive,
			const bool multiLine,
			const bool utf8Mode,
			pcre** regex,
			pcre_extra** extraData,
			int** subStringPos,
			int* subStringCount);

	static void FreeRegex(
			pcre** regex,
			pcre_extra** extra_data,
			int** subStringPos);

	static bool Match(
			const pcre* regex,
			const pcre_extra* extra_data,
			const int subStringCount,
			int* subStringPos,
			const std::string& target,
			std::vector<std::string>& groups);

	static PCRERegexResult MatchEx(
			const pcre* regex,
			const pcre_extra* extra_data,
			const int subStringCount,
			int* subStringPos,
			const char* target,
			const int offSet,
			const int nMaxMatches);

private:
	pcre* regex;
	pcre_extra* extra_data;
	int subStringCount;
	int* subStringPos;
};

}

