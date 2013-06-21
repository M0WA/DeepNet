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
	const domparser::dom3::DOMString* item(const size_t& index) const;
	const size_t length() const { return list.size(); }
	bool contains(const domparser::dom3::DOMString& str) const;

private:
	std::vector<domparser::dom3::DOMString> list;
};

}

}
