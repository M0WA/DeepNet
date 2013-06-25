/**
 *
 * @file DOMError.h
 * @author Moritz Wagner
 * @date 25.06.2013
 *
 */

#pragma once

#include <string>

#include "ErrorNamesTable.h"

namespace domparser {

namespace dom3 {

class DOMError {

public:
	DOMError(const std::string& name);
	virtual ~DOMError();

public:
	//DOM3 interface
	const std::string& name() const { return entry.name; }

private:
	ErrorNamesTable::ErrorNamesTableEntry entry;
};

}

}
