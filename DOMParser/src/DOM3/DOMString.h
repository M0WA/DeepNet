/**
 *
 * @file DOM3/DOMString.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include <string>
#include <unicode/unistr.h>

namespace domparser {

namespace dom3 {

class DOMString {
public:
	DOMString();
	DOMString(const char* pszAssign);
	DOMString(const char* pcAssign, const size_t& size);
	DOMString(const std::string& assign);

	DOMString(const DOMString& copy);

	DOMString& operator= (const DOMString& assign);
	bool operator== (const DOMString& rhs) const;
	bool operator< (const DOMString& rhs) const;

	virtual ~DOMString();

public:
	void Assign(const char* pszAssign);
	void Assign(const char* pcAssign, const size_t& size);
	void Assign(const std::string& assign);
	void Assign(const DOMString& assign);
	void Release();

public:
	bool CompareCaseSensitive(const DOMString& rhs) const;
	bool CompareCaseInsensitive(const DOMString& rhs) const;

private:
	icu::UnicodeString string;
};

}

}
