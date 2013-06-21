/**
 *
 * @file NameList.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once


#include <vector>

#include <Pointer.h>

#include "DOMString.h"

namespace domparser {

namespace dom3 {

class NameList {
private:
	class NameListPair {
	public:
		NameListPair(const domparser::dom3::DOMString& name, const domparser::dom3::DOMString* const ptrNamespaceURI);

	public:
		bool operator== (const NameListPair& rhs) const;

	public:
		const domparser::dom3::DOMString& name() const { return pair.first; }
		const domparser::dom3::DOMString* const namespaceURI() const { return pair.second.GetConst(); }

	private:
		std::pair<domparser::dom3::DOMString,tools::Pointer<domparser::dom3::DOMString> > pair;
	};

public:
	NameList();
	virtual ~NameList();

public:
	//DOM3 interface
	const domparser::dom3::DOMString* const getName(const size_t& index) const;
	const domparser::dom3::DOMString* const getNamespaceURI(const size_t& index) const;
	const size_t length() const;
	bool contains(const domparser::dom3::DOMString& str) const;
	bool containsNS(const domparser::dom3::DOMString* const namespaceURI, const domparser::dom3::DOMString& name) const;

private:
	std::vector<NameListPair> names;
};

}

}
