/*
 * Dictionary.cpp
 *
 *  Created on: 11.03.2012
 *      Author: Moritz Wagner
 */

#include "Dictionary.h"

#include <cstring>
#include <sstream>
#include <Logging.h>
#include <HttpUrlParser.h>
#include <DatabaseLayer.h>
#include <StringTools.h>
#include <SpellChecking.h>

namespace indexing
{

Dictionary::Dictionary(database::DatabaseConnection* database)
: limit(-1)
, database(database)
, urlID(-1)
, urlStageID(-1)
, testMode(false)
{
}

Dictionary::~Dictionary()
{
}

/*
void Dictionary::Merge(const Dictionary& dic1,const Dictionary& dic2, Dictionary& merged)
{
	merged = dic1;
	std::set<Word>::const_iterator iterWords = dic2.words.begin();
	for(;iterWords != dic2.words.end();iterWords++) {
		std::pair<std::set<Word>::iterator,bool> insertPair = merged.words.insert(*iterWords);
		if(!insertPair.second) {
			//add up occurrences when not inserted
			insertPair.first->IncrementOccurances(iterWords->GetOccurances());
		}
	}
}
*/
bool Dictionary::Add(const std::string& word, const std::pair<long long,long long>& paragraphPosition)
{
	if(!testMode && urlID < 0) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"dictionary url id not set");
		return false; }

	std::pair<std::set<Word>::iterator,bool> insertPair = words.insert(Word(word));
	if(!insertPair.second) {
		//was already there -> increment occurrences
		insertPair.first->IncrementOccurrences();
		insertPair.first->AddPosition(paragraphPosition);
	}

	//only return true when a new word was inserted
	return insertPair.second;
}

bool Dictionary::Add(const std::string& word)
{
	if(!testMode && urlID < 0) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"dictionary url id not set");
		return false; }

	std::pair<std::set<Word>::iterator,bool> insertPair = words.insert(Word(word));
	if(!insertPair.second) {
		//was already there -> increment occurrences
		insertPair.first->IncrementOccurrences();
	}

	//only return true when a new word was inserted
	return insertPair.second;
}

void Dictionary::SetUrlID(const long long urlID, const long long urlStageID)
{
	words.clear();
	this->urlID = urlID;
	this->urlStageID = urlStageID;
}

void Dictionary::Dump(std::string& dictDump) const
{
	std::set<Word>::const_iterator iterWords = words.begin();
	std::stringstream dump;
	for(int i = 0; iterWords != words.end(); i++, ++iterWords) {
		dump << iterWords->GetString() << "\t" << iterWords->GetOccurrences() << std::endl;
	}
	dictDump = dump.str();
}

void Dictionary::DumpXML(std::string& dictDump, tools::SpellChecking& spellChecker) const
{
	std::set<Word>::const_iterator iterWords = words.begin();
	std::stringstream dump;
	for(int i = 0; iterWords != words.end(); i++, ++iterWords) {
		const char* curWord = iterWords->GetChars();
		std::vector<std::string> proposals;
		bool spelledCorrectly = true;
		spellChecker.GenerateProposals(curWord,spelledCorrectly,proposals);

		std::vector<std::string>::iterator iterProp = proposals.begin();
		for(;iterProp != proposals.end();++iterProp) {
			network::HttpUrlParser::EncodeUrl(*iterProp);}

		std::string dumpVec;
		tools::StringTools::VectorToString(proposals,"<proposal>","</proposal>",dumpVec);

		std::string encodedWord = curWord;
		network::HttpUrlParser::EncodeUrl(encodedWord);
		dump <<
		"<keyword id=\"" << i << "\">"
			"<word>"
				<< encodedWord <<
			"</word>"
			"<occurrence>"
				<< iterWords->GetOccurrences() <<
			"</occurrence>"
			"<spell>"
				<< spelledCorrectly <<
			"</spell>"
			"<proposals>"
				<< dumpVec <<
			"</proposals>"
		"</keyword>" << std::endl;
	}
	dictDump = dump.str();
}

}
