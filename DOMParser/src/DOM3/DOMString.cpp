/**
 *
 * @file DOM3/DOMString.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "DOMString.h"

#include <string.h>

namespace domparser {

namespace dom3 {

DOMString::DOMString() {
}

DOMString::DOMString(const char* pszAssign) {
	Assign(pszAssign);
}

DOMString::DOMString(const char* pcAssign, const size_t& size) {
	Assign(pcAssign,size);
}

DOMString::DOMString(const std::string& assign) {
	Assign(assign.c_str(),assign.length());
}

DOMString::DOMString(const DOMString& copy) {
	Assign(copy);
}

DOMString& DOMString::operator= (const DOMString& assign) {
	Assign(assign);
	return *this;
}

bool DOMString::operator== (const DOMString& rhs) const {
	return CompareCaseSensitive(rhs);
}

bool DOMString::operator< (const DOMString& rhs) const {
	return (string.compare(rhs.string) < 0);
}

DOMString::~DOMString() {
	Release();
}

void DOMString::Assign(const char* pszAssign) {
	Assign(pszAssign,strlen(pszAssign));
}

void DOMString::Assign(const char* pcAssign, const size_t& size) {
	Release();
	string = UNICODE_STRING(pcAssign,strlen(pcAssign));
}

void DOMString::Assign(const std::string& assign) {
	Assign(assign.c_str(),assign.length());
}

void DOMString::Assign(const DOMString& assign) {
	string.fastCopyFrom(assign.string);
}

void DOMString::Release() {
}

bool DOMString::CompareCaseSensitive(const DOMString& rhs) const {
	return (string.compare(rhs.string) == 0);
}

bool DOMString::CompareCaseInsensitive(const DOMString& rhs) const {
	return (string.caseCompare(rhs.string,0) == 0);
}

}

}
