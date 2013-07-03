/**
 *
 * @file DOM3/DOMImplementationSource.cpp
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#include "DOMImplementationSource.h"

#include "DOMImplementationImpl.h"
#include "DOMImplementation.h"
#include "DOMString.h"

namespace domparser {

namespace dom3 {

DOMImplementationSource::DOMImplementationSource()
: implList(new DOMImplementationImpl())
{
}

DOMImplementationSource::~DOMImplementationSource() {
}

domparser::dom3::DOMImplementation* DOMImplementationSource::getDOMImplementation(const domparser::dom3::DOMString& features) {
	return implList.item(0);
}

domparser::dom3::DOMImplementationList DOMImplementationSource::getDOMImplementationList(const domparser::dom3::DOMString& features) {
	return implList;
}

}

}
