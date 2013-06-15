/**
 *
 * @file UnitTestIndexerEx.cpp
 * @author Moritz Wagner
 * @date 15.06.2013
 *
 */

#include "UnitTestIndexerEx.h"

#include <sstream>

#include <Pointer.h>
#include <Logging.h>
#include <DatabaseLayer.h>
#include <SpellChecking.h>

#include <IndexerFactory.h>
#include <IIndexer.h>
#include <Dictionary.h>
#include <FileTools.h>

namespace toolbot {

UnitTestIndexerEx::UnitTestIndexerEx(database::DatabaseConnection* connection, const std::string& testPath)
: connection(connection)
, testPath(testPath) {
	tools::FileTools::ListDirectory(contentFiles, testPath, ".*?\\.txt$", true);
}

UnitTestIndexerEx::~UnitTestIndexerEx() {
}

bool UnitTestIndexerEx::Run() {

	if(contentFiles.size() == 0) {
		log::Logging::LogError("could not find any indexable .txt files in " + testPath);
		return false; }

	tools::SpellChecking spellCheck;
	spellCheck.InitSpellChecking("/usr/share/hunspell/en_US.dic","/usr/share/hunspell/en_US.aff");

	std::ostringstream ssOut;

	std::vector<std::string>::const_iterator iFile = contentFiles.begin();
	bool success = true;
	for(;iFile != contentFiles.end(); ++iFile) {

		tools::Pointer<indexing::IIndexer> indexer;
		if(!indexing::IndexerFactory::CreateInstance(connection,indexing::IndexerFactory::OWN_GENERIC,indexer)) {
			log::Logging::LogError("error while creating indexer");
			return false; }

		if(indexer.IsNull()) {
			log::Logging::LogError("indexer is NULL _AFTER_ successful creation");
			return false; }

		std::string fileContent;
		if(!tools::FileTools::ReadFile(*iFile,fileContent)) {
			log::Logging::LogError("could not read " + *iFile + ", continuing but unit test will fail");
			success = false;
			continue; }

		indexer.Get()->Parse(fileContent,0);

		std::string dictionaryDump;
		indexer.Get()->GetDictionary().DumpXML(dictionaryDump,spellCheck);

		ssOut << "<dictionary file=\"" << *iFile << "\" >" << std::endl
			  << dictionaryDump << std::endl
			  << "</dictionary>" << std::endl;
	}

	std::string completeXML = ssOut.str();
	if(!completeXML.empty()) {
		log::Logging::LogTraceUnlimited(completeXML); }
	else {
		log::Logging::LogError("empty dictionary for all unit tests");
		return false; }

	return success;
}

}
