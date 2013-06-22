/**
 *
 * @file DOMImplementationList.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "DOMImplementationList.h"
#include "DOMImplementation.h"

namespace domparser {

namespace dom3 {

DOMImplementationList::DOMImplementationList() {
}

DOMImplementationList::DOMImplementationList(domparser::dom3::DOMImplementation* singleImplementation) {
	implementations.push_back(singleImplementation);
}

DOMImplementationList::DOMImplementationList(const std::vector<domparser::dom3::DOMImplementation*>& implementations)
: implementations(implementations){
}

DOMImplementationList::~DOMImplementationList() {
	Release();
}

DOMImplementationList::DOMImplementationList(const DOMImplementationList& implList) {
	std::vector<DOMImplementation*>::const_iterator i = implList.implementations.begin();
	for(;i != implList.implementations.end(); ++i) {
		implementations.push_back((*i)->clone());}
}

DOMImplementationList& DOMImplementationList::operator= (const DOMImplementationList& implList) {
	Release();
	std::vector<DOMImplementation*>::const_iterator i = implList.implementations.begin();
	for(;i != implList.implementations.end(); ++i) {
		implementations.push_back((*i)->clone());}
	return *this;
}

domparser::dom3::DOMImplementation* DOMImplementationList::item(const size_t& index) {
	if(index >= implementations.size())
		return 0;
	return implementations.at(index);
}

const size_t DOMImplementationList::length() const{
	return implementations.size();
}

void DOMImplementationList::Release() {
	std::vector<DOMImplementation*>::iterator i = implementations.begin();
	for(;i != implementations.end(); ++i) {
		delete *i; }
}

}

}
