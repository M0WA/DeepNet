/**
 *
 * @file IIndexer.h
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#pragma once

#include <string>

namespace indexing {

class Dictionary;
class IIndexer {

public:
	virtual ~IIndexer() {}

public:
	virtual void Parse(const std::string& input, const long long paragraph) = 0;
	virtual Dictionary& GetDictionary() = 0;
};

}


