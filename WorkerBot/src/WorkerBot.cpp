/**
 * @file WorkerBot.cpp
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#include "WorkerBot.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <Crawler.h>
#include <CrawlerParam.h>
#include <CrawlerFactory.h>

#include <HtmlParserBase.h>
#include <HtmlParserParam.h>
#include <HtmlParserBaseFactory.h>
#include <HtmlParserFactory.h>

#include <Indexer.h>
#include <IndexerParam.h>
#include <IndexerFactory.h>

#include <HtmlParserBase.h>
#include <HttpUrlParser.h>

#include <Logging.h>
#include <PerformanceCounter.h>
#include <StringTools.h>
#include <NotImplementedException.h>

#include <DatabaseLayer.h>

#include <DatabaseRepair.h>

namespace workerbot {

WorkerBot::WorkerBot()
: Bot() {
}

WorkerBot::~WorkerBot() {
}

bool WorkerBot::OnInit()
{
	bool bSuccess = true;

	crawlerParam.Set(new crawler::CrawlerParam(),true);
	parserParam.Set(new parser::HtmlParserParam(),true);
	indexerParam.Set(new indexing::IndexerParam(),true);

	bSuccess &= InitCrawlerConfig();
	bSuccess &= InitParserConfig();
	bSuccess &= InitIndexerConfigParams();

	return bSuccess;
}

bool WorkerBot::OnRun() {

	crawlerParam.Get()->databaseConfig =
	parserParam.Get() ->databaseConfig =
	indexerParam.Get()->databaseConfig = dbConfig;

	bool bSuccess = true;

	bSuccess &= crawler.Get()->StartThread();
	bSuccess &= parser.Get() ->StartThread();
	bSuccess &= indexer.Get()->StartThread();

	return bSuccess;
}

bool WorkerBot::OnShutdown() {

#ifdef ENABLE_PERFORMANCE_LOG
	tools::PerformanceCounter tmp;
	std::ostringstream oDetails;
	oDetails << "detailed shutdown times: " << std::endl;
#endif

	PERFORMANCE_LOG_START;

#ifdef ENABLE_PERFORMANCE_LOG
	tmp.Start();
#endif
	crawler.Get()->SetShallEnd(true);
	crawler.Get()->WaitForThread();

#ifdef ENABLE_PERFORMANCE_LOG
	oDetails << "crawler threads shutdown: " << tmp.Stop() << std::endl;
	tmp.Start();
#endif

	parser.Get()->SetShallEnd(true);
	parser.Get()->WaitForThread();

#ifdef ENABLE_PERFORMANCE_LOG
	oDetails << "parser threads shutdown: " << tmp.Stop() << std::endl;
	tmp.Start();
#endif

	indexer.Get()->SetShallEnd(true);
	indexer.Get()->WaitForThread();

#ifdef ENABLE_PERFORMANCE_LOG
	oDetails << "indexer threads shutdown: " << tmp.Stop();
	log::Logging::LogTrace(oDetails.str());
#endif

	PERFORMANCE_LOG_STOP("shutdown WorkerBot");
	return true;
}

bool WorkerBot::OnPreInit(void)
{
	RegisterCrawlerConfigParams();
	RegisterParserConfigParams();
	RegisterIndexerConfigParams();
	RegisterModeSpecificParams();

	Config().RegisterFlag("autoFixUncleanShutdown","fixing database inconsistencies on shutdown",false);
	return true;
}

bool WorkerBot::OnPostInit() {

	return InitModeConfig();
}

void WorkerBot::RegisterCrawlerConfigParams()
{
	std::string initalThreads = "8";
	Config().RegisterParam("crawler_threads", "number of concurrent crawler threads", true, &initalThreads);

	std::string defaultMinAge = "30";
	Config().RegisterParam("crawler_minAge", "minimum age of page in days before recrawl", true, &defaultMinAge);

	std::string defaultMaxPerSelect = "20";
	Config().RegisterParam("crawler_maxUrl", "maximum size of selected urls per turn", true, &defaultMaxPerSelect);

	std::string defaultUserAgent = "Mozilla/5.0 (Windows NT 6.2; rv:9.0.1) Gecko/20100101 Firefox/9.0.1";
	Config().RegisterParam("crawler_userAgent", "user agent string", true, &defaultUserAgent);

	std::string defaultConnectTimeout = "8";
	Config().RegisterParam("crawler_cntTimeout", "timeout for connect() in sec", true, &defaultConnectTimeout);

	std::string defaultConnectionTimeout = "15";
	Config().RegisterParam("crawler_connectionTimeout", "timeout for connection, overall in sec", true, &defaultConnectionTimeout);

	Config().RegisterFlag("crawler_ipv6", "enable the use of ipv6", false);

	std::string defaultSpeedLimit = "300";
	Config().RegisterParam("crawler_limit", "speed limit per connection in kb (0 <= unlimited)", true, &defaultSpeedLimit);

	std::string waitOnIdle = "10";
	Config().RegisterParam("crawler_waitIdle", "how long to wait for recheck if idle in seconds", true, &waitOnIdle);

	std::string respectRobotsTxt = "1";
	Config().RegisterParam("crawler_respectRobotsTxt", "respect robots.txt when crawling sites", true, &respectRobotsTxt);

	std::string httpClientType = "curl";
	Config().RegisterParam("crawler_client", "http client used for crawling ( curl | own )", true, &httpClientType);
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
	Config().RegisterParam("parser_threads", "number of concurrent parser threads", true, &initalThreads);

	std::string defaultMaxPerSelect = "20";
	Config().RegisterParam("parser_maxUrl", "maximum size of selected urls per turn", true, &defaultMaxPerSelect);

	std::string waitOnIdle = "10";
	Config().RegisterParam("parser_waitIdle", "how long to wait for recheck if parser is idle in seconds", true, &waitOnIdle);

	std::string parserType = "libxml";
	Config().RegisterParam("parser_type", "type of parser: libxml | domparser", true, &parserType);
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
	Config().RegisterParam("indexer_threads", "number of concurrent indexer threads", true, &initalThreads);

	std::string waitOnIdle = "10";
	Config().RegisterParam("indexer_waitIdle", "how long to wait for recheck if indexer is idle in seconds", true, &waitOnIdle);

	std::string maxPerSelect = "100";
	Config().RegisterParam("indexer_maxUrl", "maximum size of selected urls per turn", true, &maxPerSelect);
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

void WorkerBot::RegisterModeSpecificParams()
{
	std::string workerBotMode = "searchengine";
	Config().RegisterParam("worker_bot_mode", "mode of workerbot, one of: searchengine, commercesearch, datamining, fenced", true, &workerBotMode);
}

bool WorkerBot::InitModeConfig()
{
	std::string workerBotMode;
	if(!Config().GetValue("worker_bot_mode",workerBotMode) ){
		THROW_EXCEPTION(errors::NotImplementedException,"WorkerBot missing mode, use one of: commercesearch,datamining,searchengine");}

	//initializing commercesearch
	if(workerBotMode.compare("commercesearch") == 0) {

		crawler.Set(crawler::CrawlerFactory::CreateCommerceSearchCrawler(crawlerParam.Get()),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateCommerceSearchParser(parserParam.Get()),true);
		indexer.Set(indexing::IndexerFactory::CreateGenericWebIndexer(indexerParam.Get()),true);
	}
	//initializing searchengine
	else if(workerBotMode.compare("searchengine") == 0) {

		crawler.Set(crawler::CrawlerFactory::CreateGenericWebCrawler(crawlerParam.Get()),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateGenericWebParser(parserParam.Get()),true);
		indexer.Set(indexing::IndexerFactory::CreateGenericWebIndexer(indexerParam.Get()),true);
	}
	//initializing datamining
	else if (workerBotMode.compare("datamining") == 0) {

		crawler.Set(crawler::CrawlerFactory::CreateDataminingCrawler(crawlerParam.Get()),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateGenericWebParser(parserParam.Get()),true);
		indexer.Set(indexing::IndexerFactory::CreateDataminingIndexer(indexerParam.Get()),true);
	}
	//initializing fenced mode
	else if (workerBotMode.compare("fenced") == 0) {

		crawler.Set(crawler::CrawlerFactory::CreateFencedCrawler(crawlerParam.Get()),true);
		parser.Set(parser::HtmlParserBaseFactory::CreateGenericWebParser(parserParam.Get()),true);
		indexer.Set(indexing::IndexerFactory::CreateGenericWebIndexer(indexerParam.Get()),true);
	}
	else {
		THROW_EXCEPTION(errors::NotImplementedException,"Invalid WorkerBot mode, use one of: commercesearch,datamining,searchengine,fenced; current mode: " + workerBotMode);
	}
	return true;
}

bool WorkerBot::CheckCleanShutdown() {

	bool autoFixUncleanShutdown = false;
	if(!Config().GetValue("autoFixUncleanShutdown",autoFixUncleanShutdown) ||
		autoFixUncleanShutdown == false ) {
		return true;}

	log::Logging::LogInfo("checking database consistency after shutdown");

	if(!bot::DatabaseRepair::FixUncleanShutdown(DB().Connection(),true,crawler.Get()->GetOldCrawlerSessionIDs())) {
		log::Logging::LogError("errors while checking/fixing database consistency after shutdown");
		return false; }

	return true;
}

}
