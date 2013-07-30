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

#include <Pointer.h>
#include <Exception.h>

namespace caching {

CacheDatabaseUrl CacheDatabaseUrl::cacheInstance;

CacheDatabaseUrl::CacheDatabaseUrl(size_t limit)
: cacheIDUrl(limit, false) {
}

CacheDatabaseUrl::~CacheDatabaseUrl() {
}

bool CacheDatabaseUrl::GetByUrlID(database::DatabaseConnection* db, const long long& urlID, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	htmlparser::DatabaseUrl tmp;
	if( !cacheInstance.cacheIDUrl.GetItem(urlID,tmp) ) {
		urlOut.Set(new htmlparser::DatabaseUrl(db, urlID),true);
		cacheInstance.cacheIDUrl.AddItem(urlOut.Get()->GetUrlID(),*urlOut.Get());
	}
	else {
		urlOut.Set(new htmlparser::DatabaseUrl(tmp),true);
	}
	return true;
}

void CacheDatabaseUrl::GetByUrlID(database::DatabaseConnection* db,const std::vector<long long>& IDs,std::map<long long,htmlparser::DatabaseUrl>& urls) {

	std::vector<long long>::const_iterator iterIDs(IDs.begin());
	for(;iterIDs != IDs.end();++iterIDs) {
		tools::Pointer<htmlparser::DatabaseUrl> urlOut;
		CacheDatabaseUrl::GetByUrlID(db,*iterIDs,urlOut);
		std::pair<long long,htmlparser::DatabaseUrl> insertPair(*iterIDs, *urlOut.Get());
		urls.insert(insertPair);
	}
}

bool CacheDatabaseUrl::GetByUrl(database::DatabaseConnection* db, const network::HttpUrl& url, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	long long urlID(-1);
	if(!cacheInstance.cacheIDUrl.GetByValue(url,urlID)){
		urlOut.Set(new htmlparser::DatabaseUrl(db,url),true);
		cacheInstance.cacheIDUrl.AddItem(urlOut.Get()->GetUrlID(),*urlOut.Get());
		return true; }
	else {
		return GetByUrlID(db,urlID,urlOut);	}
}

bool CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(url,httpUrl);
	return GetByUrl(db, httpUrl, urlOut);
}

bool CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const std::string& baseUrl, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(baseUrl,url,httpUrl);
	return GetByUrl(db, httpUrl, urlOut);
}

bool CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const network::HttpUrl& baseUrl, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(baseUrl,url,httpUrl);
	return GetByUrl(db, httpUrl, urlOut);
}

bool CacheDatabaseUrl::GetByUrlString(database::DatabaseConnection* db, const std::string& url, const htmlparser::DatabaseUrl& baseUrl, tools::Pointer<htmlparser::DatabaseUrl>& urlOut) {

	network::HttpUrl httpUrl;
	network::HttpUrlParser::ParseURL(dynamic_cast<const network::HttpUrl&>(baseUrl), url, httpUrl);
	return GetByUrl(db, httpUrl, urlOut);
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

	const database::TableDefinition* urlsTableDef(database::urlsTableBase::CreateTableDefinition());
	const database::TableColumnDefinition* urlsSubDomDef(urlsTableDef->GetConstColumnDefinitionByName("SUBDOMAIN_ID"));
	database::TableColumn* colSubDom(database::TableColumn::CreateInstanceFromValue(urlsSubDomDef,subdomainID));
	if(subdomainID<=0)
		colSubDom->SetNull();

	database::WhereConditionTableColumn* pWhereCol(database::WhereConditionTableColumn::CreateInstance(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			colSubDom ));
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

void CacheDatabaseUrl::Clear(void) {
	cacheInstance.cacheIDUrl.ClearItems();
}

void CacheDatabaseUrl::SetCapacity(const int capacity) {
	cacheInstance.cacheIDUrl.SetLimit(capacity);
}

size_t CacheDatabaseUrl::GetSize() {
	return cacheInstance.cacheIDUrl.GetSize();
}

size_t CacheDatabaseUrl::GetMatches() {
	return cacheInstance.cacheIDUrl.GetMatches();
}

size_t CacheDatabaseUrl::GetMisses() {
	return cacheInstance.cacheIDUrl.GetMisses();
}

}
