/**
 *
 * @file DOMStringList.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include <vector>

#include "DOMString.h"

namespace domparser {

namespace dom3 {

class DOMStringList {
public:
	DOMStringList(const std::vector<domparser::dom3::DOMString>& list);
	virtual ~DOMStringList();

public:
	//DOM3 interface
	DOMString* item(const size_t& index);
	const size_t length() const { return list.size(); }
	bool contains(const DOMString& str);

private:
	std::vector<domparser::dom3::DOMString> list;
};

}

}
