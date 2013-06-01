/**
 *
 * @file NamedCharacterReferences.h
 * @author Moritz Wagner
 * @date Mar 2, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <stddef.h>

namespace domparser {

class NamedCharacterReferences {
private:
	NamedCharacterReferences();

public:
	virtual ~NamedCharacterReferences();

public:
	static void InitStaticNamedCharRefs();
	static size_t IsRef(const char* p,const size_t size, bool& isPossibleRef, bool& isCompleteRef);
};

}
