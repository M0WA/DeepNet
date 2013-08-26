/*
 * Dictionary.h
 *
 *  Created on: 11.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Word.h"

#include <string>
#include <set>
#include <map>

namespace tools {
	class SpellChecking;
}

namespace database {
	class DatabaseConnection;
}

namespace indexing
{

class Dictionary {

public:
	typedef enum {

		META_UNKNOWN = 0,

		META_TITLE = 1,
		META_DESCRIPTION = 2,
		META_KEYWORDS = 3,
		META_AUTHOR = 4,
		META_COPYRIGHT = 5,

		META_TYPE_MAX, //do not use this

	} MetaInformationType;

public:
	Dictionary(database::DatabaseConnection* database);
	virtual ~Dictionary();

public:
	virtual bool CommitMeta(void)=0;
	virtual bool CommitContent(void)=0;

public:
	bool AddContent(const std::string& word, const std::pair<long long,long long>& paragraphPosition);
	//bool AddContent(const std::string& word);

	bool AddMeta(const std::string& word, const MetaInformationType& type);

	void SetUrlID(const long long urlID, const long long urlStageID);

	void SetTestMode(const bool testMode) { this->testMode = testMode; }
	void Dump(std::string& dictDump) const;
	void DumpXML(std::string& dictDump, tools::SpellChecking& spellChecker) const;
	size_t ContentSize(void) const { return wordContent.size(); }
	size_t MetaSize(void) const { return wordMeta.size(); }

protected:
	int limit;
	database::DatabaseConnection* database;
	std::set<Word> wordContent;
	std::map<MetaInformationType,std::set<Word> > wordMeta;

	long long urlID;
	long long urlStageID;

	bool testMode;
};

}
