/**
 *
 * @file QueryXmlRequest.h
 * @author Moritz Wagner
 * @date 13.08.2013
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

#include "Query.h"

namespace fastcgiserver {
	class FastCGIServerThread;
}

namespace queryserver {

	class QueryThreadManager;

/**
 * @brief encapsulates a xml query request
 */
class QueryXmlRequest: public fastcgiserver::FastCGIRequest {

public:
	/**
	 * creates from QueryThreadManager and FastCGIServerThread
	 * @param queryManager query thread manager
	 * @param serverThread server thread
	 */
	QueryXmlRequest(QueryThreadManager& queryManager,fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~QueryXmlRequest();

public:
	/**
	 * gets query associated with this request
	 * @return query
	 */
	const Query& GetQuery(void) const { return query; }

private:
	virtual void OnHandle(FCGX_Request& request);

private:
	bool ParseQuery(const std::string& xmlRequest);
	bool ParseQueryCriteria(const std::string& xmlRequest);
	bool ParseQueryGrouping(const std::string& xmlRequest);
	bool ParseQueryLimitations(const std::string& xmlRequest);

private:
	Query query;
	QueryThreadManager& queryManager;

private:
	bool QueryXml(std::vector<std::string>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType);
	bool QueryTmXml(std::vector<struct tm>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType);
	bool QueryTmXmlFirstElement(struct tm& out, const char* xmlDocument, const size_t& lenDocument, const char* queryType);

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
		CRITERIA_TITLE   = 4,
		CRITERIA_DOMAIN  = 16,
		CRITERIA_CONTENT = 32,
		CRITERIA_LINKS   = 64,
		CRITERIA_PATH    = 128,

		CRITERIA_MAX     = 0xFF,
	};

	enum QueryGroupingFlag
	{
		GROUPING_UNKNOWN = 0,

		GROUPING_DOMAIN  = 1,
		GROUPING_PATH    = 2,
		GROUPING_FILE    = 4,

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

