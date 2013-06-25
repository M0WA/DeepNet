/**
 *
 * @file DOMError.cpp
 * @author Moritz Wagner
 * @date 25.06.2013
 *
 */

#include "DOMError.h"

namespace domparser {

namespace dom3 {

DOMError::DOMError(const std::string& name)
: entry(ErrorNamesTable::GetEntryByName(name)){
}

DOMError::~DOMError() {
}

}

}
