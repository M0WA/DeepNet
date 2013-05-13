/**
 *
 * @file NamedCharacterReferences.h
 * @author Moritz Wagner
 * @date Mar 2, 2013
 *
 */

#pragma once

#include <stddef.h>

namespace htmlparser {

/**
 * wrapper class for named character references.
 * For more inforamtion please consult DOM5 specification
 * found at the W3C homepage
 */
class NamedCharacterReferences {
private:
	NamedCharacterReferences();

public:
	virtual ~NamedCharacterReferences();

	/**
	 * checks if string is a valid character reference
	 * @param p string to check if it is a character reference
	 * @param size max. allowd size for character reference
	 * @param isPossibleRef true if it might be a reference but it may be too short
	 * @param isCompleteRef true if the string is a character reference
	 * @return 0 if not a character reference, otherwise the size of (possible) character reference
	 */
	static size_t IsRef(const char* p,const size_t size, bool& isPossibleRef, bool& isCompleteRef);

private:
	/**
	 * initializes cache for named character references.
	 * this function needs to called ONCE before the HTML
	 * parser is used and normally the parser does this on its
	 * own.
	 */
	static void InitStaticNamedCharRefs();
};

}
