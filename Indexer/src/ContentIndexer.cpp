/*
 * ContentIndexer.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include "ContentIndexer.h"
#include <string.h>

#include "Dictionary.h"

namespace indexing
{
	class IndexerBase;
}

#include "../generated/content_parser.tab.hpp"

namespace indexing {

ContentIndexer::ContentIndexer(database::DatabaseConnection* database,const IndexerBase::IndexerType type)
: IndexerBase(database,type)
, posWord(0)
{
	ctx = new ContentIndexerCtx(this);
}

ContentIndexer::~ContentIndexer()
{
	delete ctx;
	ctx = 0;
}

void ContentIndexer::OnWord(std::string* word)
{
	tmpWord += *word;
	//TODO:memory leak here, should be double free
	//because its deleted by parser
	delete word;
}

void ContentIndexer::OnHtmlEntity(std::string* entity)
{
	tmpWord += *entity;
	//TODO:memory leak here, should be double free
	//because its deleted by parser
	delete entity;
}

void ContentIndexer::OnCharacterReference(std::string* characterReference)
{
	tmpWord += *characterReference;
	//TODO:memory leak here, should be double free
	//because its deleted by parser
	delete characterReference;
}

void ContentIndexer::TerminateWord(void)
{
	++posWord;
	if( !tmpWord.empty() && tmpWord.length() > 2 ) {
		GetDictionary().Add(tmpWord,std::pair<long long, long long>(paragraph,posWord)); }
	tmpWord.clear();
}

void ContentIndexer::OnParse(const long long paragraph)
{
	this->paragraph = paragraph;
	posWord = 0;
	ContentIndexerHelper::ParseFromContext(reinterpret_cast<ContentIndexerCtx*>(ctx));
	TerminateWord();
}

}
