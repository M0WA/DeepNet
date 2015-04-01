/**
 *
 * @file DOM3/DOMImplementationSource.h
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#pragma once

#include "DOMImplementationList.h"

namespace domparser {

namespace dom3 {

class DOMString;
class DOMImplementation;

class DOMImplementationSource {
public:
	DOMImplementationSource();
	virtual ~DOMImplementationSource();

public:
	//DOM3 interface
	domparser::dom3::DOMImplementation* getDOMImplementation(const domparser::dom3::DOMString& features);
	domparser::dom3::DOMImplementationList getDOMImplementationList(const domparser::dom3::DOMString& features);

private:
	domparser::dom3::DOMImplementationList implList;
};

}

}
