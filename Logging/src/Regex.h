/**
 *
 * @file Regex.h
 * @author Moritz Wagner
 * @date 09.09.2012
 *
 */

#pragma once

#include <string>
#include <vector>
#include <regex.h>

namespace tools {

/**
 * @brief wrapper class for (extended) posix compatible regular expressions.
 */
class Regex {
public:
	/**
	 * constructs a regular expression with a precompiled regex.
	 * @param regexExp the regex.
	 * @param caseInsensitive true if regex is case insensitive.
	 */
	Regex(const std::string& regexExp,const bool caseInsensitive = false);
	virtual ~Regex();

public:
	/**
	 * matches a target string against a precompiled regex.
	 * @param target target string.
	 * @param groups result groups.
	 * @return true if match, false if not match.
	 */
	bool Match(const std::string& target, std::vector<std::string>& groups);

public:
	/**
	 * matches a target string against a regex.
	 * @param regexExp the regex.
	 * @param target target string.
	 * @param groups result groups.
	 * @param caseInsensitive true if regex is case insensitive.
	 * @return true if match, false if not match.
	 */
	static bool Match(const std::string& regexExp, const std::string& target, std::vector<std::string>& groups, const bool caseInsensitive = false );

private:
	static bool Match(const regex_t& regex, const std::string& target, std::vector<std::string>& groups );
	static bool Compile(const std::string& regexExp, const bool caseInsensitive, regex_t& regex );
	static void FreeRegex(regex_t& regex);

private:
	regex_t regex;
	bool isInitialized;
};

}

