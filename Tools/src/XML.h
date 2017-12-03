/*
 * @file XML.h
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include <libxml/tree.h>

#include "StringTools.h"

namespace tools {

/**
 * @brief class to read/query xml formated files
 */
class XML {
public:
	XML(const std::string& xmlDoc);
	virtual ~XML();

public:
	bool XPath(const std::string& xpath,std::vector<std::string>& entries);

public:
	template <class T>
	bool XPath(const std::string& xpath, std::vector<T>& entries) {
		std::vector<std::string> partsStr;
		if(!XPath(xpath, partsStr)) {
			return false;}

		XPathFunc<T> trans(entries);
		std::for_each(partsStr.begin(),partsStr.end(),trans);
		return true;
	}

	template <class T>
	bool XPathFirst(const std::string& xpath, T& out) {
		std::vector<T> entries;
		if(!XPath<T>(xpath, entries)) {
			return false;}
		out = entries.at(0);
		return true;
	}

private:
	template <class T>
	struct XPathFunc : public std::unary_function<std::string,bool> {
	public:
		XPathFunc(std::vector<T>& out)
		: out(out){ }

		bool operator () (const std::string& in) {
			bool success(tools::StringTools::TransformString(in,tmp));
			if(success)
				out.push_back(tmp);
			return success;
		}

	private:
		std::vector<T>& out;
		T tmp;
	};

private:
	xmlDocPtr doc;
};

}
