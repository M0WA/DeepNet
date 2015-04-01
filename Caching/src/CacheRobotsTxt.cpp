/**
 * @file CacheRobotsTxt.cpp
 * @author Moritz Wagner
 * @date 04.12.2012
 */

#include "CacheRobotsTxt.h"

#include <sstream>
#include <HttpUrlParser.h>
#include <IHttpClient.h>
#include <HttpClientFactory.h>
#include <HttpResponse.h>

namespace caching {

CacheRobotsTxt CacheRobotsTxt::cacheInstance;

CacheRobotsTxt::CacheRobotsTxt(size_t limit)
: cacheRobotsTxts(limit,false)
, saveRobotsTxt(true) {
}

CacheRobotsTxt::~CacheRobotsTxt() {
}

bool CacheRobotsTxt::IsUrlAllowed(database::DatabaseConnection* db,const htmlparser::DatabaseUrl& url, const std::string& useragent) {

	CacheRobotsEntry entry(url);
	RobotTxt robot(url.GetTopLevelID(), url.GetSecondLevelID(), url.GetSubdomainID());

	//check in cache
	if(!cacheInstance.cacheRobotsTxts.GetItem(CacheRobotsEntry(url),robot)) {

		//try to load it from the database
		if(!LoadRobotsFromDatabase(db,entry,robot)) {
			//try to download it, if not found, all urls are allow
			DownloadRobotsTxt(db,url,robot);
		}
		cacheInstance.cacheRobotsTxts.AddItem(entry,robot);
	}

	return robot.IsAllowed(url,useragent);
}

bool CacheRobotsTxt::DownloadRobotsTxt(database::DatabaseConnection* db,const htmlparser::DatabaseUrl& url, RobotTxt& robot) {

	const std::string& scheme(url.GetScheme());
	const std::string& subdomain(url.GetSubdomain());
	const std::string& secondlvl(url.GetSecondLevelDomain());
	const std::string& tld(url.GetTLD());

	std::ostringstream robotsUrlString;
	robotsUrlString <<
		(!scheme.empty() ? (scheme+"://") : "http://") <<
		(!subdomain.empty() ? (subdomain+".") : "") <<
		secondlvl << "." <<
		tld <<
		"/robots.txt";

	network::HttpUrl robotUrl;
	try {
		network::HttpUrlParser::ParseURL(robotsUrlString.str(),robotUrl);
	}
	catch(...) {
		return false; }

	tools::Pointer<network::IHttpClient> client;
	if(!network::HttpClientFactory::CreateInstance(network::HttpClientFactory::CURL,client)) {
		return false; }

	network::HttpResponse responseHttp;
	if(!client.Get()->Get(robotUrl,responseHttp)) {
		return false;}

	bool success = robot.Load(responseHttp.html.GetBuffer());
	if(success && cacheInstance.saveRobotsTxt) {
		//TODO: save robots to database
	}

	return success;
}

bool CacheRobotsTxt::LoadRobotsFromDatabase(database::DatabaseConnection* db,const CacheRobotsEntry& entry, RobotTxt& robot) {

	if(!cacheInstance.saveRobotsTxt)
		return false;

	//TODO: load robots from database
	return false;
}

}
