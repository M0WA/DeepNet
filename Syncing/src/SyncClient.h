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
	bool ReleaseCrawler();
	bool GetURLs(const long long& secondLevelDomainID, const long long& count,std::vector<long long>& urls);

private:
	bool RegisterCrawler(const std::string& pass);
	bool DoRequest(const std::string& xmlIn,std::string& xmlOut);

private:
	std::string apiUrl;
	long long crawlerID;
	std::string token;
};

}
