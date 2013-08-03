/*
 * XMLQueryRequest.cpp
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#include "XMLQueryRequest.h"

#include <Logging.h>
#include <StringTools.h>

namespace queryserver {

XMLQueryRequest::XMLQueryRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
{
}

XMLQueryRequest::~XMLQueryRequest()
{
}

void XMLQueryRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

	bool success(ParseQuery(std::string(rawPostData),queryRequestParam));
	if(!success){
		return;}
}

bool XMLQueryRequest::ParseQueryGrouping(const std::string& xmlRequest, QueryRequestParam& out)
{
	//parsing query grouping flag
	std::list<std::string> queryGrouping;
	if( !Xpath(queryGrouping, xmlRequest.c_str(), (xmlChar*)"/request/query/grouping/flag/text()")) {
		log::Logging::LogError("could not parse xml query grouping flag");
		return false; }
	std::list<std::string>::const_iterator iterGrouping(queryGrouping.begin());
	out.groupFlag = 0;
	for(;iterGrouping != queryGrouping.end();++iterGrouping){
		unsigned long long groupTmp(0);
		tools::StringTools::TransformString(*iterGrouping, groupTmp);
		out.groupFlag |= groupTmp;
		/*
		switch(groupTmp)
		{
		case GROUPING_DOMAIN:
			break;
		case GROUPING_PATH:
			break;
		case GROUPING_FILE:
			break;
		default:
			break;
		};
		*/
	}
	return true;
}

bool XMLQueryRequest::ParseQueryCriteria(const std::string& xmlRequest, QueryRequestParam& out)
{
	//parsing query criteria flag
	std::list<std::string> queryCriterias;
	if( !Xpath(queryCriterias, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/flag/text()")) {
		log::Logging::LogError("could not parse xml query criteria flag");
		return false; }
	std::list<std::string>::const_iterator iterCriterias(queryCriterias.begin());
	out.criteriaFlag = 0;
	std::list<std::string> tmpList;
	for(;iterCriterias != queryCriterias.end();++iterCriterias){
		unsigned long long critTmp(0);
		tools::StringTools::TransformString(*iterCriterias, critTmp);
		out.criteriaFlag |= critTmp;

		bool bDone(false);

		switch(critTmp)
		{
		case CRITERIA_ALL:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceMeta/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceMeta);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceTitle/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceTitle);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceDomain/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceDomain);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceFullText/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceFullText);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceUrlPath/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceUrlPath);
			tmpList.clear();
			bDone = true;
			break;
		case CRITERIA_META:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceMeta/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceMeta);
			break;
		case CRITERIA_TITLE:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceTitle/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceTitle);
			break;
		case CRITERIA_DOMAIN:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceDomain/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceDomain);
			break;
		case CRITERIA_CONTENT:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceFullText/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceFullText);
			break;
		case CRITERIA_LINKS:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
			break;
		case CRITERIA_PATH:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceUrlPath/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceUrlPath);
			break;
		default:
			break;
		}
		tmpList.clear();
		if(bDone) break;
	}
	return true;
}

bool XMLQueryRequest::ParseQueryLimitations(const std::string& xmlRequest, QueryRequestParam& out)
{
	//parsing query limitations flag
	std::list<std::string> queryLimitations;
	if( !Xpath(queryLimitations, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/flag/text()")) {
		log::Logging::LogError("could not parse xml query limitation flag");
		return false; }
	std::list<std::string>::const_iterator iterLimitations(queryLimitations.begin());
	out.limitFlag = 0;
	std::list<std::string> tmpList;
	for(;iterLimitations != queryLimitations.end();++iterLimitations){
		unsigned long long limitTmp(0);
		tools::StringTools::TransformString(*iterLimitations, limitTmp);
		out.limitFlag |= limitTmp;

		switch(limitTmp)
		{
		case LIMITATION_DOMAIN:
			Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/domainLimit/text()");
			if (tmpList.size() > 0) return false;
			out.limitDomain = *tmpList.begin();
			break;
		case LIMITATION_AGE:
			Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/ageLimit/text()");
			if (tmpList.size() > 0) return false;
			out.limitAge = *tmpList.begin();
			break;
		case LIMITATION_LANG:
			Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/langLimit/text()");
			if (tmpList.size() > 0) return false;
			out.limitLang = *tmpList.begin();
			break;
		default:
			break;
		}

		tmpList.clear();
	}

	//parsing max results
	std::list<std::string> maxResults;
	if( !Xpath(maxResults, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/maxResults/text()") || maxResults.size() == 0) {
		log::Logging::LogError("could not parse xml query max results");
		out.maxResults = 100;
	} else {
		tools::StringTools::TransformString(*maxResults.begin(), out.maxResults);
		if(out.maxResults > 10000){
			out.maxResults = 10000;	}
	}
	return true;
}

bool XMLQueryRequest::ParseQuery(const std::string& xmlRequest, QueryRequestParam& out)
{
	//parsing query parts
	if( !Xpath(out.queryParts, xmlRequest.c_str(), (xmlChar*)"/request/query/querypart/text()")) {
		log::Logging::LogError("could not parse xml query request");
		return false; }

	out.pageNo = 0;
	std::list<std::string> tmpPageNo;
	if( Xpath(tmpPageNo, xmlRequest.c_str(), (xmlChar*)"/request/query/pageNo/text()")) {

		if(tmpPageNo.size()>0){
			std::stringstream tmpPageNoConv;
			tmpPageNoConv << tmpPageNo.front();
			tmpPageNoConv >> out.pageNo; }
	}

	out.queryID = -1;
	std::list<std::string> tmpQueryId;
	if( Xpath(tmpQueryId, xmlRequest.c_str(), (xmlChar*)"/request/query/queryId/text()")) {

		if(tmpQueryId.size()>0){
			std::stringstream tmpSSQueryId;
			tmpSSQueryId << tmpQueryId.front();
			tmpSSQueryId >> out.queryID; }
	}

	ParseQueryCriteria(xmlRequest, out);
	ParseQueryGrouping(xmlRequest, out);
	ParseQueryLimitations(xmlRequest, out);

	return true;
}

}
