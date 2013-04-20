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

class Regex {
public:
	Regex(const std::string& regexExp,const bool caseInsensitive = false);
	virtual ~Regex();

public:
	bool Match(const std::string& target, std::vector<std::string>& groups);

public:
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

