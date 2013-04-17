/**
 * @file CacheSecondLevelDomain.cpp
 * @author Moritz Wagner
 * @date 19.05.2012
 */

#include "CacheSecondLevelDomain.h"

#include <DatabaseLayer.h>
#include <Exception.h>

#include "URLInvalidSecondLevelDomainIDException.h"

namespace caching {

CacheSecondLevelDomain CacheSecondLevelDomain::cacheInstance;

CacheSecondLevelDomain::CacheSecondLevelDomain(size_t limit)
: idSecondLevelDomain(limit, false)
{
}

CacheSecondLevelDomain::~CacheSecondLevelDomain()
{
}

void CacheSecondLevelDomain::GetSecondLevelIDByDomain(
	database::DatabaseConnection* connection,
	const std::string& secondleveldomain,
	long long& secondleveldomainID) {

	secondleveldomainID = -1;
	if(!cacheInstance.idSecondLevelDomain.GetByValue(secondleveldomain,secondleveldomainID)) {

		//insert second level domain
		database::secondleveldomainsTableBase tblSnd;
		tblSnd.Set_domain(secondleveldomain);
		tblSnd.InsertOrUpdate(connection);

		connection->LastInsertID(secondleveldomainID);
		cacheInstance.idSecondLevelDomain.AddItem(secondleveldomainID,secondleveldomain);
	}
}

void CacheSecondLevelDomain::GetDomainBySecondLevelID(
	database::DatabaseConnection* connection,
	const long long& secondleveldomainID,
	std::string& secondleveldomain) {

	if(!cacheInstance.idSecondLevelDomain.GetItem(secondleveldomainID,secondleveldomain)) {

		database::SelectResultContainer<database::secondleveldomainsTableBase> results;
		database::secondleveldomainsTableBase::GetBy_ID(connection,secondleveldomainID,results);

		if(results.Size() == 1) {
			results.ResetIter();
			database::secondleveldomainsTableBase* pTbl = results.GetIter();
			pTbl->Get_domain(secondleveldomain);
			cacheInstance.idSecondLevelDomain.AddItem(secondleveldomainID,secondleveldomain);
			return;
		}

		THROW_EXCEPTION(URLInvalidSecondLevelDomainIDException,secondleveldomainID,-1);
	}
}

void CacheSecondLevelDomain::SetCapacity(const size_t capacity)
{
	cacheInstance.idSecondLevelDomain.SetLimit(capacity);
}

void CacheSecondLevelDomain::Clear(void)
{
	cacheInstance.idSecondLevelDomain.ClearItems();
}

} /* namespace caching */
