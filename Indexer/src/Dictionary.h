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
	Dictionary(database::DatabaseConnection* database);
	virtual ~Dictionary();

public:
	virtual bool CommitMeta(void)=0;
	virtual bool CommitContent(void)=0;

public:
	bool Add(const std::string& word, const std::pair<long long,long long>& paragraphPosition);
	bool Add(const std::string& word);
	void SetUrlID(const long long urlID, const long long urlStageID);

	void SetTestMode(const bool testMode) { this->testMode = testMode; }
	void Dump(std::string& dictDump) const;
	void DumpXML(std::string& dictDump, tools::SpellChecking& spellChecker) const;
	int  Size(void) const { return words.size(); }
/*
public:
	static void Merge(const Dictionary& dic1,const Dictionary& dic2, Dictionary& merged);
*/

protected:
	int limit;
	database::DatabaseConnection* database;
	std::set<Word> words;

	long long urlID;
	long long urlStageID;

	bool testMode;
};

}
