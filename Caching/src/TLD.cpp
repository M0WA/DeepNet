/**
 * @file TLD.cpp
 * @author Moritz Wagner
 * @date 25.03.2012
 */

#include "TLD.h"

#include <DatabaseLayer.h>
#include <TableDefinition.h>

#include <ContainerTools.h>
#include <Pointer.h>

namespace caching {

TLD TLD::tld;

std::map<long long, std::string> TLD::mapIdTld;
std::map<std::string, long long> TLD::mapTldId;

threading::Mutex TLD::initMutex;
bool TLD::isInitialized = false;

bool TLD::InitTLDCache(database::DatabaseConnection* db)
{
	initMutex.Lock();
	if(isInitialized) {
		initMutex.Unlock();
		return true; }//already initialized

	bool success(tld.Init(db));
	initMutex.Unlock();
	return success;
}

const std::string TLD::GetTLDByID(const long long tldID)
{
	if(mapIdTld.count(tldID) == 0)
		return "";
	return mapIdTld[tldID];
}

const long long TLD::GetTLDIDByTLD(const std::string& tld)
{
	if(mapTldId.count(tld) == 0)
		return -1;

	return mapTldId[tld];
}

bool TLD::Init(database::DatabaseConnection* db)
{
	isInitialized = true;

	tools::Pointer<database::TableDefinition> tldTblDef(database::topleveldomainsTableBase::CreateTableDefinition());
	database::SelectStatement selectTLD(tldTblDef.GetConst());
	selectTLD.SelectAllColumns();

	database::SelectResultContainer<database::topleveldomainsTableBase> selectTLDResult;
	db->Select(selectTLD,selectTLDResult);

	selectTLDResult.ResetIter();
	for(;!selectTLDResult.IsIterEnd();selectTLDResult.Next()) {

		long long tldID = -1;
		selectTLDResult.GetIter()->Get_ID(tldID);
		if(tldID < 0){
			return false; }

		std::string tld = "";
		selectTLDResult.GetIter()->Get_tld(tld);
		if(tld.empty()){
			return false;}

		mapIdTld[tldID] = tld;
		mapTldId[tld] = tldID;
	}
	return true;
}

void TLD::GetTLDStrings(std::vector<std::string>& tlds) {
	tools::ContainerTools::Map1ToVector(mapTldId,tlds);
}

}
