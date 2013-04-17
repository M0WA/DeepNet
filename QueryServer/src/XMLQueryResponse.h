/*
 * XMLQueryResponse.h
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <sstream>
#include <vector>
#include <list>

#include <FastCGIResponse.h>

namespace htmlparser {
	class DatabaseUrl;
}

namespace database {
	class DatabaseHelper;
}

namespace queryserver {

class XMLQueryRequest;
class KeywordEntry;
class UrlStageEntry;
class BackLinkEntry;
class PageInfo;
class Relevance;
class UrlStageProperties;

class XMLQueryResponse : public fastcgiserver::FastCGIResponse {
public:
	class OrderedResults
	{
public:
		std::vector<long long> sortedUrlStageIDs;
		std::vector<long long> sortedSecondLevelDomainID;
		std::map<long long, std::vector<long long> > groupedSecondLevelDomainIDUrlStageID;
	};

public:
	XMLQueryResponse(database::DatabaseHelper& dbHelper,XMLQueryRequest* xmlQueryRequest);
	virtual ~XMLQueryResponse();

	virtual bool Process(FCGX_Request& request);

private:
	bool ProcessNewQuery(std::vector<std::string>& vecKeywords);
	bool ProcessExistQuery();

	bool GetResultsFromDatasources(
			const std::map<long long, KeywordEntry>& idKeywords,
			std::vector<long long>& orderedUrlStages,
			std::map<long long, long long>& mapUrlStageIDUrlID,
			std::map<long long, UrlStageEntry>& mapUrlStages);

	bool GetKeywordIDs(const std::vector<std::string>& vecKeywords, std::map<long long, KeywordEntry>& idKeywords);

	bool GetPagesByContent(
			const std::map<long long, KeywordEntry>& idKeywords,
			std::map<long long, std::vector<KeywordEntry> >& idUrlStage );

	bool GetPagesByDomain(
			const std::map<long long, KeywordEntry>& idKeywords,
			std::map<long long, std::vector<KeywordEntry> >& idUrlStage );

	bool GetPagesByMeta(
			const std::map<long long, KeywordEntry>& idKeywords,
			std::map<long long, std::vector<KeywordEntry> >& idUrlStage );

	bool GetPagesByUrlPath(
			const std::map<long long, KeywordEntry>& idKeywords,
			std::map<long long, std::vector<KeywordEntry> >& idUrlStage );

	bool GetPageRelevanceByBacklinks(
			const std::map<long long, long long>& mapUrlStageIDUrlID,
			std::map<long long, BackLinkEntry>& urlStageIDBackLinks);

	bool GetPageInfoByUrlStageID(
			const std::vector<long long>& sortedUrlStages,
			std::map<long long, PageInfo>& mapUrlStageIDPageInfo);

	bool GetPageUrlStageInfo(
			const std::map<long long, std::vector<KeywordEntry> >& idUrlStage,
			std::map<long long, long long>& mapUrlStageIDUrlID,
			std::map<long long, UrlStageProperties>& mapUrlStageIDMetaInfo);

	bool SortResults(
			const std::map<long long, UrlStageEntry >& idUrlStages,
			const std::map<long long, BackLinkEntry>& urlStageIDBackLinks,
			std::vector<long long>& sortedUrlStageIDs,
			std::map<long long, Relevance>& urlStageRelevance );

	bool GroupResults(
			std::map<long long, UrlStageEntry >& idUrlStages,
			const std::vector<long long>& sortedUrlStageIDs,
			OrderedResults& orderedResults);

	bool OutputResults(
			const std::vector<long long>& sortedUrlStageIDs,
			const std::map<long long, long long>& mapUrlStageIDUrlID,
			const std::map<long long, PageInfo>& mapUrlStagePageInfo,
			const std::map<long long, htmlparser::DatabaseUrl>& mapUrls);

	bool LogQuery(
			const std::vector<std::string>& vecKeywords,
			bool& isExistent);

	bool SaveResults(
			const std::vector<long long>& sortedUrlStageIDs,
			const std::map<long long, long long>& mapUrlStageIDUrlID);

private:
	XMLQueryRequest* xmlQueryRequest;
	database::DatabaseHelper& dbHelper;

	long long countResults;
};

}
