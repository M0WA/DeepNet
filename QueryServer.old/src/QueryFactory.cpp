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

void QueryFactory::CommitKeywordGroup(const std::string& querystring, size_t &pos, size_t &oldPos, const bool isMandatory, const bool isCaseInsensitive, const bool isSimilar, queryserver::Query& query) {

	pos++;
	if( (pos-oldPos) <= 1) {
		oldPos = pos;
		return;	}

	QueryKeywordGroup group;
	if(group.ParseFromString(querystring.substr(oldPos,pos-oldPos),isMandatory,isCaseInsensitive, isSimilar)) {
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

	bool inQuote(false), isMandatory(false), isCaseInsensitive(true), isSimilar(false);
	size_t pos(0), oldPos(0);

	while( (pos = querystring.find_first_of("+\" ",pos)) != std::string::npos ) {

		const char& c(querystring.at(pos));

		bool commit(false), commitIsMandatory(isMandatory), commitIsCaseInsensitive(isCaseInsensitive), commitIsSimilar(isSimilar);
		if(!inQuote) {
			if(c == ' ') {
				commit = true;
				isMandatory = true;
				isCaseInsensitive = false;
				isSimilar = false;
			}
			else if(c == '+') {
				commit = true;
				isMandatory = true;
				isCaseInsensitive = false;
				isSimilar = false;
			}
		}
		else if (c == '\"') {
			if( !pos || querystring.at(pos-1) != '\\' ) {
				commit = true;
				inQuote = !inQuote;
				isMandatory = false;
				isCaseInsensitive = true;
				isSimilar = false;
			}
		}

		if(commit) {
			CommitKeywordGroup(
				querystring,
				pos,
				oldPos,
				commitIsMandatory,
				commitIsCaseInsensitive,
				commitIsSimilar,
				query
			);
		}
	}

	if(pos < querystring.length()) {
		CommitKeywordGroup(querystring, pos, oldPos, isMandatory, isCaseInsensitive, isSimilar, query); }

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
		case QueryLimitations::LIMITATION_DOMAIN:

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
		case QueryLimitations::LIMITATION_MAX_AGE:
		{
			std::string maxAge;
			if(!QueryXmlFirstElement(maxAge, xmlRequest.c_str(), xmlRequest.length(), "limitations/ageLimit")) {
				log::Logging::LogWarn("could not find maximum age in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			query.properties.limitations.limits[QueryLimitations::LIMITATION_MAX_AGE] = maxAge;
		}
			break;
		case QueryLimitations::LIMITATION_MIN_AGE:
		{
			std::string minAge;
			if(!QueryXmlFirstElement(minAge, xmlRequest.c_str(), xmlRequest.length(), "limitations/minAgeLimit")) {
				log::Logging::LogWarn("could not find minimum age in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			query.properties.limitations.limits[QueryLimitations::LIMITATION_MIN_AGE] = minAge;
		}
			break;
		case QueryLimitations::LIMITATION_LANG:
		{
			std::string lang;
			if(!QueryXmlFirstElement(lang, xmlRequest.c_str(), xmlRequest.length(), "langLimit/langLimit")) {
				log::Logging::LogWarn("could not find language limitation in query request");
				log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
				return false; }
			query.properties.limitations.limits[QueryLimitations::LIMITATION_LANG] = lang;
		}
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

	unsigned long long flag(QueryCriteria::CRITERIA_UNKNOWN);
	std::vector<unsigned long long>::const_iterator i(queryCriterias.begin());
	for(;i != queryCriterias.end();++i){
		flag |= (*i); }

	QueryCriteria& criteria(query.properties.criteria);
	if( (flag & QueryCriteria::CRITERIA_META) ) {
		double relevanceMeta(0.0);
		if(!QueryXmlFirstElement(relevanceMeta, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceMeta")) {
			log::Logging::LogWarn("could not find limitation flag in query request");
			log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
			return false; }
		if(relevanceMeta > 0.0) {
			criteria.relevance.insert(std::pair<QueryCriteria::QueryCriteriaFlag,Relevance>(QueryCriteria::CRITERIA_META,Relevance(relevanceMeta,1.0)));}
	}
	if( (flag & QueryCriteria::CRITERIA_CONTENT) ) {
		double relevanceContent(0.0);
		if(!QueryXmlFirstElement(relevanceContent, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceFullText")) {
			log::Logging::LogWarn("could not find limitation flag in query request");
			log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
			return false; }
		if(relevanceContent > 0.0) {
			criteria.relevance.insert(std::pair<QueryCriteria::QueryCriteriaFlag,Relevance>(QueryCriteria::CRITERIA_CONTENT,Relevance(relevanceContent,1.0))); }
	}
	if( (flag & QueryCriteria::CRITERIA_PATH) ) {
		double relevanceUrlPath(0.0);
		if(!QueryXmlFirstElement(relevanceUrlPath, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceUrlPath")) {
			log::Logging::LogWarn("could not find limitation flag in query request");
			log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
			return false; }
		if(relevanceUrlPath > 0.0) {
			criteria.relevance.insert(std::pair<QueryCriteria::QueryCriteriaFlag,Relevance>(QueryCriteria::CRITERIA_PATH,Relevance(relevanceUrlPath,1.0))); }
	}
	if( (flag & QueryCriteria::CRITERIA_DOMAIN) ) {
		double relevanceDomain(0.0);
		if(!QueryXmlFirstElement(relevanceDomain, xmlRequest.c_str(), xmlRequest.length(), "criteria/relevanceDomain")) {
			log::Logging::LogWarn("could not find limitation flag in query request");
			log::Logging::LogTraceUnlimited("%s",xmlRequest.c_str());
			return false; }
		if(relevanceDomain > 0.0) {
			criteria.relevance.insert(std::pair<QueryCriteria::QueryCriteriaFlag,Relevance>(QueryCriteria::CRITERIA_DOMAIN,Relevance(relevanceDomain,1.0))); }
	}
	//TODO:
	//case QueryCriteria::CRITERIA_LINKS:
	//	if (!Xpath(tmpList, xmlRequest.c_str(), (xmlChar*)"/request/query/criteria/relevanceBackLinks/text()") || tmpList.size() == 0)
	//		return false;
	//	tools::StringTools::TransformString(*tmpList.begin(), out.relevanceBackLinks);
	//	break;

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
