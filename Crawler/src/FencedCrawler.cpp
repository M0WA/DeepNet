/**
 *
 * @file FencedCrawler.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "FencedCrawler.h"

#include <Logging.h>
#include <OpenSSLThreadLock.h>
#include <DatabaseLayer.h>

#include "FencedUrlFetcherThread.h"

namespace crawler {

FencedCrawler::FencedCrawler(const CrawlerParam* crawlerParam)
: Crawler(crawlerParam){
}

FencedCrawler::~FencedCrawler() {
}

bool FencedCrawler::StartCrawler() {
	tools::thread_setup();

	//fetch all fenced secondlevel domains
	database::SelectStatement selectAll(database::fencedsearchTableBase::CreateTableDefinition());
	selectAll.SelectAllColumns();

	database::SelectResultContainer<database::fencedsearchTableBase> fencedTbls;

	database::DatabaseHelper dbHelper;
	database::DatabaseConnection* db = dbHelper.CreateConnection(crawlerParam->databaseConfig);
	db->Select(selectAll,fencedTbls);
	dbHelper.DestroyConnection();

	if(fencedTbls.Size() == 0) {
		log::Logging::LogError("no fenced searches found in database");
		return false; }

	fencedTbls.ResetIter();
	for(;!fencedTbls.IsIterEnd();fencedTbls.Next()) {
		long long secondLevelID = -1;
		fencedTbls.GetIter()->Get_SECONDLEVELDOMAIN_ID(secondLevelID);
		boundSecondLevelDomains.push_back(secondLevelID); }

	//check if there are more threads allowed than needed
	size_t actualThreadCount = crawlerParam->threadCount;
	if(actualThreadCount > boundSecondLevelDomains.size()) {
		actualThreadCount = boundSecondLevelDomains.size(); }

	//calculate how many secondlevel domains must be handled by each thread
	size_t domainsPerThread = ((boundSecondLevelDomains.size()/actualThreadCount)+1);

	size_t curPos = 0;
	for(size_t i = 0; i < actualThreadCount && curPos < boundSecondLevelDomains.size(); i++) {
		std::vector<long long> tmpBound;
		for(size_t posTmp = 0; posTmp < domainsPerThread && curPos < boundSecondLevelDomains.size(); posTmp++,curPos++) {
			tmpBound.push_back(boundSecondLevelDomains.at(curPos)); }

		if(tmpBound.size() > 0) {
			FencedUrlFetcherThread::FencedUrlFetcherThreadParam* fencedThreadParam =
					new FencedUrlFetcherThread::FencedUrlFetcherThreadParam(*crawlerParam,tmpBound);
			FencedUrlFetcherThread* urlFetcherThread = new FencedUrlFetcherThread();
			urlFetcherThread->StartThread(fencedThreadParam);

			urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
					dynamic_cast<UrlFetcherThreadParam*>(fencedThreadParam);
		}
	}
	tools::thread_cleanup();
	return true;
}

}
