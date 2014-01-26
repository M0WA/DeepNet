/**
 *
 * @file IndexerBase.h
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

#pragma once

#include <string>
#include <map>
#include <istream>
#include <iostream>

#include "IIndexer.h"

namespace indexing {
	class IndexerBase;
}

namespace database {
	class DatabaseConnection;
}

/**
 * @struct IndexerCtx
 * context for indexing::IndexerBase
 * @see indexing::IndexerBase
 */
struct IndexerCtx {

	IndexerCtx()
	: indexerBase(0)
	, memoryScanner(0)
	, instream(&std::cin)
	{}

	IndexerCtx(indexing::IndexerBase* indexerBase)
	: indexerBase(indexerBase)
	, memoryScanner(0)
	, instream(&std::cin)
	{}

	indexing::IndexerBase* indexerBase;
	void* memoryScanner;
	std::istream* instream;

};

namespace indexing
{
class IndexerBase : public indexing::IIndexer
{
public:
	enum WordLen {
		SHORT,
		MEDIUM,
		LONG,
	};

	enum IndexerType {
		META_CONTENT,
		BODY_CONTENT,
		URL_CONTENT,
	};

protected:
	IndexerBase(database::DatabaseConnection* database,const IndexerType type);

public:
	virtual ~IndexerBase();

public:
	virtual void Parse(const std::string& input, const long long paragraph);
	virtual void ParseMeta(const std::string& input, const Dictionary::MetaInformationType& type);
	int Read(char* buf,int maxSize);

private:
	virtual void OnParse(const long long paragraph)=0;

	//TODO: implement meta parsing
	virtual void OnParseMeta(const Dictionary::MetaInformationType& type) {};

private:
	IndexerType type;

public:
	IndexerCtx* ctx;

	std::string content;
	std::string::iterator contentIter;
};

}
