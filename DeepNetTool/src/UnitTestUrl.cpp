/*
 * UnitTestUrl.cpp
 *
 *  Created on: 25.08.2012
 *      Author: Moritz Wagner
 */

#include "UnitTestUrl.h"

#include <FileTools.h>
#include <Regex.h>

namespace toolbot {

bool UnitTestUrl::ReadValidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls) {

	std::vector<std::string> lines;
	bool bSuccessReadFile = tools::FileTools::ReadFile(urlFileName,lines);
	if(!bSuccessReadFile)
		return false;

	std::vector<std::string>::iterator iterLines = lines.begin();
	for(int line=1;iterLines != lines.end();++iterLines,line++) {

		std::string findGroupRegex;
		findGroupRegex = "^[[:blank:]]*\"(.*?)\"[[:blank:]]*\"(.*?)\"[[:blank:]]*\"(.*?)\"";

		std::vector<std::string> groups;
		if(!tools::Regex::Match(findGroupRegex,*iterLines,groups,true)
		 || groups.size() < 3 ) {
			continue; }

		UnitTestUrl url;
		url.baseUrl   = groups.at(0);
		url.theUrl    = groups.at(1);
		url.resultUrl = groups.at(2);
		url.line      = line;
		testUrls.push_back(url);
	}

	return testUrls.size() > 0;
}

bool UnitTestUrl::ReadInvalidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls) {

	std::vector<std::string> lines;
	bool bSuccessReadFile = tools::FileTools::ReadFile(urlFileName,lines);
	if(!bSuccessReadFile)
		return false;

	std::vector<std::string>::iterator iterLines = lines.begin();
	for(int line=1;iterLines != lines.end();++iterLines,line++) {

		std::string findGroupRegex;
		findGroupRegex = "^[[:blank:]]*\"(.*?)\"[[:blank:]]*\"(.*?)\"";

		std::vector<std::string> groups;
		if(!tools::Regex::Match(findGroupRegex,*iterLines,groups,true)
		 || groups.size() < 2 ) {
			continue; }

		UnitTestUrl url;
		url.baseUrl = groups.at(0);
		url.theUrl  = groups.at(1);
		url.line    = line;
		testUrls.push_back(url);
	}

	return testUrls.size() > 0;
}

}
