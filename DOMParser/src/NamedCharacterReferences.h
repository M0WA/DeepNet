/**
 *
 * @file NamedCharacterReferences.h
 * @author Moritz Wagner
 * @date 02.03.2013
 *
 */

#pragma once

#include <stddef.h>

namespace domparser {

/**
 * container to deal with named html character references
 */
class NamedCharacterReferences {
private:
	NamedCharacterReferences();

public:
	virtual ~NamedCharacterReferences();

public:
	/**
	 * initialize static cache of named character references,
	 * this function should be called once per runtime and also
	 * prior to any usage of this class
	 */
	static void InitStaticNamedCharRefs();

	/**
	 * checks if p is a named character reference
	 * @param p string to check
	 * @param size number of characters to check in p
	 * @param isPossibleRef true if input MAY BE a character reference, but if so it is not complete
	 * @param isCompleteRef true if input is a complete reference
	 */
	static size_t IsRef(const char* p,const size_t size, bool& isPossibleRef, bool& isCompleteRef);
};

}
