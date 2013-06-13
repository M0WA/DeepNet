/*
 * IndexerTester.cpp
 *
 *  Created on: 22.04.2012
 *      Author: Moritz Wagner
 */

#include "IndexerTester.h"

#include "IndexerBase.h"
#include "IIndexer.h"
#include "IndexerFactory.h"
#include "Dictionary.h"

#include <StringTools.h>
#include <Logging.h>

namespace indexing {

IndexerTester::IndexerTester() {

}

IndexerTester::~IndexerTester() {
}

bool IndexerTester::Parse(database::DatabaseConnection* database, const std::string& content)
{
	tools::Pointer<IIndexer> indexer;
	IndexerFactory::CreateInstance(database,IndexerFactory::FLEX_GENERIC,indexer);
	indexer.Get()->GetDictionary().SetTestMode(true);
	indexer.Get()->Parse( content,-1 );

	std::string dictDump;
	indexer.Get()->GetDictionary().Dump(dictDump);

	log::Logging::Log(log::Logging::LOGLEVEL_INFO,"dumping dictionary:\n%s",dictDump.c_str());
	return true;
}

}
