/**
 * @file CacheDatabaseUrl.cpp
 * @author Moritz Wagner
 * @date 30.12.2012
 */

#include "CacheDatabaseUrl.h"

#include "CacheSubdomain.h"
#include "CacheSecondLevelDomain.h"

#include <HttpUrlParser.h>
#include <DatabaseUrl.h>

#include <DatabaseLayer.h>
#include <TableColumn.h>
#include <TableDefinition.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace caching {

CacheDatabaseUrl CacheDatabaseUrl::cacheInstance;

CacheDatabaseUrl::CacheDatabaseUrl(size_t limit)
: cacheIDUrl(limit, false) {
}

CacheDatabaseUrl::~CacheDatabaseUrl() {
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrlID(database::DatabaseConnection* db, const long long& urlID) {

	if( cacheInstance.cacheIDUrl.ContainsKey(urlID) ) {
		htmlparser::DatabaseUrl url;
		cacheInstance.cacheIDUrl.GetItem(urlID,url);
		return url;
	}
	else {
		htmlparser::DatabaseUrl url(db, urlID);
		cacheInstance.cacheIDUrl.AddItem(url.GetUrlID(),url);
		return url;
	}
}

void CacheDatabaseUrl::GetByUrlID(database::DatabaseConnection* db,const std::vector<long long>& IDs,std::map<long long,htmlparser::DatabaseUrl>& urls) {

	std::vector<long long>::const_iterator iterIDs = IDs.begin();
	for(;iterIDs != IDs.end();++iterIDs) {
		std::pair<long long,htmlparser::DatabaseUrl> insertPair(*iterIDs,CacheDatabaseUrl::GetByUrlID(db,*iterIDs));
		urls.insert(insertPair);
	}
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrl(database::DatabaseConnection* db, const network::HttpUrl& url) {

	if( cacheInstance.cacheIDUrl.ContainsValue(url) ) {
		long long key = -1;
		cacheInstance.cacheIDUrl.GetByValue(url,key);
		return cacheInstance.cacheIDUrl.GetItem(key);
	}
	else {
		htmlparser::DatabaseUrl retUrl(db,url);
		cacheInstance.cacheIDUrl.AddItem(retUrl.GetUrlID(),retUrl);
		return retUrl;
	}
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(url,httpUrl);
	return GetByUrl(db, httpUrl);
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const std::string& baseUrl) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(baseUrl,url,httpUrl);
	return GetByUrl(db, httpUrl);
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const network::HttpUrl& baseUrl) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(baseUrl,url,httpUrl);
	return GetByUrl(db, httpUrl);
}

htmlparser::DatabaseUrl CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const htmlparser::DatabaseUrl& baseUrl) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(dynamic_cast<const network::HttpUrl&>(baseUrl), url, httpUrl);
	return GetByUrl(db, httpUrl);
}

void CacheDatabaseUrl::GetBySecondLevelIDSubdomainID(
		database::DatabaseConnection* db,
		const long long secondlevelID, const long long subdomainID,	const int limitIn,
		std::vector<htmlparser::DatabaseUrl>& urls) {

	database::SelectStatement stmt(database::urlsTableBase::CreateTableDefinition());
	stmt.SelectAllColumns();

	std::vector<database::WhereConditionTableColumn*> container;
	database::urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		secondlevelID,
		container );

	const database::TableDefinition* urlsTableDef = database::urlsTableBase::CreateTableDefinition();
	const database::TableColumnDefinition* urlsSubDomDef = urlsTableDef->GetConstColumnDefinitionByName("SUBDOMAIN_ID");
	database::TableColumn* colSubDom = database::TableColumn::CreateInstanceFromValue(urlsSubDomDef,subdomainID);
	if(subdomainID<=0)
		colSubDom->SetNull();

	database::WhereConditionTableColumn* pWhereCol = database::WhereConditionTableColumn::CreateInstance(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			colSubDom );
	container.push_back(pWhereCol);

	stmt.Where().AddColumns(container);
	if(limitIn>0) {
		stmt.SetLimit(limitIn);}

	database::SelectResultContainer<database::urlsTableBase> tblUrls;
	db->Select(stmt,tblUrls);
	for(tblUrls.ResetIter();!tblUrls.IsIterEnd();tblUrls.Next())
	{
		urls.push_back(htmlparser::DatabaseUrl(db, tblUrls.GetIter()));
		cacheInstance.cacheIDUrl.AddItem(urls.back().GetUrlID(),urls.back());
	}
}

}
