/**
 * @file DatabaseUrl.cpp
 * @author Moritz Wagner
 * @date 29.12.2012
 */

#include "DatabaseUrl.h"

#include <TimeTools.h>
#include <HttpUrlParser.h>
#include <DatabaseLayer.h>
#include <TableColumn.h>

#include <CacheSubdomain.h>
#include <CacheSecondLevelDomain.h>
#include <CacheUrlPathPart.h>
#include <CacheUrlSearchPart.h>

#include <HttpUrlParserInvalidUrlException.h>

#include "TLD.h"

namespace htmlparser {

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, const network::HttpUrl& url)
: network::HttpUrl(url)
, urlID(-1)
, schemeID(-1)
, subdomainID(-1)
, secondlevelID(-1)
, toplevelID(-1)
, urlPathPartID(-1)
, urlSearchPartID(-1) {

	InitByHttpUrl(db);
}

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, const long long& urlID)
: network::HttpUrl()
, urlID(urlID)
, schemeID(-1)
, subdomainID(-1)
, secondlevelID(-1)
, toplevelID(-1)
, urlPathPartID(-1)
, urlSearchPartID(-1){

	InitByUrlID(db, urlID);
}

DatabaseUrl::DatabaseUrl(database::DatabaseConnection* db, database::urlsTableBase* urlTbl)
: network::HttpUrl()
, urlID(urlID)
, schemeID(-1)
, subdomainID(-1)
, secondlevelID(-1)
, toplevelID(-1)
, urlPathPartID(-1)
, urlSearchPartID(-1) {

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

const long long DatabaseUrl::GetUrlPathPartID() const {

	return urlPathPartID;
}

const long long DatabaseUrl::GetUrlSearchPartID() const {

	return urlSearchPartID;
}

void DatabaseUrl::InitByHttpUrl(database::DatabaseConnection* db) {

	//scheme
	if(scheme.compare("http") == 0) {
		schemeID = 1; }
	else if(scheme.compare("https") == 0) {
		schemeID = 2; }
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), ""); }

	//subdomain
	caching::CacheSubdomain::GetSubdomainIDByDomain(db,subdomain,subdomainID);

	//secondleveldomain
	if(!secondleveldomain.empty()) {
		caching::CacheSecondLevelDomain::GetSecondLevelIDByDomain(db,secondleveldomain,secondlevelID); }
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), ""); }

	//topleveldomain
	if(!tld.empty()) {
		toplevelID = htmlparser::TLD::GetTLDIDByTLD(tld); }
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), ""); }

	//path part
	caching::CacheUrlPathPart::GetIDByUrlPathPart(db,path_part,urlPathPartID);

	//search part
	caching::CacheUrlSearchPart::GetIDByUrlSearchPart(db,search_part,urlSearchPartID);

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
	urlTbl->Get_SCHEME_ID(schemeID);
	urlTbl->Get_TOPLEVELDOMAIN_ID(toplevelID);
	urlTbl->Get_SUBDOMAIN_ID(subdomainID);
	urlTbl->Get_SECONDLEVELDOMAIN_ID(secondlevelID);
	urlTbl->Get_URLPATHPART_ID(urlPathPartID);
	urlTbl->Get_URLSEARCHPART_ID(urlSearchPartID);

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
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
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

	if(urlPathPartID > -1) {
		caching::CacheUrlPathPart::GetUrlPathPartByID(db, urlPathPartID, path_part);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}

	if(urlSearchPartID > -1) {
		caching::CacheUrlSearchPart::GetUrlSearchPartByID(db, urlSearchPartID, search_part);
	}
	else {
		THROW_EXCEPTION(network::HttpUrlParserInvalidUrlException, GetFullUrl(), "");
	}
}

void DatabaseUrl::Store(database::DatabaseConnection* db) {

	if(!isCalculated)
		CalculateFullUrl(db);

	database::urlsTableBase tblUrls;

	long long tmpPort = -1;
	std::stringstream tmpSS;
	tmpSS << port;
	tmpSS >> tmpPort;

	tblUrls.Set_SCHEME_ID(schemeID);
	tblUrls.Set_SUBDOMAIN_ID(subdomainID);
	tblUrls.Set_SECONDLEVELDOMAIN_ID(secondlevelID);
	tblUrls.Set_TOPLEVELDOMAIN_ID(toplevelID);
	tblUrls.Set_port(tmpPort);
	tblUrls.Set_URLPATHPART_ID(urlPathPartID);
	tblUrls.Set_URLSEARCHPART_ID(urlSearchPartID);
	tblUrls.Set_found_date(tools::TimeTools::NowUTC());
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
		match &= GetUrlPathPartID() == rhs.GetUrlPathPartID();
		match &= GetUrlSearchPartID() == rhs.GetUrlSearchPartID();
	}
	return match;
}

void DatabaseUrl::GetBackLinks(database::DatabaseConnection* db, const long long& urlID, std::map<long long,htmlparser::DatabaseUrl>& mapIDUrls) {
	//TODO: implement getting backlinks
}

}
