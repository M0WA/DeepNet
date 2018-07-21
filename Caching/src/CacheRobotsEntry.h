/**
 * @file CacheRobotsEntry.h
 * @author Moritz Wagner
 * @date 04.12.2012
 */

#pragma once

#include "DatabaseUrl.h"

namespace caching {

/**
 * @brief container for caching robot.txts.
 */
class CacheRobotsEntry {

public:
	CacheRobotsEntry(long long toplevelID,	long long secondlevelID, long long subdomainID)
	: toplevelID(toplevelID)
	, secondlevelID(secondlevelID)
	, subdomainID(subdomainID) { }

	CacheRobotsEntry(const DatabaseUrl& url)
	: toplevelID(url.GetTopLevelID())
	, secondlevelID(url.GetSecondLevelID())
	, subdomainID(url.GetSubdomainID()) { }

	CacheRobotsEntry()
	: toplevelID(-1)
	, secondlevelID(-1)
	, subdomainID(-1) {	}

	/**
	 * compares by toplevel-, secondlevel- and subdomain.
	 * @param entry to compare to.
	 * @return false if larger or equal, true if smaller
	 */
	bool operator< (const CacheRobotsEntry& entry) const {
		if(toplevelID == entry.toplevelID) {
			if(secondlevelID == entry.secondlevelID) {
				return (subdomainID < entry.subdomainID);
			}
			else {
				return (secondlevelID < entry.secondlevelID);
			}
		}
		else {
			return (toplevelID < entry.toplevelID);
		}
	}

	/**
	 * compares by toplevel-, secondlevel- and subdomain.
	 * @param entry to compare to.
	 * @return false if not equal, true if equal
	 */
	bool operator== (const CacheRobotsEntry& entry) const {

		return(
			(toplevelID == entry.toplevelID) &&
			(secondlevelID == entry.secondlevelID) &&
			(subdomainID == entry.subdomainID)
		);
	}

	long long toplevelID;
	long long secondlevelID;
	long long subdomainID;

};

}

