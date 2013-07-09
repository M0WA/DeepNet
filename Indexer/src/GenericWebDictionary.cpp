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

	std::set<Word>::iterator iterWords = wordContent.begin();
	long long occurrences = 0;

	for(int i = 0; iterWords != wordContent.end(); i++, ++iterWords) {

		const Word& wordRef = *iterWords;
		occurrences = wordRef.GetOccurrences();

		const std::string& word = wordRef.GetString();

		database::dictTableBase dictKeyword;
		dictKeyword.Set_keyword(word);
		dictKeyword.Set_occurrence(occurrences);

		std::vector<database::TableColumnDefinition*> colDefsSum;
		colDefsSum.push_back(database::dictTableBase::GetDefinition_occurrence());

		database->TransactionStart();

		try {
			dictKeyword.InsertOrUpdate(database,colDefsSum);
		}
		catch(...) {
			database->TransactionRollback();
			throw;
		}

		long long dictID = -1;
		if(!database->LastInsertID(dictID) || dictID<0){
			log::Logging::LogWarn("error while getting ID for word in dictionary: %s",word.c_str());
			database->TransactionRollback();
			continue; }

		database::dockeyTableBase docKey;
		docKey.Set_DICT_ID(dictID);
		docKey.Set_URLSTAGE_ID(urlStageID);
		docKey.Set_occurrence(occurrences);

		colDefsSum.clear();
		colDefsSum.push_back(database::dockeyTableBase::GetDefinition_occurrence());

		try {
			docKey.InsertOrUpdate(database,colDefsSum);
		}
		catch(...) {
			database->TransactionRollback();
			throw;
		}

		long long docKeyID = -1;
		database->LastInsertID(docKeyID);

		const std::vector<std::pair<long long, long long> >& wordPositions = wordRef.GetPositions();
		std::vector<std::pair<long long, long long> >::const_iterator iterPos = wordPositions.begin();
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

	long long occurrences = 0;
	for(;iterTypes != wordMeta.end();++iterTypes) {
		const std::set<Word>& refWords(iterTypes->second);
		std::set<Word>::const_iterator iterWords = refWords.begin();
		for(;iterWords != refWords.end(); ++iterWords) {

			occurrences = iterWords->GetOccurrences();

			const std::string& word = iterWords->GetString();

			database::dictTableBase dictKeyword;
			dictKeyword.Set_keyword(word);
			dictKeyword.Set_occurrence(occurrences);

			std::vector<database::TableColumnDefinition*> colDefsSum;
			colDefsSum.push_back(database::dictTableBase::GetDefinition_occurrence());

			database->TransactionStart();

			try {
				dictKeyword.InsertOrUpdate(database,colDefsSum);
			}
			catch(...) {
				database->TransactionRollback();
				throw;
			}

			long long dictID = -1;
			if(!database->LastInsertID(dictID) || dictID<0){
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
