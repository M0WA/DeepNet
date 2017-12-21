/*
 * @file SyncClient.h
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

namespace syncing {

/**
 * @brief syncing client implementation
 */
class SyncClient {
public:
	SyncClient(const std::string& apiUrl,const long long& crawlerID, const std::string& pass);
	virtual ~SyncClient();

public:
	/**
	 * releases crawler id
	 * @return true on success, false on error
	 */
	bool ReleaseCrawler();

	/**
	 * gets url ids
	 * @param count max number of urls to lock
	 * @param secondLevelDomainID if -1 a random domain will be reserved,else the given one, will be set to selected id
	 * @param urls urls ids that have been reserved
	 * @return true on success, false on error
	 */
	bool GetURLs(const long long& count,long long& secondLevelDomainID, std::vector<long long>& urls);

private:
	bool RegisterCrawler(const std::string& pass);
	bool DoRequest(const std::string& xmlIn,std::string& xmlOut);

private:
	std::string apiUrl;
	long long crawlerID;
	std::string token;
};

}
