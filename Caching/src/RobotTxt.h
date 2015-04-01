/**
 * @file RobotTxt.h
 * @author Moritz Wagner
 * @date 03.12.2012
 */

#pragma once

#include <map>
#include <vector>
#include <string>

#include <PCRERegex.h>

namespace database {
	class DatabaseConnection;
}

namespace htmlparser {
	class DatabaseUrl;
}

namespace caching {

/**
 * @brief wrapper class for a robots.txt.
 */
class RobotTxt {
private:
	RobotTxt();
public:
	/**
	 * constructs object with corresponding domain ids.
	 * @param toplevelID toplevel domain id.
	 * @param secondlevelID secondlevel domain id.
	 * @param subdomainID subdomain id.
	 */
	RobotTxt(
			const long long& toplevelID,
			const long long& secondlevelID,
			const long long& subdomainID );

	virtual ~RobotTxt();

public:
	/**
	 * parse robots.txt from string.
	 * @param robotsTxt robots.txt as string.
	 * @return false on error, true on success.
	 */
	bool Load(const std::string& robotsTxt);

	/**
	 * check if url is valid for this robots.txt.
	 * @param url url to check.
	 * @return false if not matching, true if matching.
	 */
	bool AppliesTo(const htmlparser::DatabaseUrl& url) const;

	/**
	 * check if url is allowed.
	 * @param url url to check.
	 * @param userAgent useragent to check for.
	 * @return
	 */
	bool IsAllowed(
			const htmlparser::DatabaseUrl& url,
			const std::string& userAgent);

	/**
	 * dump robots.txt as string
	 * @return dumped string.
	 */
	std::string ToString();

private:
	long long toplevelID;
	long long secondlevelID;
	long long subdomainID;

	std::map<std::string, std::vector<std::string> > useragent;
};

}

