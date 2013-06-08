/**
 *
 * @file DOMTokenList.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "DOMTypes.h"

#include <vector>
#include <algorithm>

namespace domparser {

/**
 * @brief implementation of a not modifiable list
 */
class DOMTokenList {
public:
	DOMTokenList();
	virtual ~DOMTokenList();

	/**
	 * get the number of items in the list
	 * @return number of items in list
	 */
	unsigned long GetLength() const {
		return tokens.size(); }

	/**
	 * gets specified item by it's index
	 * @param index item index
	 * @return content of the item or empty string
	 */
	const DOMStringPtr item(unsigned long index) const {
		if(index > tokens.size() - 1) {
			return DOMStringPtr();
		}
		return DOMStringPtr(tokens.at(index));
	}

	/**
	 * checks if a certain item is in this list
	 * @param token item to look for
	 * @return true if in list, false if not in list
	 */
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
