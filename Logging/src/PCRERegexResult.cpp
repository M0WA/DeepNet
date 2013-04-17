/**
 * @file PCRERegexResult.cpp
 * @author Moritz Wagner
 * @date 15.11.2012
 */

#include "PCRERegexResult.h"

#include <sstream>
#include <cstring>

namespace tools {

PCRERegexResult::PCRERegexResult()
: begin(-1)
, end(-1)
, success(false){
}

PCRERegexResult::~PCRERegexResult() {
}

std::string PCRERegexResult::Dump(const char* pszTarget) const {

	char* pszMatchValue = NULL;
	if(success && begin != -1 && end != -1) {
		size_t sizeMatch = end-begin + 1;
		pszMatchValue = new char[sizeMatch];
		pszMatchValue[sizeMatch-1]=0;
		memcpy(pszMatchValue,&pszTarget[begin],end-begin);
	}

	std::ostringstream ssOut;
	ssOut << std::endl
		<< "result: " << (success ? "successful" : "unsuccessful") << std::endl
		<< "\tstart: " << begin << std::endl
		<< "\tstop: " << end << std::endl
		<< "\tmatchValue: "<< std::endl << (pszMatchValue ? pszMatchValue : "N/A") << std::endl
		<< "groups: " << groups.size() << " groups detected" << std::endl;

	delete [] pszMatchValue;
	pszMatchValue = NULL;

	std::vector<PCRERegexGroup>::const_iterator iterGroups = groups.begin();
	for(size_t groupNo = 1;iterGroups != groups.end();++iterGroups,groupNo++) {
		ssOut
			<< "\tgroup: " << groupNo << std::endl
			<< "\tstart: " << iterGroups->begin << std::endl
			<< "\tstop:  " << iterGroups->end << std::endl
			<< "\tgroupValue: " << std::endl << iterGroups->groupValue << std::endl;
	}

	return ssOut.str();
}

}
