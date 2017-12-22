/**
 *
 * @file UnitTestCacheUrl.cpp
 * @author Moritz Wagner
 * @date 25.08.2012
 *
 */

#include "UnitTestCacheUrl.h"

#include <HttpUrlParser.h>
#include <HttpUrl.h>

#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>

#include <Exception.h>
#include <Logging.h>
#include <Pointer.h>

namespace toolbot {

UnitTestCacheUrl::UnitTestCacheUrl(database::DatabaseConnection* connection,const std::string& urlFileName)
: connection(connection){
	UnitTestUrl::ReadValidURLFile(urlFileName, testUrls);
}

UnitTestCacheUrl::~UnitTestCacheUrl() {
}

bool UnitTestCacheUrl::Run() {

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
		log::Logging::LogError("\n\n !!! CACHE URL UNIT TEST FAILED !!! \n\n");	}
	else {
		log::Logging::LogInfo("all cache url unit tests passed");	}
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
		log::Logging::LogError(
			"failed matching HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			testUrl.url.Dump().c_str(),
			testUrl.result.Dump().c_str()
		);
		return false;
	}

	//fetch result and test url from cache by string
	tools::Pointer<caching::DatabaseUrl> byStringTestUrlPtr,byStringResultUrlPtr;
	caching::CacheDatabaseUrl::GetByUrlString(db,testUrl.url.GetFullUrl(),byStringTestUrlPtr);
	caching::CacheDatabaseUrl::GetByUrlString(db,testUrl.result.GetFullUrl(),byStringResultUrlPtr);
	caching::DatabaseUrl& byStringTestUrl(*byStringTestUrlPtr.Get()), &byStringResultUrl(*byStringResultUrlPtr.Get());
	if(!byStringTestUrl.DeepMatchUrl(byStringResultUrl)) {
		log::Logging::LogError(
			"failed matching DatabaseUrls by HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			byStringTestUrl.Dump().c_str(),
			byStringResultUrl.Dump().c_str()
		);
		return false;
	}

	log::Logging::LogTrace(
		"UnitTestCacheUrl:\nInputUrl : %s\nOutputUrl: %s",
		testUrl.url.GetFullUrl().c_str(),
		byStringResultUrl.GetFullUrl().c_str());

	//fetch result and test url from cache by HttpUrl
	tools::Pointer<caching::DatabaseUrl> dbTestUrlPtr,dbResultUrlPtr;
	caching::CacheDatabaseUrl::GetByUrl(db,testUrl.url,dbTestUrlPtr);
	caching::CacheDatabaseUrl::GetByUrl(db,testUrl.result,dbResultUrlPtr);
	caching::DatabaseUrl& dbTestUrl(*dbTestUrlPtr.Get()), &dbResultUrl(*dbResultUrlPtr.Get());
	if( dbTestUrl.GetUrlID() == -1 || !dbTestUrl.DeepMatchUrl(dbResultUrl) ) {
		log::Logging::LogError(
			"failed matching DatabaseUrls by HttpUrls:\nTestUrl: %s\nResultUrl:\n%s",
			dbTestUrl.Dump().c_str(),
			dbResultUrl.Dump().c_str()
		);
		return false;
	}

	//fetch result and test url from cache by ID
	tools::Pointer<caching::DatabaseUrl> byIdTestUrlPtr,byIdResultUrlPtr;
	caching::CacheDatabaseUrl::GetByUrlID(db, dbTestUrl.GetUrlID(),byIdTestUrlPtr);
	caching::CacheDatabaseUrl::GetByUrlID(db, dbResultUrl.GetUrlID(),byIdResultUrlPtr);
	caching::DatabaseUrl& byIdTestUrl(*byIdTestUrlPtr.Get()), &byIdResultUrl(*byIdResultUrlPtr.Get());
	if( byIdTestUrl.GetUrlID() == -1 || !byIdTestUrl.DeepMatchUrl(byIdResultUrl) ) {
		log::Logging::LogError(
			"failed matching DatabaseUrls by IDs:\nTestUrl: %s\nResultUrl:\n%s",
			dbTestUrl.Dump().c_str(),
			dbResultUrl.Dump().c_str()
		);
		return false;
	}

	return true;
}

}
