/**
 *
 * @file QueryFactory.cpp
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#include "QueryFactory.h"

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <Logging.h>
#include <TimeTools.h>

#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>

//
//TODO: move to config file
//
#define RESULTS_PER_REQUEST_HARDLIMIT 10000

namespace queryserver {

QueryFactory::QueryFactory() {
}

QueryFactory::~QueryFactory() {
}

bool QueryFactory::CreateQueryFromXML(const std::string& xml, tools::Pointer<queryserver::Query>& queryPtr) {

	queryPtr.Set(new queryserver::Query(),true);
	queryserver::Query& query(*queryPtr.Get());

	if(!ParseQueryString(xml, query)) {
		return false; }

	//parsing page number
	if(!QueryXmlFirstElement(query.properties.pageNo, xml.c_str(), xml.length(), "pageNo")) {
		query.properties.pageNo = 0; }

	//parsing query id
	if(!QueryXmlFirstElement(query.properties.queryId, xml.c_str(), xml.length(), "queryId")) {
		query.properties.queryId = 0; }

	if(!ParseQueryCriteria(xml, query))
		return false;

	if(!ParseQueryGrouping(xml, query))
		return false;

	if(!ParseQueryLimitations(xml, query))
		return false;

	return true;
}

bool QueryFactory::QueryXml(std::vector<std::string>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType)
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

bool QueryFactory::QueryTmXml(std::vector<struct tm>& queryparts, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
	std::vector<std::string> querypartsStr;
	if(!QueryXml(querypartsStr, xmlDocument, lenDocument, queryType)) {
		return false;}

	QueryTmXmlFunc trans(queryparts);
	std::for_each(querypartsStr.begin(),querypartsStr.end(),trans);
	return true;
}

bool QueryFactory::QueryTmXmlFirstElement(struct tm& out, const char* xmlDocument, const size_t& lenDocument, const char* queryType) {
	std::vector<struct tm> queryparts;
	if(!QueryTmXml(queryparts, xmlDocument, lenDocument, queryType)) {
		return false;}
	if(queryparts.size() < 1) {
		return false;}
	out = queryparts.at(0);
	return true;
}

void QueryFactory::CommitKeywordGroup(const std::string& querystring, size_t &pos, size_t &oldPos, const bool isMandatory, queryserver::Query& query) {

	pos++;
	if( (pos-oldPos) <= 1) {
		oldPos = pos;
		return;	}

	QueryKeywordGroup group;
	if(group.ParseFromString(querystring.substr(oldPos,pos-oldPos),isMandatory)) {
		query.AddQueryGroup(group); }
	oldPos = pos;
}

bool QueryFactory::ParseQueryString(const std::string& xmlRequest, queryserver::Query& query) {

	std::string querystring;
	if(!QueryXmlFirstElement(querystring, xmlRequest.c_str(), xmlRequest.length(), "queryString")) {
		log::Logging::LogWarn("could not find query string in query request %s",querystring.c_str());
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
		return false; }

	tools::StringTools::Trim(querystring);
	query.query = querystring;

	bool inQuote(false), isMandatory(false);
	size_t pos(0), oldPos(0);

	while( (pos = querystring.find_first_of("+\" ",pos)) != std::string::npos ) {
		switch(querystring.at(pos))
		{
		case '+':
			if(!inQuote) {
				CommitKeywordGroup(querystring, pos, oldPos, isMandatory, query);
				isMandatory = true;	}
			break;
		case '\"':
			inQuote = !inQuote;
			if(!inQuote) {
				CommitKeywordGroup(querystring, pos, oldPos, isMandatory, query);
				isMandatory = false; }
			break;
		case ' ':
			if(!inQuote) {
				CommitKeywordGroup(querystring, pos, oldPos, isMandatory, query);
				isMandatory = false; }
			break;
		}
	}

	if(pos < querystring.length()) {
		CommitKeywordGroup(querystring, pos, oldPos, isMandatory, query); }

	if(!query.GetKeywordGroups().size()) {
		log::Logging::LogWarn("could not find query string groups in query request: %s",querystring.c_str());
		log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str()); }

	return query.GetKeywordGroups().size();
}

bool QueryFactory::ParseQueryLimitations(const std::string& xmlRequest, queryserver::Query& query) {

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

			//
			//TODO: need database connection here
			//      for parsing domains, see beyond
			//

			/*
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
			*/
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

bool QueryFactory::ParseQueryCriteria(const std::string& xmlRequest, queryserver::Query& query) {

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
			tmpList.clear();
			if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
				return false;
			tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
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

bool QueryFactory::ParseQueryGrouping(const std::string& xmlRequest, queryserver::Query& query) {

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

}
