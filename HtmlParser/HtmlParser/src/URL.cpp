/*
 * URL.cpp
 *
 *  Created on: 14.01.2012
 *      Author: Moritz Wagner
 */

#include "URL.h"

#include <sstream>
#include <string.h>

#include <libxml/uri.h>

#include "UrlParser.h"
#include "TLD.h"

#include <CacheUrl.h>
#include <Tools.h>
#include <StringTools.h>
#include <Regex.h>

#include <TableDefinition.h>
#include <TableColumn.h>
#include <TableColumnDefinition.h>

#include <WhereConditionTableColumnCreateParam.h>

#include <DatabaseLayer.h>
#include <ContainerTools.h>

#include <NotImplementedException.h>
#include <URLInvalidSchemeIDException.h>
#include <URLInvalidSchemeException.h>
#include <URLInvalidSubdomainIDException.h>
#include <URLInvalidMD5ValueException.h>
#include <URLInvalidTopLevelDomainIDException.h>
#include <URLInvalidSecondLevelDomainIDException.h>

namespace htmlparser {

URL::URL()
: urlID(-1)
, schemeID(-1)
, toplevelID(-1)
, secondlevelID(-1)
, subdomainID(-1)
, isCalculated(false)
{
}

URL::~URL()
{
}

bool URL::operator<(URL const& rhs) const {

	if( this->md5.empty() || rhs.md5.empty() )
		throw;
	return this->md5 < rhs.md5;
}

bool URL::operator==(URL const& rhs) const {

	if( this->md5.empty() || rhs.md5.empty() )
		throw;
	return ( this->md5.compare(rhs.md5) == 0 );
}

bool URL::operator==(const long long& urlID) const {

	if( this->urlID == -1 || urlID == -1 )
		throw;
	return (this->urlID == urlID);
}

void URL::CalculateSchemePart(database::DatabaseConnection* connection) {

	if( scheme.empty() && schemeID == -1 )
		THROW_EXCEPTION(URLInvalidSchemeIDException, schemeID, urlID);

	if(schemeID != -1 && scheme.empty()) {

		//create by schemeID
		switch(schemeID)
		{
		case 1: //http
			scheme = "http";
			break;
		case 2: //https
			scheme = "https";
			break;

		default:
			THROW_EXCEPTION(URLInvalidSchemeIDException, schemeID, urlID);
		}
	}
	else if(schemeID == -1 && !scheme.empty()) {

		//create by scheme string
		if(scheme.compare("http") == 0) {
			schemeID = 1;
		}
		else if(scheme.compare("https") == 0) {
			schemeID = 2;
		}
		else {
			THROW_EXCEPTION(URLInvalidSchemeException,Dump());
		}
	}
	else {
		//both filled out already, no need to do anything
	}
}

void URL::CalculateDomainPart(database::DatabaseConnection* connection) {

	if(domain.empty() && secondleveldomain.empty() && secondlevelID == -1) {
		THROW_EXCEPTION(URLInvalidSecondLevelDomainIDException,urlID,secondlevelID);}

	if(!domain.empty() && secondleveldomain.empty()) {

		//calculate from domain, split in subdomain and secondleveldomain
		std::vector<std::string> domainParts;
		tools::StringTools::SplitBy(domain, ".", domainParts);
		if(domainParts.size()){
			secondleveldomain = domainParts.back();
			for(size_t i = 0; i < domainParts.size()-1; i++){
				if(i)
					subdomain.append(".");
				subdomain.append(domainParts.at(i));
			}
		} else {
			secondleveldomain = domain;
		}
	}
	else if(domain.empty() && !secondleveldomain.empty()) {
		if(!subdomain.empty())
			domain = subdomain + ".";
		domain += secondleveldomain;
	}

	if(subdomainID == -1 && !subdomain.empty()) {
		caching::CacheUrl::GetSubdomainIDByDomain(connection,subdomain,subdomainID);	}
	else if(subdomainID != -1){
		caching::CacheUrl::GetSubdomainByDomainID(connection, subdomainID, subdomain); }

	if(secondlevelID == -1 && !secondleveldomain.empty()) {
		caching::CacheUrl::GetSecondLevelIDByDomain(connection,secondleveldomain,secondlevelID);	}
	else if(secondlevelID != -1 && secondleveldomain.empty()) {
		caching::CacheUrl::GetSecondLevelByDomainID(connection, secondlevelID, secondleveldomain);}

	if(domain.empty() && !subdomain.empty())
		domain = subdomain + "." + secondleveldomain;
	else if(domain.empty())
		domain = secondleveldomain;

	//TODO:
	/*
	if(domain.empty()) {
		THROW_EXCEPTION(URLInvalidUrlException);
	}
	*/

	if(!tld.empty() && toplevelID == -1) {
		toplevelID = TLD::GetTLDIDByTLD(tld);}
	else if(tld.empty() && toplevelID != -1) {
		tld = TLD::GetTLDByID(toplevelID);}
	else {
		THROW_EXCEPTION(URLInvalidTopLevelDomainIDException,toplevelID,urlID);}
}

void URL::CalculatePortPart(database::DatabaseConnection* connection) {

	if(port.empty()) {

		if(scheme.compare("https") == 0) {
			port = "443";
		}
		else if (scheme.compare("http") == 0) {
			port = "80";
		}
		else {
			THROW_EXCEPTION(URLInvalidSchemeException,Dump());
		}
	}
}

bool URL::CalculateFullUrl(database::DatabaseConnection* connection, const bool forceRecalculate)
{
	if(isCalculated && !forceRecalculate)
		return true;

	CalculateSchemePart(connection);
	CalculateDomainPart(connection);
	CalculatePortPart(connection);

	std::stringstream ssUrl;
	ssUrl << scheme << "://" << domain << "." << tld << ":" << port;
	if(!path_part.empty() || !search_part.empty())
		ssUrl << "/";
	ssUrl << path_part;
	ssUrl << search_part;

	md5 = bot::Tools::MD5Calculator::GetMD5(ssUrl.str().c_str());

	//fragment part gets ignored for hash calculation
	if(path_part.empty() && search_part.empty() && !fragment_part.empty())
		ssUrl << "/";
	ssUrl << fragment_part;
	fullUrl = ssUrl.str();

	isCalculated = true;
	return true;
}
std::string URL::Dump() const
{
	std::string dump;
	Dump(dump);
	return dump;
}

void URL::Dump(std::string& dump) const
{
	std::stringstream ssDump;
	ssDump << "full url:  " << fullUrl << std::endl <<
	"scheme:       " << scheme << std::endl <<
	"domain:       " << domain << std::endl <<
	"subdomain:    " << subdomain << std::endl <<
	"secondlvl:    " << secondleveldomain << std::endl <<
	"tld:          " << tld << std::endl <<
	"port:         " << port << std::endl <<
	"path_part:    " << path_part << std::endl <<
	"path:         " << path << std::endl <<
	"document:     " << document << std::endl <<
	"search:       " << search_part << std::endl <<
	"fragment:     " << fragment_part << std::endl <<
	"urlID:        " << urlID << std::endl <<
	"toplevelID:   " << toplevelID << std::endl <<
	"secondlevelID:" << secondlevelID << std::endl <<
	"subdomainID:  " << subdomainID << std::endl <<
	"schemeID:     " << schemeID << std::endl<<
	"md5:          " << md5 << std::endl <<
	"auth_user:    " << auth_user << std::endl<<
	"auth_pass:    " << auth_pass << std::endl;
	dump = ssDump.str();
}

bool URL::GetBackLinks(database::DatabaseConnection* db, const long long urlID, std::map<long long,URL>& mapIDUrls)
{
	std::vector<database::WhereConditionTableColumn*> container;
	database::WhereConditionTableColumnCreateParam hyperLinkWhereParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	hyperLinkWhereParam.tableNameAlias = "theHyper";
	database::hyperlinksTableBase::GetWhereColumnsFor_TARGET_URL_ID(
		hyperLinkWhereParam,
		urlID,
		container );

	database::SelectStatement selectBackLinks(database::urlsTableBase::CreateTableDefinition(), "theUrl");
	selectBackLinks.SelectAddColumn(database::urlsTableBase::GetDefinition_ID(),"theUrl", "ID");
	selectBackLinks.GroupBy().AddGroupByFieldname("theUrl", "ID");

	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID("theLatest", "URL_ID", "theUrl", "ID", selectBackLinks);
	database::hyperlinksTableBase::AddInnerJoinLeftSideOn_TARGET_URL_ID("theHyper", "TARGET_URL_ID", "theUrl", "ID", selectBackLinks);

	database::SelectResultContainer<database::TableBase> results;
	db->Select(selectBackLinks,results);
	if( results.Size() == 0 ) {
		return true; }

	std::vector<long long> backlinkIDs;
	results.ResetIter();
	for(int i=1; !results.IsIterEnd(); i++,results.Next()) {
		long long nID = -1;

		results.GetIter()->GetConstColumnByName("ID")->Get(nID);
		backlinkIDs.push_back(nID);
	}

	caching::CacheUrl::GetBy_URL_ID(db,backlinkIDs,mapIDUrls);
	return true;
}

bool URL::PathPartIndex(database::DatabaseConnection* database, const URL& url)
{
	if(url.path_part.length() < 4)
		return true;

	std::vector<std::string> words;
	//TODO:make a better indexer for urls
	tools::Regex::Match("[^[:alpha:]]*([A-Za-z]{4,})[^[:alpha:]]*",url.path_part,words);
	tools::ContainerTools::MakeUniqueVector(words,true);

	std::vector<std::string>::iterator iterWords = words.begin();
	for(; iterWords != words.end(); ++iterWords) {

		if(iterWords->length()<4)
			continue;

		std::string word = *iterWords;


		database::dictTableBase dictKeyword;
		dictKeyword.Set_keyword(word);
		dictKeyword.Set_occurrence(1);

		std::vector<database::TableColumnDefinition*> colDefsSum;
		colDefsSum.push_back(database::dictTableBase::GetDefinition_occurrence());

		database->TransactionStart();

		try {
			dictKeyword.InsertOrUpdate(database, colDefsSum);
		}
		catch(...) {
			database->TransactionRollback();
			throw;
		}

		long long dictID = -1;
		if(!database->LastInsertID(dictID) || dictID<0){
			database->TransactionRollback();
			throw; }

		database::docurlTableBase docUrl;
		docUrl.Set_DICT_ID(dictID);
		docUrl.Set_URL_ID(url.GetUrlID());

		try {
			docUrl.InsertOrUpdate(database);
		}
		catch(database::DatabaseException& ex) {
			database->TransactionRollback();
			throw;
		}

		database->TransactionCommit();
	}

	return true;
}

bool URL::DeepMatchURL(const URL& url1, const URL& url2) {

	bool match = true;
	match &= url1.GetFullUrl().compare(url2.GetFullUrl()) == 0;
	match &= url1.GetDomain().compare(url2.GetDomain()) == 0;
	match &= url1.GetScheme().compare(url2.GetScheme()) == 0;
	match &= url1.GetSubdomain().compare(url2.GetSubdomain()) == 0;
	match &= url1.GetSecondLevelDomain().compare(url2.GetSecondLevelDomain()) == 0;
	match &= url1.GetTLD().compare(url2.GetTLD()) == 0;
	match &= url1.GetPort().compare(url2.GetPort()) == 0;
	match &= url1.GetPathPart().compare(url2.GetPathPart()) == 0;
	match &= url1.GetSearchPart().compare(url2.GetSearchPart()) == 0;
	match &= url1.GetPath().compare(url2.GetPath()) == 0;
	match &= url1.GetDocument().compare(url2.GetDocument()) == 0;
	match &= url1.GetMD5().compare(url2.GetMD5()) == 0;
	match &= url1.GetFragmentPart().compare(url2.GetFragmentPart()) == 0;

	//match &= url1.GetAuthUser().compare(url2.GetAuthUser()) == 0;
	//match &= url1.GetAuthPass().compare(url2.GetAuthPass()) == 0;

	//url1.urlID;
	match &= url1.GetSchemeID() == url2.GetSchemeID();
	match &= url1.GetTopLevelID() == url2.GetTopLevelID();
	match &= url1.GetSecondLevelID() == url2.GetSecondLevelID();
	match &= url1.GetSubdomainID() == url2.GetSubdomainID();

	return match;
}

}
