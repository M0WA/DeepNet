/**
 * @file RobotTxt.h
 * @author Moritz Wagner
 * @date 03.12.2012
 */

#include "RobotTxt.h"

#include <DatabaseUrl.h>
#include <StringTools.h>
#include <FileTools.h>
#include <sstream>

#define REGEX_ROBOTS_LINE "((dis)?allow|user-agent)\\s*:\\s*(.*)"

namespace caching {

RobotTxt::RobotTxt()
: toplevelID(-1)
, secondlevelID(-1)
, subdomainID(-1) {
}

RobotTxt::RobotTxt( const long long& toplevelID, const long long& secondlevelID, const long long& subdomainID )
: toplevelID(toplevelID)
, secondlevelID(secondlevelID)
, subdomainID(subdomainID) {
}

RobotTxt::~RobotTxt() {
}

bool RobotTxt::Load(const std::string& robotsTxt) {

	std::vector<std::string> lines;
	std::istringstream stream(robotsTxt);
	std::string line;
	while (std::getline(stream, line)) {
	 lines.push_back(line);	}
	tools::StringTools::RemoveComments(lines);
	tools::StringTools::RemoveEmptyLines(lines);

	std::vector<std::string> groups;
	std::vector<std::string>::iterator iterLines(lines.begin());

	std::string tmpUserAgent;
	std::vector<std::string> tmpDisallow;

	tools::PCRERegex regexLine(REGEX_ROBOTS_LINE, true);
	for(;iterLines != lines.end();++iterLines) {

		if( regexLine.Match(iterLines->c_str(), groups) && groups.size() >= 4){

			std::string& key(groups.at(1)), value(groups.at(3));

			tools::StringTools::ToLowerIP(key);
			if(key.compare("user-agent") == 0) {

				if(!tmpUserAgent.empty() && tmpDisallow.size() > 0) {
					useragent[tmpUserAgent] = tmpDisallow;
					tmpDisallow.clear();
				}

				tmpUserAgent = value;
			}
			else if (!tmpUserAgent.empty()) {

				if(key.compare("disallow") == 0) {
					tmpDisallow.push_back(value);
				}
				else if(key.compare("allow") == 0) {
					tmpDisallow.push_back(value);
				}
				else {
					//ignoring invalid key
				}
			}
			else {
				//ignoring non-targeted entry
			}
		}

		groups.clear();
	}

	return true;
}

bool RobotTxt::AppliesTo(const htmlparser::DatabaseUrl& url) const {

	bool success = true;
	success &= (toplevelID    == url.GetTopLevelID());
	success &= (secondlevelID == url.GetSecondLevelID());
	success &= (subdomainID   == url.GetSubdomainID());
	return success;
}

bool RobotTxt::IsAllowed(const htmlparser::DatabaseUrl& url, const std::string& userAgent) {

	std::vector<std::string>* pTmp = 0;
	if(useragent.count(userAgent) > 0) {
		pTmp = &(useragent[userAgent]);
	}
	else if(useragent.count("*") > 0) {
		pTmp =&(useragent["*"]); }

	if(!pTmp)
		return true;

	std::string fullPath(url.GetFullPathSearch());
	std::vector<std::string>::const_iterator iterDisallow(pTmp->begin());
	for(;iterDisallow != pTmp->end();++iterDisallow) {
		if(fullPath.find(iterDisallow->c_str()) == 0) {
			return false;
		}
	}

	return true;
}

std::string RobotTxt::ToString() {

	std::ostringstream ssRobotsTxt;
	std::map<std::string, std::vector<std::string> >::const_iterator iterUserAgent(useragent.begin());
	for(;iterUserAgent != useragent.end();++iterUserAgent) {

		ssRobotsTxt << "User-Agent: " << iterUserAgent->first << std::endl;

		const std::vector<std::string>& vecDisallow(iterUserAgent->second);
		std::vector<std::string>::const_iterator iterDisallow(vecDisallow.begin());
		for(;iterDisallow != vecDisallow.end();++iterDisallow) {

			ssRobotsTxt << "Disallow: " << *iterDisallow << std::endl;
		}
		ssRobotsTxt << std::endl;
	}

	return ssRobotsTxt.str();
}

}
