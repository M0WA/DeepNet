/*
 * IndexerTester.cpp
 *
 *  Created on: 22.04.2012
 *      Author: Moritz Wagner
 */

#include "IndexerTester.h"

#include "IndexerBase.h"
#include "GenericWebContentIndexer.h"

#include <StringTools.h>
#include <Logging.h>

namespace indexing {

IndexerTester::IndexerTester() {

}

IndexerTester::~IndexerTester() {
}

bool IndexerTester::Parse(database::DatabaseConnection* database, const std::string& content)
{
	indexing::ContentIndexer* indexer = new indexing::GenericWebContentIndexer(database, indexing::IndexerBase::BODY_CONTENT);
	indexer->GetDictionary().SetTestMode(true);
	indexer->Parse( content,-1 );

	std::string dictDump;
	indexer->GetDictionary().Dump(dictDump);
	delete indexer;

	log::Logging::Log(log::Logging::LOGLEVEL_INFO,"dumping dictionary:\n%s",dictDump.c_str());
	return true;
}

}
