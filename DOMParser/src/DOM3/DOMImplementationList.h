/**
 *
 * @file DOMImplementationList.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include <vector>
#include <stddef.h>

namespace domparser {

namespace dom3 {

class DOMImplementation;
class DOMImplementationList {
public:
	DOMImplementationList();
	DOMImplementationList(domparser::dom3::DOMImplementation* singleImplementation);
	DOMImplementationList(const std::vector<domparser::dom3::DOMImplementation*>& implementations);
	DOMImplementationList(const DOMImplementationList& implList);
	virtual ~DOMImplementationList();

public:
	DOMImplementationList& operator= (const DOMImplementationList& implList);

public:
	//DOM3 interface
	domparser::dom3::DOMImplementation* item(const size_t& index);
	const size_t length() const;

private:
	void Release();

private:
	std::vector<domparser::dom3::DOMImplementation*> implementations;
};

}

}
