/*
 * XMLQueryRequest.h
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "FastCGIRequest.h"

namespace queryserver {

class XMLQueryRequest : public fastcgiserver::FastCGIRequest
{
public:
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
		LIMITATION_AGE     = 2,
		LIMITATION_LANG    = 4,

		LIMITATION_MAX     = 0xFF,
	};


	class QueryRequestParam
	{
	public:
		QueryRequestParam()
		: criteriaFlag(CRITERIA_UNKNOWN)
		, groupFlag(GROUPING_UNKNOWN)
		, limitFlag(LIMITATION_UNKNOWN)
		, relevanceMeta(0.0)
		, relevanceTitle(0.0)
		, relevanceDomain(0.0)
		, relevanceFullText(0.0)
		, relevanceBackLinks(0.0)
		, relevanceUrlPath(0.0)
		, pageNo(0)
		, maxResults(100)
		, limitDomain("")
		, limitAge("")
		, limitLang("")
		, queryID(-1) {}

		const unsigned long long& CriteriaFlag() const { return criteriaFlag; }
		const unsigned long long& GroupingFlag() const { return groupFlag;    }
		const unsigned long long& LimitFlag()    const { return limitFlag;    }
		const size_t              PageNumber()   const { return pageNo;       }
		const int&                MaxResults()   const { return maxResults;   }

		const long long QueryID()         const { return queryID;            }

		const double& MetaRelevance()     const { return relevanceMeta;      }
		const double& TitleRelevance()    const { return relevanceTitle;     }
		const double& DomainRelevance()   const { return relevanceDomain;    }
		const double& ContentRelevance()  const { return relevanceFullText;  }
		const double& BackLinkRelevance() const { return relevanceBackLinks; }
		const double& UrlPathRelevance()  const { return relevanceUrlPath;   }

	public:
		//container for keywords
		std::list<std::string> queryParts;

		//flags
		unsigned long long criteriaFlag;
		unsigned long long groupFlag;
		unsigned long long limitFlag;

		//criteria
		double relevanceMeta;
		double relevanceTitle;
		double relevanceDomain;
		double relevanceFullText;
		double relevanceBackLinks;
		double relevanceUrlPath;

		//limitations
		size_t pageNo;
		int maxResults;
		std::string limitDomain;
		std::string limitAge;
		std::string limitLang;

		long long queryID;
	};

public:
	XMLQueryRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~XMLQueryRequest();

	virtual void OnHandle(FCGX_Request& request);

	const std::list<std::string>& QueryParts() {
		queryRequestParam.queryParts.sort();
		queryRequestParam.queryParts.unique();
		return queryRequestParam.queryParts; }

	const QueryRequestParam& Params() const { return queryRequestParam; }
	QueryRequestParam& Params() { return queryRequestParam; }

private:
	bool ParseQuery(const std::string& xmlRequest, QueryRequestParam& out);
	bool ParseQueryCriteria(const std::string& xmlRequest, QueryRequestParam& out);
	bool ParseQueryGrouping(const std::string& xmlRequest, QueryRequestParam& out);
	bool ParseQueryLimitations(const std::string& xmlRequest, QueryRequestParam& out);

private:
	QueryRequestParam queryRequestParam;
};

}
