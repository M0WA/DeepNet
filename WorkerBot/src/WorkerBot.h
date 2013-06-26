/*
 * WorkerBot.h
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Bot.h>
#include <Crawler.h>
#include <Indexer.h>

namespace parser {
	class HtmlParserBase;
	class HtmlParserParam;
}

class WorkerBot : public bot::Bot {
public:
	WorkerBot();
	virtual ~WorkerBot();

protected:
	virtual bool OnPreInit();
	virtual bool OnInit();
	virtual bool OnPostInit();
	virtual bool OnRun();
	virtual bool OnShutdown();

private:
	void RegisterCrawlerConfigParams();
	bool InitCrawlerConfig();

	void RegisterParserConfigParams();
	bool InitParserConfig();

	void RegisterIndexerConfigParams();
	bool InitIndexerConfigParams();

private:
	crawler::Crawler* crawler;
	crawler::Crawler::CrawlerParam crawlerParam;

	parser::HtmlParserBase* parser;
	parser::HtmlParserParam* htmlParserParam;

	indexing::Indexer* indexer;
	indexing::Indexer::IndexerParam indexerParam;
};
