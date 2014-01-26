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

#include <IIndexerFactory.h>
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

	//remove all broken files
	std::vector<std::string> brokenFiles;
	tools::FileTools::ListDirectory(brokenFiles, testPath, ".*?\\.broken$", true);
	if(brokenFiles.size() > 0) {
		log::Logging::LogInfo("cleaning up old *.broken files before beginning unit test");

		std::vector<std::string>::const_iterator iBroken = brokenFiles.begin();
		for(;iBroken != brokenFiles.end();++iBroken) {
			tools::FileTools::DeleteFile(testPath+"/"+*iBroken); }
	}

	if(contentFiles.size() == 0) {
		log::Logging::LogError("could not find any indexable .txt files in " + testPath);
		return false; }

	tools::SpellChecking spellCheck;
	spellCheck.InitSpellChecking("/usr/share/hunspell/en_US.dic","/usr/share/hunspell/en_US.aff");

	std::vector<std::string>::const_iterator iFile = contentFiles.begin();
	bool success = true;
	for(;iFile != contentFiles.end(); ++iFile) {
		success &= HandleSingleFile(spellCheck,*iFile);
	}

	return success;
}

bool UnitTestIndexerEx::HandleSingleFile(tools::SpellChecking& spellCheck,const std::string& fileName) {

	std::string curFileName(testPath + "/" + fileName);
	if(testPath.at(testPath.length() - 1) == '/' ) {
		curFileName = testPath + fileName; }

	tools::Pointer<indexing::IIndexer> indexer;
	if(!indexing::IIndexerFactory::CreateInstance(connection,indexing::IIndexerFactory::OWN_GENERIC,indexing::IIndexerFactory::IDX_OPT_NONE,indexer)) {
		log::Logging::LogError("error while creating indexer");
		return false; }

	if(indexer.IsNull()) {
		log::Logging::LogError("indexer is NULL _AFTER_ successful creation");
		return false; }

	indexer.Get()->GetDictionary().SetTestMode(true);

	std::string fileContent;
	if(!tools::FileTools::ReadFile(curFileName,fileContent)) {
		log::Logging::LogError("could not read " + curFileName);
		return false; }

	log::Logging::LogInfo("indexing file: " + curFileName);
	indexer.Get()->Parse(fileContent,0);

	std::string dictionaryDump;
	indexer.Get()->GetDictionary().DumpXML(dictionaryDump,spellCheck);

	 if(dictionaryDump.empty()) {
		log::Logging::LogError("empty dictionary for file " + curFileName);
		return false; }

	std::ostringstream ssOut;
	ssOut << "<dictionary file=\"" << fileName << "\" >" << std::endl
		  << dictionaryDump
		  << "</dictionary>" << std::endl;

	std::string completeXML(ssOut.str());
	/*
	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::LogTraceUnlimited(completeXML); }
	*/

	std::string tmplFileName(curFileName+".tmpl");
	if(!tools::FileTools::FileExists(tmplFileName)) {
		log::Logging::LogError("could not find template html, setting current result as template, please check it for correctness and rerun this unittest: " + tmplFileName);
		tools::FileTools::WriteFile(tmplFileName,completeXML,false); }

	std::string tmpFile(curFileName+".temp");
	tools::FileTools::DeleteFile(tmpFile);
	tools::FileTools::WriteFile(tmpFile,completeXML,false);
	bool isEqualToTemplate = tools::FileTools::CompareFiles(tmpFile,tmplFileName);
	tools::FileTools::DeleteFile(tmpFile);

	if(!isEqualToTemplate) {
		log::Logging::LogError("template and unittest output did not match, please check it for correctness and rerun this unittest: " + curFileName + ".broken");
		tools::FileTools::WriteFile(curFileName + ".broken",completeXML,false);
		return false;
	}

	return true;
}

}
