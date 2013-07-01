/**
 *
 * @file IIndexer.h
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#pragma once

#include <string>

#include "Dictionary.h"

namespace indexing {

/**
 * @brief interface class for indexers
 */
class IIndexer {

public:
	virtual ~IIndexer() {}

public:
	/**
	 * parses a text
	 * @param input text to parse
	 * @param paragraph paragraph of this text
	 */
	virtual void Parse(const std::string& input, const long long paragraph) = 0;

	/**
	 * parses content part of a meta type
	 * @param input content part to parse
	 * @param type meta type to set
	 */
	virtual void ParseMeta(const std::string& input, const Dictionary::MetaInformationType& type) = 0;

	/**
	 * gets dictionary of this indexer
	 * @return instance of this indexers dictionary
	 */
	virtual Dictionary& GetDictionary() = 0;
};

}


