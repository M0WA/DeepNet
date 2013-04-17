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

#include <Logging.h>
#include <TLD.h>
#include <DatabaseLayer.h>
#include <GenericWebCrawler.h>
#include <CommerceSearchCrawler.h>
#include <CommerceSearchParser.h>
#include <CommerceSearchParserParam.h>
#include <GenericWebHtmlParser.h>
#include <GenericWebHtmlParserParam.h>
#include <GenericWebIndexer.h>
#include <DataminingCrawler.h>
#include <DataminingIndexer.h>
#include <HtmlParserBase.h>

#include <NotImplementedException.h>

WorkerBot::WorkerBot()
: Bot()
, crawler(0)
, parser(0)
, htmlParserParam(0)
, indexer(0) {
}

WorkerBot::~WorkerBot() {

	if(crawler || parser || htmlParserParam || indexer) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR," !!!!!!! LEAKING MEMORY: crawler, parser or indexer not deleted properly !!!!!!! "); }

	delete crawler;
	crawler = 0;

	delete parser;
	parser = 0;

	delete htmlParserParam;
	htmlParserParam = 0;

	delete indexer;
	indexer = 0;
}

bool WorkerBot::OnInit()
{
	bool bSuccess = true;

	std::string workerBotMode;
	if(!Config().GetValue("worker_bot_mode",workerBotMode) ){
		THROW_EXCEPTION(errors::NotImplementedException,"WorkerBot missing mode, use one of: commercesearch,datamining,searchengine");}

	//initializing commercesearch
	if(workerBotMode.compare("commercesearch") == 0) {
		crawler = dynamic_cast<crawler::Crawler*>(new crawler::CommerceSearchCrawler());
		parser  = dynamic_cast<parser::HtmlParserBase*>(new parser::CommerceSearchParser());
		htmlParserParam = dynamic_cast<parser::HtmlParserParam*>(new parser::CommerceSearchParserParam());
	}

	//initializing searchengine
	else if(workerBotMode.compare("searchengine") == 0) {
		crawler = dynamic_cast<crawler::Crawler*>(new crawler::GenericWebCrawler());
		parser  = dynamic_cast<parser::HtmlParserBase*>(new parser::GenericWebHtmlParser());
		htmlParserParam = dynamic_cast<parser::HtmlParserParam*>(new parser::GenericWebHtmlParserParam());
		indexer = dynamic_cast<indexing::Indexer*>(new indexing::GenericWebIndexer());
	}
	//initializing datamining
	else if (workerBotMode.compare("datamining") == 0) {
		crawler = dynamic_cast<crawler::Crawler*>(new crawler::DataminingCrawler());
		parser  = dynamic_cast<parser::HtmlParserBase*>(new parser::GenericWebHtmlParser());
		htmlParserParam = dynamic_cast<parser::HtmlParserParam*>(new parser::GenericWebHtmlParserParam());
		indexer = dynamic_cast<indexing::Indexer*>(new indexing::DataminingIndexer());
	}
	else {
		THROW_EXCEPTION(errors::NotImplementedException,"Invalid WorkerBot mode, use one of: commercesearch,datamining,searchengine, current mode: " + workerBotMode);
	}

	bSuccess &= InitCrawlerConfig();
	bSuccess &= InitParserConfig();
	bSuccess &= InitIndexerConfigParams();

	return bSuccess;
}

bool WorkerBot::OnRun() {

	indexerParam.databaseConfig = crawlerParam.databaseConfig = htmlParserParam->databaseConfig = dbConfig;

	database::DatabaseConnection* conn = DB().CreateConnection(dbConfig);
	if(conn) {
		htmlparser::TLD::InitTLDCache(DB().Connection());
		DB().DestroyConnection();
	}
	else {
		return false;}

	bool bSuccess = true;

	bSuccess &= crawler->StartThread(&crawlerParam);
	bSuccess &= parser ->StartThread(htmlParserParam);
	bSuccess &= indexer->StartThread(&indexerParam);

	return bSuccess;
}

bool WorkerBot::OnShutdown() {

	crawler->SetShallEnd(true);
	crawler->WaitForThread();
	delete crawler;
	crawler = NULL;

	parser->SetShallEnd(true);
	parser->WaitForThread();
	delete parser;
	delete htmlParserParam;
	parser = NULL;
	htmlParserParam = NULL;

	indexer->SetShallEnd(true);
	indexer->WaitForThread();
	delete indexer;
	indexer = NULL;

	return true;
}

void WorkerBot::RegisterDefaultParams(void)
{
	RegisterCrawlerConfigParams();
	RegisterParserConfigParams();
	RegisterIndexerConfigParams();

	std::string workerBotMode = "searchengine";
	Config().RegisterParam("worker_bot_mode", "mode of workerbot, one of: searchengine, commercesearch, datamining", true, false, &workerBotMode);

	Bot::RegisterDefaultParams();
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
	Config().RegisterParam("crawler_respectRobotsTxt", "", true, false, &respectRobotsTxt);
}

bool WorkerBot::InitCrawlerConfig()
{
	if( !Config().GetValue( "crawler_threads", crawlerParam.threadCount) )
		return false;

	if(crawlerParam.threadCount<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_threads count specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("crawler_maxUrl",crawlerParam.maxPerSelect)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_maxUrl !!!");
		return false;}
	if(crawlerParam.maxPerSelect<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_maxUrl specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("crawler_minAge",crawlerParam.minAge)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_minAge !!!");
		return false;}
	if(crawlerParam.minAge<0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid crawler_minAge specified (< 0). exiting...");
		return false;}
	if(crawlerParam.minAge==0){
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"!!! WARNING crawler_minAge == 0 specified !!!");}

	if(!Config().GetValue("crawler_userAgent",crawlerParam.userAgent)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_userAgent !!!");
		return false;}

	if(!Config().GetValue("crawler_cntTimeout",crawlerParam.connectTimeout) || crawlerParam.connectTimeout <= 0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! invalid/missing crawler_cntTimeout timeout !!!");
		return false;}

	if(!Config().GetValue("crawler_connectionTimeout",crawlerParam.connectionTimeout) || crawlerParam.connectionTimeout <= 0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! invalid/missing crawler_connectionTimeout !!!");
		return false;}

	if(!Config().GetValue("crawler_ipv6",crawlerParam.useIPv6))
		crawlerParam.useIPv6 = false;

	if(!Config().GetValue("crawler_limit", crawlerParam.speedLimitKB)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_limit !!!");
		return false;}

	if(!Config().GetValue("crawler_waitIdle",crawlerParam.waitOnIdle)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_waitIdle !!!");
		return false;}

	if(!Config().GetValue("crawler_respectRobotsTxt",crawlerParam.respectRobotsTxt)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"!!! missing crawler_respectRobotsTxt !!!");
		return false;}

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
}

bool WorkerBot::InitParserConfig()
{
	if(!htmlParserParam) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"parser parameters not initialized correctly. exiting...");
		return false;}

	if( !Config().GetValue( "parser_threads", htmlParserParam->parserThreadCount) )
		return false; //should not happen as "threads" is mandatory...

	if(htmlParserParam->parserThreadCount<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser thread count specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("parser_maxUrl",htmlParserParam->maxPerSelect))
		return false;
	if(htmlParserParam->maxPerSelect<=0){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid parser_maxUrl specified (<= 0). exiting...");
		return false;}

	if(!Config().GetValue("parser_waitIdle",htmlParserParam->waitOnIdle))
		return false;

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
	if( !Config().GetValue( "indexer_threads", indexerParam.threadCount) )
		return false;

	if( !Config().GetValue( "indexer_waitIdle", indexerParam.waitOnIdle) )
		return false;

	if( !Config().GetValue( "indexer_maxUrl", indexerParam.maxPerSelect) )
		return false;

	return true;
}

