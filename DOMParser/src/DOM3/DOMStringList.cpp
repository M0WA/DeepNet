/**
 *
 * @file DOMStringList.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "DOMStringList.h"

#include <algorithm>

namespace domparser {

namespace dom3 {

DOMStringList::DOMStringList(const std::vector<domparser::dom3::DOMString>& list)
: list(list) {
	std::sort(this->list.begin(),this->list.end());
}

DOMStringList::~DOMStringList() {
}

DOMString* DOMStringList::item(const size_t& index) {
	if(index >= list.size())
		return 0;
	else
		return &(list.at(index));
}

bool DOMStringList::contains(const DOMString& str) const {
	return (std::find(list.begin(),list.end(),str) != list.end());
}

}

}
