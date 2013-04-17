/**
 *
 * @file DOMTokenList.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"

#include <vector>
#include <algorithm>

namespace htmlparser {

class DOMTokenList {
public:
	DOMTokenList();
	virtual ~DOMTokenList();

	unsigned long GetLength() const {
		return tokens.size(); }

	const DOMStringPtr item(unsigned long index) const {
		if(index > tokens.size() - 1) {
			return DOMStringPtr();
		}
		return DOMStringPtr(tokens.at(index));
	}

	bool contains(const DOMString& token) const {
		return std::find(tokens.begin(),tokens.end(), token) != tokens.end();
	}

	/*
	  void add(DOMString... tokens);
	  void remove(DOMString... tokens);
	  boolean toggle(DOMString token, optional boolean force);
	*/

private:
	std::vector<DOMString> tokens;
};

}
