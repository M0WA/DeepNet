/**
 *
 * @file QueryXmlRequest.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryXmlRequest.h"

#include "QueryThreadManager.h"

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <Logging.h>
#include <TimeTools.h>

#include <FastCGIServerThread.h>

#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>

namespace queryserver {

//
//TODO: move to config file
//
#define RESULTS_PER_REQUEST_HARDLIMIT 10000

QueryXmlRequest::QueryXmlRequest(QueryThreadManager& queryManager,fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
, queryManager(queryManager){
}

QueryXmlRequest::~QueryXmlRequest() {
}

bool QueryXmlRequest::ParseQuery(const std::string& xmlRequest) {

	//parsing keywords for query
	std::vector<std::string> strKeywords;
	if(!QueryXml(strKeywords, xmlRequest.c_str(), xmlRequest.length(), "querypart")) {
		log::Logging::LogWarn("could not find keywords in query request");
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }

	//parsing case sensivity
	bool caseSensitive(false);
	if(!QueryXmlFirstElement(caseSensitive, xmlRequest.c_str(), xmlRequest.length(), "caseSensivity")) {
		caseSensitive = false; }

	//append all keywords to query
	std::vector<std::string>::const_iterator iStrs(strKeywords.begin());
	for(size_t pos(0);iStrs!=strKeywords.end();++iStrs,++pos) {
		query.AppendKeyword(pos,*iStrs,caseSensitive); }

	//parsing page number
	if(!QueryXmlFirstElement(query.pageNo, xmlRequest.c_str(), xmlRequest.length(), "pageNo")) {
		query.pageNo = 0; }

	//parsing query id
	if(!QueryXmlFirstElement(query.queryId, xmlRequest.c_str(), xmlRequest.length(), "pageNo")) {
		query.queryId = 0; }

	if(!ParseQueryCriteria(xmlRequest))
		return false;

	if(!ParseQueryGrouping(xmlRequest))
		return false;

	if(!ParseQueryLimitations(xmlRequest))
		return false;

	return true;
}

bool QueryXmlRequest::QueryXml(std::vector<std::string>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType)
{
	static const char* xPathPrefix("/request/query/");
	static const char* xPathPostfix("/text()");

	std::string xPathQuery;
	tools::StringTools::FormatString(xPathQuery,"%s%s%s",xPathPrefix,queryType,xPathPostfix);

    xmlDocPtr doc(xmlParseMemory(xmlDocument,lenDocument));
    if (doc == NULL) {
    	log::Logging::LogWarn("unable to parse incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",xmlDocument);
		return false; }

    xmlXPathContextPtr xpathCtx(xmlXPathNewContext(doc));
    if(xpathCtx == NULL) {
    	log::Logging::LogWarn("unable to create new xpath context for incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",xmlDocument);
        xmlFreeDoc(doc);
        return false; }

    xmlXPathObjectPtr xpathObj(xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xPathQuery.c_str()), xpathCtx));
    if(xpathObj == NULL) {
    	log::Logging::LogWarn("unable to evaluate xpath expression for incoming query xml request: %s",xPathQuery.c_str());
    	log::Logging::LogTraceUnlimited("%s",xmlDocument);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false; }

    xmlNodeSetPtr nodes(xpathObj->nodesetval);
    int size( (nodes) ? nodes->nodeNr : 0 );

    for(int i(0); i < size; ++i) {
    	if(nodes->nodeTab[i]->type == XML_TEXT_NODE) {
			if(nodes->nodeTab[i]->content) {
				queryparts.push_back(std::string(reinterpret_cast<const char*>(nodes->nodeTab[i]->content)));
			}
    	}
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
    return true;
}

bool QueryXmlRequest::QueryTmXml(std::vector<struct tm>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
	std::vector<std::string> querypartsStr;
	if(!QueryXml(querypartsStr, xmlDocument, lenDocument, queryType)) {
		return false;}

	QueryTmXmlFunc trans(queryparts);
	std::for_each(querypartsStr.begin(),querypartsStr.end(),trans);
	return true;
}

bool QueryXmlRequest::QueryTmXmlFirstElement(struct tm& out, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
	std::vector<struct tm> queryparts;
	if(!QueryTmXml(queryparts, xmlDocument, lenDocument, queryType)) {
		return false;}
	if(queryparts.size() < 1) {
		return false;}
	out = queryparts.at(0);
	return true;
}

bool QueryXmlRequest::ParseQueryLimitations(const std::string& xmlRequest) {

	std::vector<unsigned long long> limitationFlags;
	if(!QueryXml(limitationFlags, xmlRequest.c_str(), xmlRequest.length(), "limitations/flag")) {
		log::Logging::LogWarn("could not find limitation flag in query request");
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }

	std::vector<unsigned long long>::const_iterator i(limitationFlags.begin());
	for(;i != limitationFlags.end();++i) {
		switch(*i)
		{
		case LIMITATION_DOMAIN:
			{
				std::string limitDomainString;
				if(!QueryXmlFirstElement(limitDomainString, xmlRequest.c_str(), xmlRequest.length(), "limitations/domainLimit")) {
					log::Logging::LogWarn("could not find limitation domain in query request");
					log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
					return false; }

				tools::Pointer<htmlparser::DatabaseUrl> url;
				try {
					caching::CacheDatabaseUrl::GetByUrlString(serverThread->DB().Connection(), limitDomainString, url);	}
				catch(errors::Exception& e) {
					e.DisableLogging();
					log::Logging::LogWarn("could not parse limitation domain");
					log::Logging::LogTraceUnlimited("exception:\n%s",e.Dump().c_str());
					log::Logging::LogTraceUnlimited("request:\n%s",xmlRequest.c_str());
					break; }

				query.properties.limitSecondLevelDomainID = url.GetConst()->GetSecondLevelID();
				query.properties.limitSubDomainID = url.GetConst()->GetSubdomainID();
			}
			break;
		case LIMITATION_MAX_AGE:
			if(!QueryTmXmlFirstElement(query.properties.maxAge, xmlRequest.c_str(), xmlRequest.length(), "limitations/ageLimit")) {
				log::Logging::LogWarn("could not find maximum age in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		case LIMITATION_MIN_AGE:
			if(!QueryTmXmlFirstElement(query.properties.minAge, xmlRequest.c_str(), xmlRequest.length(), "limitations/minAgeLimit")) {
				log::Logging::LogWarn("could not find minimum age in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		case LIMITATION_LANG:
			if(!QueryXmlFirstElement(query.properties.language, xmlRequest.c_str(), xmlRequest.length(), "langLimit/langLimit")) {
				log::Logging::LogWarn("could not find language limitation in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		default:
			break;
		}
	}

	//parsing max results
	if(!QueryXmlFirstElement(query.properties.maxResults, xmlRequest.c_str(), xmlRequest.length(), "limitations/maxResults")) {
		log::Logging::LogWarn("could not find limitation flag in query request");
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }
	if(query.properties.maxResults > RESULTS_PER_REQUEST_HARDLIMIT) {
		query.properties.maxResults = RESULTS_PER_REQUEST_HARDLIMIT; }

	return true;
}

bool QueryXmlRequest::ParseQueryCriteria(const std::string& xmlRequest) {

	//parsing query criteria flag
	std::vector<unsigned long long> queryCriterias;
	if( !QueryXml(queryCriterias, xmlRequest.c_str(), xmlRequest.length(), "criteria/flag") ) {
		log::Logging::LogWarn("could not find criteria flag in query request");
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }

	bool bDone(false);
	std::vector<unsigned long long>::const_iterator i(queryCriterias.begin());
	for(;i != queryCriterias.end();++i){
		switch(*i)
		{
		case CRITERIA_ALL:
			if(!QueryXmlFirstElement(query.properties.relevanceMeta, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceMeta")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }

			if(!QueryXmlFirstElement(query.properties.relevanceSecondLevelDomain, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceDomain")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }

			if(!QueryXmlFirstElement(query.properties.relevanceContent, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceFullText")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }

			if(!QueryXmlFirstElement(query.properties.relevanceUrlPath, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceUrlPath")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			//TODO:
			/*
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceTitle/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceTitle);
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
			tmpList.clear();
			*/
			bDone = true;
			break;
		case CRITERIA_META:
			if(!QueryXmlFirstElement(query.properties.relevanceMeta, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceMeta")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		case CRITERIA_CONTENT:
			if(!QueryXmlFirstElement(query.properties.relevanceContent, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceFullText")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		case CRITERIA_PATH:
			if(!QueryXmlFirstElement(query.properties.relevanceUrlPath, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceUrlPath")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
		case CRITERIA_DOMAIN:
			if(!QueryXmlFirstElement(query.properties.relevanceSecondLevelDomain, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceDomain")) {
				log::Logging::LogWarn("could not find limitation flag in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			break;
			//TODO:
			/*
		case CRITERIA_TITLE:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceTitle/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceTitle);
			break;
		case CRITERIA_LINKS:
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
			break;
			*/
		default:
			break;
		}

		if(bDone) break;
	}

	return true;
}

bool QueryXmlRequest::ParseQueryGrouping(const std::string& xmlRequest) {

	//parsing query grouping flag
	std::vector<unsigned long long> queryGrouping;
	if( !QueryXml(queryGrouping, xmlRequest.c_str(), xmlRequest.length(), "grouping/flag") ) {
		log::Logging::LogWarn("could not find grouping flag in query request");
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }

	std::vector<unsigned long long>::const_iterator iterGrouping(queryGrouping.begin());
	for(;iterGrouping != queryGrouping.end();++iterGrouping) {
		switch(*iterGrouping) {
		case GROUPING_DOMAIN:
			query.properties.groupBySecondLevelDomain = true;
			break;
		default:
			break;
		};
	}

	return true;
}

void QueryXmlRequest::OnHandle(FCGX_Request& request) {

	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

	//
	//TODO: need to make this better => buffer overflow ???
	//
	if(!ParseQuery(std::string(rawPostData))) {
		return; }

	queryManager.BeginQuery(query);
}

}
