/*
 * UnitTestCacheUrl.cpp
 *
 *  Created on: 25.08.2012
 *      Author: Moritz Wagner
 */

#include "UnitTestCacheUrl.h"

#include <HttpUrlParser.h>
#include <HttpUrl.h>
#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>
#include <Exception.h>
#include <Logging.h>

namespace toolbot {

UnitTestCacheUrl::UnitTestCacheUrl() {
}

UnitTestCacheUrl::~UnitTestCacheUrl() {
}

bool UnitTestCacheUrl::TestUrlCache(database::DatabaseConnection* connection, std::vector<UnitTestUrl>& testUrls) {

	std::vector<UnitTestUrl>::iterator iterUrls = testUrls.begin();
	bool success = true;

	caching::CacheDatabaseUrl::Clear();
	for(;iterUrls != testUrls.end();++iterUrls) {
		success &= TestSingleEntry(connection, *iterUrls);
	}

	for(;iterUrls != testUrls.end();++iterUrls) {
		success &= TestSingleEntry(connection, *iterUrls);
	}

	if(!success) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"\n\n !!! CACHE URL UNIT TEST FAILED !!! \n\n");	}
	else {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"all cache url unit tests passed");	}
	return success;
}

bool UnitTestCacheUrl::TestSingleEntry(database::DatabaseConnection* db, UnitTestUrl& testUrl) {

	//parse url strings into HttpUrls
	if(!testUrl.baseUrl.empty()) {
		network::HttpUrlParser::ParseURL(testUrl.baseUrl,testUrl.base);
		network::HttpUrlParser::ParseURL(testUrl.base,testUrl.theUrl,testUrl.url);
	}
	else {
		network::HttpUrlParser::ParseURL(testUrl.theUrl,testUrl.url);
	}
	network::HttpUrlParser::ParseURL(testUrl.resultUrl,testUrl.result);
	if(!testUrl.url.DeepMatchUrl(testUrl.result)) {
		log::Logging::Log(
			log::Logging::LOGLEVEL_ERROR,
			"failed matching HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			testUrl.url.Dump().c_str(),
			testUrl.result.Dump().c_str()
		);
		return false;
	}

	//fetch result and test url from cache by string
	htmlparser::DatabaseUrl byStringTestUrl   = caching::CacheDatabaseUrl::GetByUrlString(db,testUrl.url.GetFullUrl());
	htmlparser::DatabaseUrl byStringResultUrl = caching::CacheDatabaseUrl::GetByUrlString(db,testUrl.result.GetFullUrl());
	if(!byStringTestUrl.DeepMatchUrl(byStringResultUrl)) {
		log::Logging::Log(
			log::Logging::LOGLEVEL_ERROR,
			"failed matching DatabaseUrls by HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			byStringTestUrl.Dump().c_str(),
			byStringResultUrl.Dump().c_str()
		);
		return false;
	}

	//fetch result and test url from cache by HttpUrl
	htmlparser::DatabaseUrl dbTestUrl   = caching::CacheDatabaseUrl::GetByUrl(db,testUrl.url);
	htmlparser::DatabaseUrl dbResultUrl = caching::CacheDatabaseUrl::GetByUrl(db,testUrl.result);
	if( dbTestUrl.GetUrlID() == -1 || !dbTestUrl.DeepMatchUrl(dbResultUrl) ) {
		log::Logging::Log(
			log::Logging::LOGLEVEL_ERROR,
			"failed matching DatabaseUrls by HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			dbTestUrl.Dump().c_str(),
			dbResultUrl.Dump().c_str()
		);
		return false;
	}

	//fetch result and test url from cache by ID
	htmlparser::DatabaseUrl byIdTestUrl   = caching::CacheDatabaseUrl::GetByUrlID(db, dbTestUrl.GetUrlID());
	htmlparser::DatabaseUrl byIdResultUrl = caching::CacheDatabaseUrl::GetByUrlID(db, dbResultUrl.GetUrlID());
	if( byIdTestUrl.GetUrlID() == -1 || !byIdTestUrl.DeepMatchUrl(byIdResultUrl) ) {
		log::Logging::Log(
			log::Logging::LOGLEVEL_ERROR,
			"failed matching DatabaseUrls by IDs:\nTestUrl: %s\nResultUrl:\n%s",
			dbTestUrl.Dump().c_str(),
			dbResultUrl.Dump().c_str()
		);
		return false;
	}

	return true;
}

}
