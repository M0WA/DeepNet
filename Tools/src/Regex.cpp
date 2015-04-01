/**
 *
 * @file Regex.cpp
 * @author Moritz Wagner
 * @date 09.09.2012
 *
 */

#include "Regex.h"

#include <cstring>
#include "Logging.h"

namespace tools {

Regex::Regex(const std::string& regexExp, const bool caseInsensitive ) {

	isInitialized = Compile(regexExp, caseInsensitive, regex);
}

Regex::~Regex() {

	if(isInitialized) {
		FreeRegex(regex);}

}

bool Regex::Compile(const std::string& regexExp, const bool caseInsensitive, regex_t& regex ) {

	int flags = REG_EXTENDED;
	if(caseInsensitive)
		flags |= REG_ICASE;
	int regError = regcomp(&regex, regexExp.c_str(), flags);
	if( regError ) {
		char errorBuf[512];
		regerror(regError,&regex,errorBuf,512);
		log::Logging::LogError("invalid regular expression: %s\n%s", regexExp.c_str(),regError);
		return false;
	}
	return true;
}

bool Regex::Match(const regex_t& regex, const std::string& target, std::vector<std::string>& groups ) {

	size_t ngroups = regex.re_nsub + 1;
	regmatch_t* matches = new regmatch_t[ngroups+1];
	size_t startPos = 0;
	const char* pszTarget = target.c_str();
	bool finished = false;
	bool error = false;
	while(!finished) {

		if(startPos > target.length()){
			error = true;
			break; }

		memset(matches, -1, sizeof(regmatch_t) * (ngroups+1));
		int reti = regexec(&regex, &pszTarget[startPos], ngroups, matches, 0);
		if(!reti){
			size_t lastEntry = 0;
			for (size_t nmatched = 1; nmatched < ngroups; nmatched++) {

				if (matches[nmatched].rm_so == -1 || matches[nmatched].rm_eo == -1) {
					finished = true;
					break;
				}
				else {
					size_t groupBegin = (size_t)matches[nmatched].rm_so;
					size_t groupEnd   = (size_t)matches[nmatched].rm_eo;
					size_t groupLen   = groupEnd - groupBegin;

					std::string group = target.substr(startPos + groupBegin, groupLen);
					if(lastEntry<groupEnd)
						lastEntry = groupEnd;

					groups.push_back(group);

					if(startPos >= target.length()){
						finished = true;
						break;	}
				}
			}
			startPos += lastEntry+1;
		}
		else {
			finished = true;
			break;
		}
	}
	delete [] matches;
	return !error;
}

bool Regex::Match(const std::string& regexExp, const std::string& target, std::vector<std::string>& groups, const bool caseInsensitive )
{
	regex_t regex;
	if(!Compile(regexExp,caseInsensitive,regex))
		return false;

	bool success = Match(regex,target,groups);
	FreeRegex(regex);

	return success;
}

void Regex::FreeRegex(regex_t& regex) {

	regfree(&regex);
}

bool Regex::Match(const std::string& target, std::vector<std::string>& groups) {

	if(!isInitialized)
		return false;

	return Regex::Match(regex,target,groups);
}

}
