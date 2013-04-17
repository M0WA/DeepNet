/*
 * KeywordEntry.h
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "Relevance.h"

namespace queryserver {

class KeywordEntry : public Relevance
{
public:
	enum KeywordEntryType
	{
		UNKNOWN_KEYWORD_TYPE = 0,

		TITLE_KEYWORD_TYPE,
		META_KEYWORD_TYPE,
		URL_KEYWORD_TYPE,
		DOMAIN_KEYWORD_TYPE,
		CONTENT_KEYWORD_TYPE,
	};

public:
	KeywordEntry(const KeywordEntryType& type, const double& relevanceIn, const double& weightIn, const std::string& keywordIn, const long long& dictIDIn, const long long& occurrenceIn)
	: Relevance(relevanceIn,KeywordEntry::GetWeightByOccurrence(weightIn, occurrenceIn))
	, type(type)
	, keyword(keywordIn)
	, dictID(dictIDIn)
	, occurrence(occurrenceIn)
	{ }

public:
	const KeywordEntryType& GetType()    const { return type;    }
	const std::string&      GetKeyword() const { return keyword; }
	const long long& DictionaryID() const { return dictID;     }
	const long long& Occurrence()   const { return occurrence; }

private:
	static const double GetWeightByOccurrence(const double& weight, const long long& occurrence) {
		//TODO: make occurrence have an influence on relevance
		return weight;
	}

private:
	KeywordEntryType type;
	std::string keyword;
	long long dictID;
	long long occurrence;
};

class KeywordEntryTypeConverter
{
private:
	KeywordEntryTypeConverter() {}

public:
	static std::string ToString(const KeywordEntry::KeywordEntryType& in)
	{
		switch(in)
		{
		case KeywordEntry::TITLE_KEYWORD_TYPE:
			return "meta";
		case KeywordEntry::META_KEYWORD_TYPE:
			return "meta";
		case KeywordEntry::URL_KEYWORD_TYPE:
			return "url";
		case KeywordEntry::DOMAIN_KEYWORD_TYPE:
			return "domain";
		case KeywordEntry::CONTENT_KEYWORD_TYPE:
			return "content";

		default:
			return "";
		}
	}
};

}
