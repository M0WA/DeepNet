/*
 * WorkerBot.cpp
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#include "WorkerBot.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <Crawler.h>
#include <CrawlerFactory.h>

#include <HtmlParserBase.h>
#include <HtmlParserBaseFactory.h>
#include <HtmlParserParam.h>
#include <HtmlParserFactory.h>

#include <GenericWebIndexer.h>
#include <DataminingIndexer.h>

#include <HtmlParserBase.h>
#include <HttpUrlParser.h>

#include <Logging.h>
#include <StringTools.h>
#include <NotImplementedException.h>

#include <TLD.h>
#include <DatabaseLayer.h>

WorkerBot::WorkerBot()
: Bot() {
}

WorkerBot::~WorkerBot() {
}

bool WorkerBot::OnInit()
{
	bool bSuccess = true;

	bSuccess &= InitCrawlerConfig();
	bSuccess &= InitParserConfig();
	bSuccess &= InitIndexerConfigParams();

	return bSuccess;
}

bool WorkerBot::OnRun() {

	crawlerParam.Get()->databaseConfig =
	parserParam.Get() ->databaseConfig =
	indexerParam.Get()->databaseConfig = dbConfig;

	database::DatabaseConnection* conn = DB().CreateConnection(dbConfig);
	if(conn) {
		htmlparser::TLD::InitTLDCache(DB().Connection());
		std::vector<std::string> tldString;
		htmlparser::TLD::GetTLDStrings(tldString);
		network::HttpUrlParser::SetTopLevelDomains(tldString);
		DB().DestroyConnection();
	}
	else {
		return false;}

	bool bSuccess = true;

	bSuccess &= crawler.Get()->StartThread();
	bSuccess &= parser.Get() ->StartThread(parserParam.Get());
	bSuccess &= indexer.Get()->StartThread(indexerParam.Get());

	return bSuccess;
}

bool WorkerBot::OnShutdown() {

	crawler.Get()->SetShallEnd(true);
	crawler.Get()->WaitForThread();

	parser.Get()->SetShallEnd(true);
	parser.Get()->WaitForThread();

	indexer.Get()->SetShallEnd(true);
	indexer.Get()->WaitForThread();

	return true;
}

bool WorkerBot::OnPreInit(void)
{
	RegisterCrawlerConfigParams();
	RegisterParserConfigParams();
	RegisterIndexerConfigParams();

	std::string workerBotMode = "searchengine";
	Config().RegisterParam("worker_bot_mode", "mode of workerbot, one of: searchengine, commercesearch, datamining", true, false, &workerBotMode);

	return true;
}

bool WorkerBot::OnPostInit() {

	std::string workerBotMode;
	if(!Config().GetValue("worker_bot_mode",workerBotMode) ){
		THROW_EXCEPTION(errors::NotImplementedException,"WorkerBot missing mode, use one of: commercesearch,datamining,searchengine");}

	//initializing commercesearch
	if(workerBotMode.compare("commercesearch") == 0) {

		crawlerParam.Set(new crawler::CrawlerParam(),true);
		crawler.Set(crawler::CrawlerFactory::CreateCommerceSearchCrawler(crawlerParam.Get()),true);

		parserParam.Set(new parser::HtmlParserParam(),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateCommerceSearchParser(parserParam.Get()),true);

		indexer.Set(dynamic_cast<indexing::Indexer*>(new indexing::GenericWebIndexer()),true);
		indexerParam.Set(new indexing::Indexer::IndexerParam(),true);
	}
	//initializing searchengine
	else if(workerBotMode.compare("searchengine") == 0) {

		crawlerParam.Set(new crawler::CrawlerParam(),true);
		crawler.Set(crawler::CrawlerFactory::CreateGenericWebCrawler(crawlerParam.Get()),true);

		parserParam.Set(new parser::HtmlParserParam(),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateGenericWebParser(parserParam.Get()),true);

		indexer.Set(dynamic_cast<indexing::Indexer*>(new indexing::GenericWebIndexer()),true);
		indexerParam.Set(new indexing::Indexer::IndexerParam(),true);
	}
	//initializing datamining
	else if (workerBotMode.compare("datamining") == 0) {

		crawlerParam.Set(new crawler::CrawlerParam(),true);
		crawler.Set(crawler::CrawlerFactory::CreateDataminingCrawler(crawlerParam.Get()),true);

		parserParam.Set(new parser::HtmlParserParam(),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateGenericWebParser(parserParam.Get()),true);

		indexer.Set(dynamic_cast<indexing::Indexer*>(new indexing::DataminingIndexer()),true);
		indexerParam.Set(new indexing::Indexer::IndexerParam(),true);
	}
	else {
		THROW_EXCEPTION(errors::NotImplementedException,"Invalid WorkerBot mode, use one of: commercesearch,datamining,searchengine, current mode: " + workerBotMode);
	}

	return true;
}

void WorkerBot::RegisterCrawlerConfigParams()
{
	std::string initalThreads = "8";
	Config().RegisterParam("crawler_threads", "number of concurrent crawler threads", true, false, &initalThreads);

	std::string defaultMinAge = "30";
	Config().RegisterParam("crawler_minAge", "minimum age of page in days before recrawl", true, false, &defaultMinAge);

	std::string defaultMaxPerSelect = "20";
	Config().RegisterParam("crawler_maxUrl", "maximum size of selected urls per turn", true, false, &defaultMaxPerSelect);

	std::string defaultUserAgent = "Mozilla/5.0 (Windows NT 6.2; rv:9.0.1) Gecko/20100101 Firefox/9.0.1";
	Config().RegisterParam("crawler_userAgent", "user agent string", true, false, &defaultUserAgent);

	std::string defaultConnectTimeout = "8";
	Config().RegisterParam("crawler_cntTimeout", "timeout for connect() in sec", true, false, &defaultConnectTimeout);

	std::string defaultConnectionTimeout = "15";
	Config().RegisterParam("crawler_connectionTimeout", "timeout for connection, overall in sec", true, false, &defaultConnectionTimeout);

	Config().RegisterParam("crawler_ipv6", "enable the use of ipv6", false, true, 0);

	std::string defaultSpeedLimit = "300";
	Config().RegisterParam("crawler_limit", "speed limit per connection in kb (0 <= unlimited)", true, false, &defaultSpeedLimit);

	std::string waitOnIdle = "10";
	Config().RegisterParam("crawler_waitIdle", "how long to wait for recheck if idle in seconds", true, false, &waitOnIdle);

	std::string respectRobotsTxt = "1";
	Config().RegisterParam("crawler_respectRobotsTxt", "respect robots.txt when crawling sites", true, false, &respectRobotsTxt);

	std::string httpClientType = "curl";
	Config().RegisterParam("crawler_client", "http client used for crawling ( curl | own )", true, false, &httpClientType);
}

bool WorkerBot::InitCrawlerConfig()
{
	if(crawlerParam.IsNull()) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"crawler parameters not initialized correctly. exiting...");
		return false;}

	if( !Config().GetValue( "crawler_threads", crawlerParam.Get()->threadCount) )
		return false;

	if(crawlerParam.Get()->threadCount<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_threads count specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("crawler_maxUrl",crawlerParam.Get()->maxPerSelect)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_maxUrl !!!");
		return false;}
	if(crawlerParam.Get()->maxPerSelect<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_maxUrl specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("crawler_minAge",crawlerParam.Get()->minAge)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_minAge !!!");
		return false;}
	if(crawlerParam.Get()->minAge<0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_minAge specified (< 0). exiting...");
		return false;}
	if(crawlerParam.Get()->minAge==0){
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"!!! WARNING crawler_minAge == 0 specified !!!");}

	if(!Config().GetValue("crawler_userAgent",crawlerParam.Get()->userAgent)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_userAgent !!!");
		return false;}

	if(!Config().GetValue("crawler_cntTimeout",crawlerParam.Get()->connectTimeout) || crawlerParam.Get()->connectTimeout <= 0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! invalid/missing crawler_cntTimeout timeout !!!");
		return false;}

	if(!Config().GetValue("crawler_connectionTimeout",crawlerParam.Get()->connectionTimeout) || crawlerParam.Get()->connectionTimeout <= 0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! invalid/missing crawler_connectionTimeout !!!");
		return false;}

	if(!Config().GetValue("crawler_ipv6",crawlerParam.Get()->useIPv6))
		crawlerParam.Get()->useIPv6 = false;

	if(!Config().GetValue("crawler_limit", crawlerParam.Get()->speedLimitKB)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_limit !!!");
		return false;}

	if(!Config().GetValue("crawler_waitIdle",crawlerParam.Get()->waitOnIdle)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_waitIdle !!!");
		return false;}

	if(!Config().GetValue("crawler_respectRobotsTxt",crawlerParam.Get()->respectRobotsTxt)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_respectRobotsTxt !!!");
		return false;}

	std::string httpClientType = "curl";
	if(!Config().GetValue("crawler_client",httpClientType)){
		httpClientType = "curl";}

	if(httpClientType.compare("curl") == 0) {
		crawlerParam.Get()->clientType = network::HttpClientFactory::CURL; }
	else if(httpClientType.compare("own") == 0) {
		crawlerParam.Get()->clientType = network::HttpClientFactory::OWN; }
	else {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_client specified. exiting...");
		return false; }

	return true;
}

void WorkerBot::RegisterParserConfigParams()
{
	std::string initalThreads = "8";
	Config().RegisterParam("parser_threads", "number of concurrent parser threads", true, false , &initalThreads);

	std::string defaultMaxPerSelect = "20";
	Config().RegisterParam("parser_maxUrl", "maximum size of selected urls per turn", true, false ,&defaultMaxPerSelect);

	std::string waitOnIdle = "10";
	Config().RegisterParam("parser_waitIdle", "how long to wait for recheck if parser is idle in seconds", true, false ,&waitOnIdle);

	std::string parserType = "libxml";
	Config().RegisterParam("parser_type", "type of parser: libxml | domparser", true, false ,&parserType);
}

bool WorkerBot::InitParserConfig()
{
	if(parserParam.IsNull()) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"parser parameters not initialized correctly. exiting...");
		return false;}

	if( !Config().GetValue( "parser_threads", parserParam.Get()->parserThreadCount) )
		return false; //should not happen as "threads" is mandatory...

	if(parserParam.Get()->parserThreadCount<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser thread count specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("parser_maxUrl",parserParam.Get()->maxPerSelect))
		return false;
	if(parserParam.Get()->maxPerSelect<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser_maxUrl specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("parser_waitIdle",parserParam.Get()->waitOnIdle))
		return false;
	if(parserParam.Get()->waitOnIdle<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser_waitIdle specified (<= 0). exiting...");
		return false;}

	std::string parserType = "libxml";
	if(!Config().GetValue("parser_type",parserType)) {
		parserType = "libxml"; }

	tools::StringTools::ToLowerIP(parserType);
	if(parserType.compare("libxml") == 0) {
		parserParam.Get()->parserType = htmlparser::HtmlParserFactory::LIBXML; }
	else if(parserType.compare("dom") == 0) {
		parserParam.Get()->parserType = htmlparser::HtmlParserFactory::DOM; }
	else {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser_type specified. exiting...");
		return false; }

	return true;
}

void WorkerBot::RegisterIndexerConfigParams()
{
	std::string initalThreads = "8";
	Config().RegisterParam("indexer_threads", "number of concurrent indexer threads", true, false, &initalThreads);

	std::string waitOnIdle = "10";
	Config().RegisterParam("indexer_waitIdle", "how long to wait for recheck if indexer is idle in seconds", true, false ,&waitOnIdle);

	std::string maxPerSelect = "100";
	Config().RegisterParam("indexer_maxUrl", "maximum size of selected urls per turn", true, false ,&maxPerSelect);
}

bool WorkerBot::InitIndexerConfigParams()
{
	if(indexerParam.IsNull()) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"parser parameters not initialized correctly. exiting...");
		return false;}

	if( !Config().GetValue( "indexer_threads", indexerParam.Get()->threadCount) )
		return false;

	if( !Config().GetValue( "indexer_waitIdle", indexerParam.Get()->waitOnIdle) )
		return false;

	if( !Config().GetValue( "indexer_maxUrl", indexerParam.Get()->maxPerSelect) )
		return false;

	return true;
}

