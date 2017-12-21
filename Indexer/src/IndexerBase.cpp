/**
 *
 * @file IndexerBase.cpp
 * @author Moritz Wagner
 * @date 11.03.2012
 *
 * !!! ATTENTION: this is NOT the base for class Indexer
 *                as the name might suggest.
 *                It is used as a base class for the current
 *                Indexer used to lex and parse a certain piece
 *                of content.
 *
 */

#include "IndexerBase.h"

namespace indexing
{

IndexerBase::IndexerBase(database::DatabaseConnection* database,const IndexerType type)
: ctx(0)
, type(type)
{

}

IndexerBase::~IndexerBase()
{
	delete ctx;
	ctx = 0;
}

void IndexerBase::Parse(const std::string& input, const long long paragraph)
{
	content     = input;
	contentIter = content.begin();

	OnParse(paragraph);
}

void IndexerBase::ParseMeta(const std::string& input, const Dictionary::MetaInformationType& type) {
	OnParseMeta(type);
}

int IndexerBase::Read(char* buf,int maxSize)
{
	std::string::iterator const content_end(content.end());
	int pos = 0;
	for(;pos < maxSize && contentIter != content_end; pos++, ++contentIter) {
		buf[pos] = *contentIter;}
	return pos;
}

}
