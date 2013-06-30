/**
 *
 * @file CrawlerFactory.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "CrawlerFactory.h"

#include "FencedCrawler.h"
#include "CommerceSearchCrawler.h"
#include "DataminingCrawler.h"
#include "GenericWebCrawler.h"

namespace crawler {

CrawlerFactory::CrawlerFactory() {
}

CrawlerFactory::~CrawlerFactory() {
}

Crawler* CrawlerFactory::CreateFencedCrawler(const CrawlerParam* crawlerParam,const std::vector<long long>& boundSecondLevelDomains){
	return new FencedCrawler(crawlerParam,boundSecondLevelDomains);
}

Crawler* CrawlerFactory::CreateCommerceSearchCrawler(const CrawlerParam* crawlerParam){
	return new CommerceSearchCrawler(crawlerParam);
}

Crawler* CrawlerFactory::CreateDataminingCrawler(const CrawlerParam* crawlerParam){
	return new DataminingCrawler(crawlerParam);
}

Crawler* CrawlerFactory::CreateGenericWebCrawler(const CrawlerParam* crawlerParam){
	return new GenericWebCrawler(crawlerParam);
}

}
