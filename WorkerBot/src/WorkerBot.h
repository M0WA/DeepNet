/*
 * WorkerBot.h
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Bot.h>
#include <Pointer.h>

namespace crawler {
	class Crawler;
	class CrawlerParam;
}

namespace parser {
	class HtmlParserBase;
	class HtmlParserParam;
}

namespace indexing {
	class Indexer;
	class IndexerParam;
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
	tools::Pointer<crawler::Crawler> crawler;
	tools::Pointer<crawler::CrawlerParam> crawlerParam;

	tools::Pointer<parser::HtmlParserBase> parser;
	tools::Pointer<parser::HtmlParserParam> parserParam;

	tools::Pointer<indexing::Indexer> indexer;
	tools::Pointer<indexing::IndexerParam> indexerParam;
};
