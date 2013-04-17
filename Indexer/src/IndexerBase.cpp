/*
 * IndexerBase.cpp
 *
 * !!! ATTENTION: this is NOT the base for class Indexer
 *                as the name might suggest.
 *                It is used as a base class for the current
 *                Indexer used to lex and parse a certain piece
 *                of content.
 *
 *  Created on: 11.03.2012
 *      Author: Moritz Wagner
 */

#include "IndexerBase.h"

namespace indexing
{

IndexerBase::IndexerBase(database::DatabaseConnection* database,const IndexerType type)
: type(type)
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

int IndexerBase::Read(char* buf,int maxSize)
{
	std::string::iterator const content_end(content.end());
	int pos = 0;
	for(;pos < maxSize && contentIter != content_end; pos++, ++contentIter) {
		buf[pos] = *contentIter;}
	return pos;
}

}
