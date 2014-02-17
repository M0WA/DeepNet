/**
 *
 * @file QueryFactory.h
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */
#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

#include <FastCGIRequest.h>
#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>

#include "Query.h"

namespace queryserver {

class QueryFactory {
public:
	QueryFactory();
	virtual ~QueryFactory();

public:
	bool CreateQueryFromXML(const std::string& xml, tools::Pointer<queryserver::Query>& queryPtr);

private:
	bool ParseQuery(const std::string& xmlRequest, queryserver::Query& query);
	bool ParseQueryString(const std::string& xmlRequest, queryserver::Query& query);
	bool ParseQueryCriteria(const std::string& xmlRequest, queryserver::Query& query);
	bool ParseQueryGrouping(const std::string& xmlRequest, queryserver::Query& query);
	bool ParseQueryLimitations(const std::string& xmlRequest, queryserver::Query& query);

private:
	void CommitKeywordGroup(const std::string& querystring, size_t &pos, size_t &oldPos, const bool isMandatory, queryserver::Query& query);

private:
	bool QueryXml(std::vector<std::string>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType);
	bool QueryTmXml(std::vector<struct tm>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType);
	bool QueryTmXmlFirstElement(struct tm& out, const char* xmlDocument, const size_t& lenDocument, const char* queryType);

private:
	template <class T>
	bool QueryXml(std::vector<T>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
		std::vector<std::string> querypartsStr;
		if(!QueryXml(querypartsStr, xmlDocument, lenDocument, queryType)) {
			return false;}

		QueryXmlFunc<T> trans(queryparts);
		std::for_each(querypartsStr.begin(),querypartsStr.end(),trans);
		return true;
	}

	template <class T>
	bool QueryXmlFirstElement(T& out, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
		std::vector<T> queryparts;
		if(!QueryXml<T>(queryparts, xmlDocument, lenDocument, queryType)) {
			return false;}
		if(queryparts.size() < 1) {
			return false;}
		out = queryparts.at(0);
		return true;
	}

	template <class T>
	struct QueryXmlFunc : public std::unary_function<std::string,bool> {
	public:
		QueryXmlFunc(std::vector<T>& out)
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

	struct QueryTmXmlFunc : public std::unary_function<std::string,bool> {
	public:
		QueryTmXmlFunc(std::vector<struct tm>& out)
		: out(out){ }

		bool operator () (const std::string& in) {
			struct tm tmp;
			bool success(tools::TimeTools::TryParseDate(in,tmp));
			if(success)
				out.push_back(tmp);
			return success;
		}

	private:
		std::vector<struct tm>& out;
	};

private:
	enum QueryCriteriaFlag
	{
		CRITERIA_UNKNOWN = 0,

		CRITERIA_ALL     = 1,
		CRITERIA_META    = 2,
		CRITERIA_DOMAIN  = 4,
		CRITERIA_CONTENT = 16,
		CRITERIA_PATH    = 32,
		CRITERIA_LINKS   = 64,

		CRITERIA_MAX     = 0xFF,
	};

	enum QueryGroupingFlag
	{
		GROUPING_UNKNOWN = 0,
		GROUPING_DOMAIN  = 1,

		GROUPING_MAX     = 0xFF,
	};

	enum QueryLimitationsFlag
	{
		LIMITATION_UNKNOWN = 0,

		LIMITATION_DOMAIN  = 1,
		LIMITATION_MAX_AGE = 2,
		LIMITATION_LANG    = 4,
		LIMITATION_MIN_AGE = 16,

		LIMITATION_MAX     = 0xFF,
	};
};

}

