/**
 * @file PCRERegex.cpp
 * @author Moritz Wagner
 * @date 09.09.2012
 */

#include "PCRERegex.h"

#include <cstdio>
#include <cstring>

#include "Logging.h"

namespace tools {

PCRERegex::PCRERegex(
		const std::string& regexExp,
		const bool caseInsensitive,
		const bool multiLine,
		const bool utf8Mode)
: regex(0)
, extra_data(0)
, subStringCount(-1)
, subStringPos(0){

	Compile(regexExp, caseInsensitive, multiLine, utf8Mode, &regex, &extra_data, &subStringPos, &subStringCount );
}

PCRERegex::~PCRERegex() {

	FreeRegex(&regex, &extra_data, &subStringPos);
}

bool PCRERegex::Compile(
		const std::string& regexExp,
		const bool caseInsensitive,
		const bool multiLine,
		const bool utf8Mode,
		pcre** regex,
		pcre_extra** extra_data,
		int** subStringPos,
		int* subStringCount) {

	int options = 0;
	if(caseInsensitive)
		options |= PCRE_CASELESS;
	if(multiLine)
		options |= (PCRE_MULTILINE | PCRE_DOTALL);
	if(utf8Mode)
		options |= PCRE_UTF8;

	const char *error;
	int erroffset;
	*regex = pcre_compile(regexExp.c_str(),options, &error, &erroffset,  NULL);
	if (*regex == NULL) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"PCRE compilation failed at offset %d: %s\n", erroffset, error);
		return false; }

	*extra_data = pcre_study(*regex,0,&error);

	*subStringCount = -1;
	if(pcre_fullinfo(*regex,*extra_data,PCRE_INFO_CAPTURECOUNT,subStringCount)!=0) {
		pcre_free(extra_data);
		return false; }

	*subStringPos = 0;
	if(*subStringCount == 0)
		*subStringCount = 1;
	if(*subStringCount) {
		*subStringCount = (*subStringCount + 1) * 3;
		*subStringPos  = new int[*subStringCount];}

	return true;
}

bool PCRERegex::Match(const pcre* regex, const pcre_extra* extra_data, const int subStringCount, int* subStringPos, const std::string& target, std::vector<std::string>& groups ) {

    unsigned int offset = 0;
    unsigned int len    = target.length();
    const char* str     = target.c_str();
    int rc              = -1;

    bool success = false;
    while (offset < len && (rc = pcre_exec(regex, extra_data, str, len, offset, 0, subStringPos, subStringCount)) >= 0) {

    	if(rc == 0) {
    		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"output buffer for regex groups too small");
			return false;}

    	const char* psubStrMatchStr = 0;
        for(int i = 0; i < rc; ++i) {

        	psubStrMatchStr = 0;
        	int subrc = pcre_get_substring(str, subStringPos, rc, i, &psubStrMatchStr);
        	if(subrc >= 0 && psubStrMatchStr) {
        		groups.push_back(psubStrMatchStr);
        		pcre_free_substring(psubStrMatchStr);
        	}
        	else {
            	log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid subgroup");
    			return false;
        	}
        }
        success = true;

        offset = subStringPos[1];
    }

	return success;
}

bool PCRERegex::Match(const std::string& target) {

	std::vector<std::string> groups;
	return Match(target,groups);
}

bool PCRERegex::Match(const std::string& target, std::vector<std::string>& groups) {

	if(!regex)
		return false;
	return PCRERegex::Match(regex, extra_data, subStringCount, subStringPos, target, groups);
}

bool PCRERegex::Match(const std::string& regexExp, const std::string& target, std::vector<std::string>& groups, const bool caseInsensitive, const bool multiLine, const bool utf8Mode ) {

	pcre* regex=0;
	pcre_extra* extra_data=0;
	int* subStringPos = 0;
	int subStringCount = -1;

	bool success = PCRERegex::Compile(regexExp, caseInsensitive, multiLine, utf8Mode, &regex, &extra_data, &subStringPos, &subStringCount);
	if(success && regex)
		success = PCRERegex::Match(regex,extra_data,subStringCount,subStringPos,target,groups);

	FreeRegex(&regex, &extra_data, &subStringPos);
	return success;
}

void PCRERegex::FreeRegex(pcre** regex, pcre_extra** extra_data, int** subStringPos) {

	if(*regex != 0)
		pcre_free(*regex);
	*regex = 0;

	if(*extra_data != 0)
		pcre_free(*extra_data);
	*extra_data = 0;

	if(subStringPos)
		delete [] *subStringPos;
}

PCRERegexResult PCRERegex::MatchEx(const char* target, const int offSet, const int nMaxMatches) {

	return MatchEx(regex, extra_data, subStringCount, subStringPos, target, offSet, nMaxMatches);
}

PCRERegexResult PCRERegex::MatchEx(const pcre* regex,const pcre_extra* extra_data,const int subStringCount,int* subStringPos,const char* target, const int offSet, const int nMaxMatches) {

	PCRERegexResult resultRegex;

	int offset          = offSet;
    int len             = strlen(target);
    const char* str     = target;
    int rc              = -1;

    resultRegex.success = false;
    int matches = 0;
    while ( offset < len && (rc = pcre_exec(regex, extra_data, str, len, offset, 0, subStringPos, subStringCount)) >= 0) {

    	if(rc == 0) {
    		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"output buffer for regex groups too small");
    		resultRegex.success = false;
    		return resultRegex;
    	}

    	if(matches==0){
    		resultRegex.begin = subStringPos[0];
    		resultRegex.end   = subStringPos[1];
    	}

    	const char* psubStrMatchStr = 0;
        for(int i = 0; i < rc; ++i) {

        	psubStrMatchStr = 0;
        	int subrc = pcre_get_substring(str, subStringPos, rc, i, &psubStrMatchStr);
        	if(subrc >= 0 && psubStrMatchStr) {

        		PCRERegexGroup group;
        		group.groupValue = psubStrMatchStr;
        		group.begin      = subStringPos[(i*2)];
        		group.end        = group.begin + group.groupValue.length();
        		resultRegex.groups.push_back(group);
        		pcre_free_substring(psubStrMatchStr);
        	}
        	else {
            	log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid subgroup");
        		resultRegex.success = false;
        		resultRegex.begin = resultRegex.end = -1;
        		return resultRegex;
        	}
        }
        resultRegex.success = true;


        if(nMaxMatches > 0 && nMaxMatches >= matches){
        	break; }

        matches++;
        offset = subStringPos[1] + 1;
    }

	return resultRegex;
}

}
