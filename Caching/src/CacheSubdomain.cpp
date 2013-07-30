/**
 * @file CacheSubdomain.cpp
 * @author Moritz Wagner
 * @date 19.05.2012
 */

#include "CacheSubdomain.h"

#include <DatabaseLayer.h>
#include <Exception.h>

#include "URLInvalidSubdomainIDException.h"

namespace caching {

CacheSubdomain CacheSubdomain::cacheInstance;

CacheSubdomain::CacheSubdomain(size_t limit)
: idSubdomain(limit, false)
{
}

CacheSubdomain::~CacheSubdomain()
{
}

void CacheSubdomain::GetSubdomainIDByDomain(
	database::DatabaseConnection* db,
	const std::string& subdomain,
	long long& subdomainID) {

	subdomainID = -1;
	if(!cacheInstance.idSubdomain.GetByValue(subdomain,subdomainID)) {

		//insert subdomain
		database::subdomainsTableBase tblSub;
		tblSub.Set_subdomain(subdomain);
		tblSub.InsertOrUpdate(db);

		db->LastInsertID(subdomainID);
		if(subdomainID == -1) {
			THROW_EXCEPTION(URLInvalidSubdomainIDException,subdomainID,-1);}
		cacheInstance.idSubdomain.AddItem(subdomainID,subdomain);
	}
}

void CacheSubdomain::GetDomainBySubdomainID(
	database::DatabaseConnection* db,
	const long long& subdomainID,
	std::string& subdomain) {

	if(!cacheInstance.idSubdomain.GetItem(subdomainID,subdomain)) {

		database::SelectResultContainer<database::subdomainsTableBase> results;
		database::subdomainsTableBase::GetBy_ID(db,subdomainID,results);

		if(results.Size() == 1) {
			results.ResetIter();
			database::subdomainsTableBase* pTbl(results.GetIter());
			pTbl->Get_subdomain(subdomain);
			cacheInstance.idSubdomain.AddItem(subdomainID,subdomain);
			return;
		}

		THROW_EXCEPTION(URLInvalidSubdomainIDException,subdomainID,-1);
	}
}

void CacheSubdomain::SetCapacity(const size_t capacity)
{
	cacheInstance.idSubdomain.SetLimit(capacity);
}

void CacheSubdomain::Clear(void)
{
	cacheInstance.idSubdomain.ClearItems();
}

} /* namespace caching */
