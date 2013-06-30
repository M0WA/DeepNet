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

Crawler* CrawlerFactory::CreateFencedCrawler(const std::vector<long long>& boundSecondLevelDomains){
	return new FencedCrawler(boundSecondLevelDomains);
}

Crawler* CrawlerFactory::CreateCommerceSearchCrawler(){
	return new CommerceSearchCrawler();
}

Crawler* CrawlerFactory::CreateDataminingCrawler(){
	return new DataminingCrawler();
}

Crawler* CrawlerFactory::CreateGenericWebCrawler(){
	return new GenericWebCrawler();
}

}
