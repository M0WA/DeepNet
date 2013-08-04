/**
 * @file DatabaseUrl.cpp
 * @author Moritz Wagner
 * @date 29.12.2012
 */

#include "DatabaseUrl.h"

#include <TimeTools.h>
#include <HashTools.h>
#include <HttpUrlParser.h>
#include <DatabaseLayer.h>
#include <TableColumn.h>

#include <CacheSubdomain.h>
#include <CacheSecondLevelDomain.h>

#include <HttpUrlParserInvalidUrlException.h>

#include "TLD.h"

namespace htmlparser {

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, const network::HttpUrl& url)
: network::HttpUrl(url)
, urlID(-1)
, schemeID(-1)
, toplevelID(-1)
, secondlevelID(-1)
, subdomainID(-1) {

	InitByHttpUrl(db);
}

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, const long long& urlID)
: network::HttpUrl()
, urlID(urlID)
, schemeID(-1)
, toplevelID(-1)
, secondlevelID(-1)
, subdomainID(-1) {

	InitByUrlID(db, urlID);
}

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, database::urlsTableBase* urlTbl)
: network::HttpUrl()
, urlID(urlID)
, schemeID(-1)
, toplevelID(-1)
, secondlevelID(-1)
, subdomainID(-1) {

	InitByTable(db, urlTbl);
}

DatabaseUrl::~DatabaseUrl() {
}

bool DatabaseUrl::operator==(const long long& urlID) const {

	if( this->urlID == -1 || urlID == -1 )
		throw;
	return (this->urlID == urlID);
}

const long long DatabaseUrl::GetUrlID() const {

	return urlID;
}

const long long DatabaseUrl::GetSchemeID() const {

	return schemeID;
}

const long long DatabaseUrl::GetSubdomainID() const {

	return subdomainID;
}

const long long DatabaseUrl::GetSecondLevelID() const {

	return secondlevelID;
}

const long long DatabaseUrl::GetTopLevelID() const {

	return toplevelID;
}

void DatabaseUrl::InitByHttpUrl(database::DatabaseConnection* db) {

	//scheme
	if(scheme.compare("http") == 0) {
		schemeID = 1;
	}
	else if(scheme.compare("https") == 0) {
		schemeID = 2;
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}

	//topleveldomain
	if(!tld.empty()) {
		toplevelID = htmlparser::TLD::GetTLDIDByTLD(tld);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}

	//subdomain
	if(!subdomain.empty()) {
		caching::CacheSubdomain::GetSubdomainIDByDomain(db,subdomain,subdomainID);
	}

	//secondleveldomain
	if(!secondleveldomain.empty()) {
		caching::CacheSecondLevelDomain::GetSecondLevelIDByDomain(db,secondleveldomain,secondlevelID);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}

	Store(db);
}

void DatabaseUrl::InitByUrlID(database::DatabaseConnection* db, const long long& urlID) {

	database::SelectResultContainer<database::urlsTableBase> results;
	database::urlsTableBase::GetBy_ID(db,urlID,results);

	if(results.Size() != 1) {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
		return;
	}

	//convert from table
	results.ResetIter();
	InitByTable(db,results.GetIter());
}

void DatabaseUrl::InitByTable(database::DatabaseConnection* db,database::urlsTableBase* urlTbl)
{
	long long tmpPort = 80;
	urlTbl->Get_port(tmpPort);
	std::stringstream ssIn;
	ssIn << tmpPort;
	port = ssIn.str();

	urlTbl->Get_ID(this->urlID);
	urlTbl->Get_path_part(path_part);
	urlTbl->Get_search_part(search_part);
	//urlTbl->Get_fragment(fragment_part);
	urlTbl->Get_url_md5(md5);

	urlTbl->Get_SCHEME_ID(schemeID);
	urlTbl->Get_TOPLEVELDOMAIN_ID(toplevelID);

	bool hasSubdomain = !urlTbl->GetColumn_SUBDOMAIN_ID()->IsNull();
	if(hasSubdomain) {
		urlTbl->Get_SUBDOMAIN_ID(subdomainID);
	}
	else {
		subdomainID = -1;
		subdomain   = "";
	}

	urlTbl->Get_SECONDLEVELDOMAIN_ID(secondlevelID);

	InitByIDs(db);
	CalculateFullUrl();
}

void DatabaseUrl::InitByIDs(database::DatabaseConnection* db) {

	switch(schemeID)
	{
	case 1: //http
		scheme = "http";
		if(port.empty()) { port = "80"; }
		break;
	case 2: //https
		scheme = "https";
		if(port.empty()) { port = "443"; }
		break;

	default:
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
		break;
	}

	if(subdomainID > -1){
		caching::CacheSubdomain::GetDomainBySubdomainID(db, subdomainID, subdomain);
	}

	if(secondlevelID > -1) {
		caching::CacheSecondLevelDomain::GetDomainBySecondLevelID(db, secondlevelID, secondleveldomain);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}

	if(toplevelID > -1) {
		tld = TLD::GetTLDByID(toplevelID);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}
}

void DatabaseUrl::Store(database::DatabaseConnection* db) {

	if(!isCalculated)
		CalculateFullUrl(db);

	database::urlsTableBase tblUrls;
	tblUrls.Set_SCHEME_ID(schemeID);

	long long tmpPort = -1;
	std::stringstream tmpSS;
	tmpSS << port;
	tmpSS >> tmpPort;
	tblUrls.Set_port(tmpPort);

	tblUrls.Set_TOPLEVELDOMAIN_ID(toplevelID);
	tblUrls.Set_SECONDLEVELDOMAIN_ID(secondlevelID);

	if(subdomainID != -1){
		tblUrls.Set_SUBDOMAIN_ID(subdomainID); }
	else {
		tblUrls.GetColumnByName("SUBDOMAIN_ID")->SetNull(); }

	tblUrls.Set_path_part(path_part);
	tblUrls.Set_search_part(search_part);
	tblUrls.Set_found_date(tools::TimeTools::NowUTC());
	tblUrls.Set_url_md5(tools::HashTools::GetMD5(fullUrl));
	tblUrls.InsertOrUpdate(db);

	if(!db->LastInsertID(urlID)) {
		urlID = -1;
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), ""); }

	if(urlID == -1){
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), ""); }
}

bool DatabaseUrl::DeepMatchUrl(const DatabaseUrl& rhs, const bool compareAuth) const {

	bool match = network::HttpUrl::DeepMatchUrl(rhs, compareAuth);

	if(match) {
		match &= GetUrlID() == rhs.GetUrlID();
		match &= GetSchemeID() == rhs.GetSchemeID();
		match &= GetTopLevelID() == rhs.GetTopLevelID();
		match &= GetSecondLevelID() == rhs.GetSecondLevelID();
		match &= GetSubdomainID() == rhs.GetSubdomainID();
	}
	return match;
}

void DatabaseUrl::GetBackLinks(database::DatabaseConnection* db, const long long& urlID, std::map<long long,htmlparser::DatabaseUrl>& mapIDUrls) {
	//TODO: implement getting backlinks
}

}
