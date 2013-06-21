/**
 *
 * @file NameList.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "NameList.h"

#include <algorithm>

namespace domparser {

namespace dom3 {

NameList::NameListPair::NameListPair(const domparser::dom3::DOMString& name, const domparser::dom3::DOMString* const ptrNamespaceURI)
{
	pair.first = name;

	if(ptrNamespaceURI)
		pair.second = tools::Pointer<domparser::dom3::DOMString>(*ptrNamespaceURI);
	else
		pair.second.Set(0,true);
}

bool NameList::NameListPair::operator== (const NameListPair& rhs) const {
	if(pair.first == rhs.pair.first) {

		if( pair.second.IsNull() && rhs.pair.second.IsNull() ) {
			return false; }

		if( pair.second.IsNull() || rhs.pair.second.IsNull() ) {
			return false; }

		return ( (*pair.second.GetConst()) == (*rhs.pair.second.GetConst()) );
	}
	else
		return false;
}

bool NameList::NameListPair::operator< (const NameListPair& rhs) const {

	if(pair.first == rhs.pair.first) {

		if( !pair.second.IsNull() && !rhs.pair.second.IsNull() ) {
			return ( (*pair.second.GetConst()) < (*rhs.pair.second.GetConst()) ); }

		if( pair.second.IsNull() ) {
			return true; }

		return false;
	}
	else {
		return pair.first < rhs.pair.first;
	}
}

NameList::NameList(const std::vector<NameListPair>& names)
: names(names){
	std::sort(this->names.begin(),this->names.end());
}

NameList::~NameList() {
}

const domparser::dom3::DOMString* const NameList::getName(const size_t& index) const {
	if(index >= names.size())
		return 0;

	return &names.at(index).name();
}

const domparser::dom3::DOMString* const NameList::getNamespaceURI(const size_t& index) const {
	if(index >= names.size())
		return 0;

	return names.at(index).namespaceURI();
}

const size_t NameList::length() const {
	return names.size();
}

bool NameList::contains(const domparser::dom3::DOMString& str) const {

	std::vector<NameListPair>::const_iterator i = names.begin();
	for(;i != names.end(); ++i) {
		if(i->name() == str)
			return true;
	}
	return false;
}

bool NameList::containsNS(const domparser::dom3::DOMString* const namespaceURI, const domparser::dom3::DOMString& name) const {
	return std::find(names.begin(),names.end(),NameListPair(name,namespaceURI)) != names.end();
}


}

}
