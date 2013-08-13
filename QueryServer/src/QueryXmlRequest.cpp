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

void QueryXmlRequest::OnHandle(FCGX_Request& request) {

	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		//
		//TODO: throw exception or leave an error
		//
		return;	}

	//
	//TODO: need to make this better => buffer overflow ???
	//
	if(!ParseQuery(std::string(rawPostData))) {
		//
		//TODO: throw exception or leave an error
		//
		return; }

	queryManager.BeginQuery(query);
}

bool QueryXmlRequest::ParseQuery(const std::string& xmlRequest) {

	//parsing query keywords
	if(!QueryXml(query.keywords, xmlRequest.c_str(), xmlRequest.length(), "querypart")) {
		log::Logging::LogError("could not find keywords in query request");
		log::Logging::LogTrace("%s",xmlRequest.c_str());
		return false; }

#if 0

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

#endif

	if(!ParseQueryCriteria(xmlRequest))
		return false;

	if(!ParseQueryGrouping(xmlRequest))
		return false;

	if(!ParseQueryLimitations(xmlRequest))
		return false;

	return true;
}

bool QueryXmlRequest::ParseQueryLimitations(const std::string& xmlRequest) {

	std::vector<unsigned long long> limitationFlags;
	if(!QueryXml(limitationFlags, xmlRequest.c_str(), xmlRequest.length(), "limitations/flag")) {
		log::Logging::LogError("could not find limitation flag in query request");
		log::Logging::LogTrace("%s",xmlRequest.c_str());
		return false; }

	std::vector<unsigned long long>::const_iterator i(limitationFlags.begin());
	for(;i != limitationFlags.end();++i) {
		switch(*i)
		{
		case LIMITATION_DOMAIN:
			{
				std::string limitDomainString;
				if(!QueryXmlFirstElement(limitDomainString, xmlRequest.c_str(), xmlRequest.length(), "limitations/domainLimit")) {
					log::Logging::LogError("could not find limitation flag in query request");
					log::Logging::LogTrace("%s",xmlRequest.c_str());
					return false;
				}
				//
				//TODO: convert to url and set secondlevel- and subdomain
				//
			}
			break;
		case LIMITATION_MAX_AGE:
			if(!QueryTmXmlFirstElement(query.properties.maxAge, xmlRequest.c_str(), xmlRequest.length(), "limitations/ageLimit")) {
				log::Logging::LogError("could not find limitation flag in query request");
				log::Logging::LogTrace("%s",xmlRequest.c_str());
				return false;
			}
			break;
		case LIMITATION_MIN_AGE:
			break;
		case LIMITATION_LANG:
			/*
			Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/limitations/langLimit/text()");
			if (tmpList.size() > 0) return false;
			out.limitLang = *tmpList.begin();
			*/
			break;
		default:
			break;
		}
	}

	//parsing max results
	if(!QueryXmlFirstElement(query.properties.maxResults, xmlRequest.c_str(), xmlRequest.length(), "limitations/maxResults")) {
		log::Logging::LogError("could not find limitation flag in query request");
		log::Logging::LogTrace("%s",xmlRequest.c_str());
		return false; }
	if(query.properties.maxResults > RESULTS_PER_REQUEST_HARDLIMIT) {
		query.properties.maxResults = RESULTS_PER_REQUEST_HARDLIMIT; }

	return true;
}

bool QueryXmlRequest::ParseQueryCriteria(const std::string& xmlRequest) {
	return false;
}

bool QueryXmlRequest::ParseQueryGrouping(const std::string& xmlRequest) {
	return false;
}

bool QueryXmlRequest::QueryXml(std::vector<std::string>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType)
{
	static const char* xPathPrefix("/request/query/");
	static const char* xPathPostfix("/text()");

	std::string xPathQuery;
	tools::StringTools::FormatString(xPathQuery,"%s%s%s",xPathPrefix,queryType,xPathPostfix);

    xmlDocPtr doc(xmlParseMemory(xmlDocument,lenDocument));
    if (doc == NULL) {
    	log::Logging::LogTrace("unable to parse incoming xml:\n %s",xmlDocument);
		return false;
    }

    xmlXPathContextPtr xpathCtx(xmlXPathNewContext(doc));
    if(xpathCtx == NULL) {
    	log::Logging::LogTrace("unable to create new XPath context");
        xmlFreeDoc(doc);
        return false;
    }

    xmlXPathObjectPtr xpathObj(xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xPathQuery.c_str()), xpathCtx));
    if(xpathObj == NULL) {
    	log::Logging::LogTrace("unable to evaluate xpath expression");
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false;
    }

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

}
