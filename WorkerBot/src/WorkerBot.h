/**
 * @file WorkerBot.h
 * @author Moritz Wagner
 * @date 06.03.2012
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

/**
 * @brief implementation of the worker bot which is the main application
 * of the whole DeepNet infrastructure.
 */
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

	void RegisterModeSpecificParams();
	bool InitModeConfig();

private:
	tools::Pointer<crawler::Crawler> crawler;
	tools::Pointer<crawler::CrawlerParam> crawlerParam;

	tools::Pointer<parser::HtmlParserBase> parser;
	tools::Pointer<parser::HtmlParserParam> parserParam;

	tools::Pointer<indexing::Indexer> indexer;
	tools::Pointer<indexing::IndexerParam> indexerParam;
};
