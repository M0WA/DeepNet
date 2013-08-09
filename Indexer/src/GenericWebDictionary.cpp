/*
 * GenericWebDictionary.cpp
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebDictionary.h"
#include <DatabaseLayer.h>

#include <Logging.h>

#include <TableDefinition.h>
#include <TableColumnDefinition.h>

#include <DatabaseColumnDatasizeExceededException.h>

namespace indexing {

GenericWebDictionary::GenericWebDictionary(database::DatabaseConnection* database)
: Dictionary(database){
}

GenericWebDictionary::~GenericWebDictionary() {
}

bool GenericWebDictionary::CommitContent(void)
{
	if( testMode || !wordContent.size() )
		return true;

	std::set<Word>::const_iterator iterWords(wordContent.begin());
	long long occurrences(0);

	for(int i(0); iterWords != wordContent.end(); i++, ++iterWords) {

		const Word& wordRef(*iterWords);
		occurrences = wordRef.GetOccurrences();

		const std::string& word(wordRef.GetString());

		database::dictTableBase dictKeyword;
		try {
			dictKeyword.Set_keyword(word);
		}
		catch(database::DatabaseColumnDatasizeExceededException& ex) {
			ex.DisableLogging();
			log::Logging::LogWarn("omitting keyword exceeding which is exceeding max size");
			continue; }

		dictKeyword.Set_occurrence(occurrences);

		std::vector<database::TableColumnDefinition*> colDefsSum;
		colDefsSum.push_back(database::dictTableBase::GetDefinition_occurrence());

		database->TransactionStart();

		long long dictID(-1);
		try {
			dictKeyword.InsertOrUpdate(database,colDefsSum);
			database->LastInsertID(dictID);
		}
		catch(...) {
			database->TransactionRollback();
			throw;
		}

		if(dictID<0){
			log::Logging::LogWarn("error while getting ID for word in dictionary: %s",word.c_str());
			database->TransactionRollback();
			continue; }

		database::dockeyTableBase docKey;
		docKey.Set_DICT_ID(dictID);
		docKey.Set_URLSTAGE_ID(urlStageID);
		docKey.Set_occurrence(occurrences);

		colDefsSum.clear();
		colDefsSum.push_back(database::dockeyTableBase::GetDefinition_occurrence());

		long long docKeyID(-1);
		try {
			docKey.InsertOrUpdate(database,colDefsSum);
			database->LastInsertID(docKeyID);
		}
		catch(...) {
			database->TransactionRollback();
			throw;
		}

		const std::vector<std::pair<long long, long long> >& wordPositions(wordRef.GetPositions());
		std::vector<std::pair<long long, long long> >::const_iterator iterPos(wordPositions.begin());
		for(;iterPos != wordPositions.end();++iterPos) {
			database::dockeyposTableBase tblPos;
			tblPos.Set_DOCKEY_ID(docKeyID);
			tblPos.Set_paragraph(iterPos->first);
			tblPos.Set_position(iterPos->second);

			try {
				tblPos.Insert(database);
			}
			catch(...) {
				database->TransactionRollback();
				throw;
			}
		}

		database->TransactionCommit();
	}

	wordContent.clear();
	return true;
}

bool GenericWebDictionary::CommitMeta(void)
{
	if( testMode || !wordMeta.size() )
		return true;

	std::map<Dictionary::MetaInformationType,std::set<Word> >::const_iterator iterTypes = wordMeta.begin();

	long long occurrences(0);
	for(;iterTypes != wordMeta.end();++iterTypes) {
		const std::set<Word>& refWords(iterTypes->second);
		std::set<Word>::const_iterator iterWords(refWords.begin());
		for(;iterWords != refWords.end(); ++iterWords) {

			occurrences = iterWords->GetOccurrences();

			const std::string& word(iterWords->GetString());

			database::dictTableBase dictKeyword;
			try {
				dictKeyword.Set_keyword(word);
			}
			catch(database::DatabaseColumnDatasizeExceededException& ex) {
				ex.DisableLogging();
				log::Logging::LogWarn("omitting meta keyword exceeding which is exceeding max size");
				continue; }

			dictKeyword.Set_occurrence(occurrences);

			std::vector<database::TableColumnDefinition*> colDefsSum;
			colDefsSum.push_back(database::dictTableBase::GetDefinition_occurrence());

			database->TransactionStart();

			long long dictID(-1);
			try {
				dictKeyword.InsertOrUpdate(database,colDefsSum);
				database->LastInsertID(dictID);
			}
			catch(...) {
				database->TransactionRollback();
				throw;
			}

			if(dictID<0){
				log::Logging::LogWarn("error while getting ID for word in dictionary: %s",word.c_str());
				database->TransactionRollback();
				continue; }

			database::docmetaTableBase docMeta;
			docMeta.Set_DICT_ID(dictID);
			docMeta.Set_URLSTAGE_ID(urlStageID);
			docMeta.Set_occurrence(occurrences);
			docMeta.Set_type(iterTypes->first);

			colDefsSum.clear();
			colDefsSum.push_back(database::docmetaTableBase::GetDefinition_occurrence());

			try {
				docMeta.InsertOrUpdate(database,colDefsSum);
			}
			catch(...) {
				database->TransactionRollback();
				throw;
			}

			database->TransactionCommit();
		}
	}

	wordMeta.clear();
	return true;
}
}
