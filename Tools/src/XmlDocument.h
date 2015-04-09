/**
 * @file XmlDocument.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>

#include <libxml/parser.h>

#include "StringTools.h"

namespace tools {

class XmlDocument {
public:
	XmlDocument(xmlDocPtr doc);
	virtual ~XmlDocument();

public:
	size_t XPathSingle(const char* xPath, std::string& value, size_t idx = 0);
	size_t XPath(const char* xPath, std::vector<std::string>& values);

	template <class T>
	size_t XPathSingle(const char* xPath, T& value, size_t idx = 0) {
		std::string valueStr;
		size_t ret(XPathSingle(xPath, valueStr, idx));
		std::stringstream ss;
		ss << std::skipws;
		ss << valueStr;
		ss >> value;
		return ret;
	}

	template <class T>
	size_t XPath(const char* xPath, std::vector<T>& values) {
		std::vector<std::string> valuesStr;
		size_t ret(XPath(xPath, valuesStr));
		tools::StringTools::TransformStringVector(valuesStr,values);
		return values.size();
	}

private:
	xmlDocPtr doc;
};

}
