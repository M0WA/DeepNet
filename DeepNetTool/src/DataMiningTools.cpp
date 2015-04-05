/*
 * DataMiningTools.cpp
 *
 *  Created on: 26.09.2012
 *      Author: Moritz Wagner
 */

#include "DataMiningTools.h"

#include <Pointer.h>
#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>
#include <HashTools.h>
#include <DatabaseLayer.h>
#include <Logging.h>
#include <DataminingNotifier.h>
#include <Exception.h>

namespace toolbot {

DataMiningTools::DataMiningTools() {
}

DataMiningTools::~DataMiningTools() {
}

bool DataMiningTools::RegisterDataminingAlert(database::DatabaseConnection* db, const std::string& username, const std::string& criteria, const std::string& alertType, const std::string& alertParam) {

	database::SelectResultContainer<database::dataminingcustomerTableBase> userInfoContainer;
	database::dataminingcustomerTableBase::GetBy_login(db,username,userInfoContainer);
	if(userInfoContainer.Size() != 1) {
		log::Logging::LogError("could not find user (%zu) for %s, alert has not been registered",userInfoContainer.Size(),username.c_str());
		return false; }

	long long userID = -1;
	userInfoContainer.GetIter()->Get_ID(userID);
	if(userID <= 0) {
		log::Logging::LogError("invalid userid %lld for user %s found, alert has not been registered",userID,username.c_str());
		return false; }

	long long alertTypeNum = indexing::DataminingNotifier::NOTIFY_TYPE_EMAIL;
	if(alertType.compare("email") == 0)
		alertTypeNum = indexing::DataminingNotifier::NOTIFY_TYPE_EMAIL;

	if(alertTypeNum == indexing::DataminingNotifier::NOTIFY_TYPE_UNKNOWN) {
		log::Logging::LogError("invalid alert type specified %s, alert has not been registered",alertType.c_str());
		return false;}

	database::dataminingcriteriaTableBase criteriaTable;
	criteriaTable.Set_keyword(criteria);
	criteriaTable.Set_type(1);

	database::dataminingalertsTableBase alertTable;
	alertTable.Set_param(alertParam);
	alertTable.Set_type(alertTypeNum);

	database::dataminingcriteriaalertsTableBase critAlertMapTable;
	critAlertMapTable.Set_CUSTOMER_ID(userID);

	long long critID = -1, alertID = -1;

	try {
		db->TransactionStart();

		criteriaTable.Insert(db);
		db->LastInsertID(critID);

		alertTable.Insert(db);
		db->LastInsertID(alertID);

		critAlertMapTable.Set_DATAMININGCRITERIA_ID(critID);
		critAlertMapTable.Set_DATAMININGALERT_ID(alertID);
		critAlertMapTable.Insert(db);

		db->TransactionCommit();
	}
	catch(errors::Exception& ex) {
		db->TransactionRollback();
		log::Logging::LogError("error while inserting dataming alert (%lld, %lld), alert has not been registered",critID,alertID);
		return false;
	}
	catch(...) {
		db->TransactionRollback();
		throw;
	}

	return true;
}

bool DataMiningTools::InsertDataminingUser(database::DatabaseConnection* db, const std::string& username, const std::string& password) {

	if(username.empty()||password.empty()){
		log::Logging::LogError("empty username or password not allowed, user not created",username.c_str(),password.c_str());
		return false; }

	database::dataminingcustomerTableBase userTable;
	userTable.Set_login(username);
	userTable.Set_password(tools::HashTools::GetSHA512(password));

	long long userID = -1;
	try {
		userTable.Insert(db);
		db->LastInsertID(userID);
		log::Logging::LogTrace("inserted user %s has userID: %lld",username.c_str(),userID);
	}
	catch(errors::Exception& ex) {
		log::Logging::LogError("error while inserting datamining user, user not created");
		return false;
	}

	return true;
}

bool DataMiningTools::InsertFencedUrl(database::DatabaseConnection* db, const std::string& username, const std::string& url) {

	tools::Pointer<htmlparser::DatabaseUrl> dbUrl;
	try {
		if(!caching::CacheDatabaseUrl::GetByUrlString(db, url, dbUrl)) {
			log::Logging::LogError("could not insert url: %s",url.c_str());
			return false; }
	}
	catch(...) {
		log::Logging::LogError("exception while inserting url: %s",url.c_str());
		return false;
	}

	database::SelectResultContainer<database::dataminingcustomerTableBase> res;
	try {
		database::dataminingcustomerTableBase::GetBy_login(db,username,res);
	}
	catch(...) {
		log::Logging::LogError("exception while getting datamining username id: %s",username.c_str());
		return false;
	}
	if(res.Size() != 1) {
		log::Logging::LogError("invalid datamining username: %s",username.c_str());
		return false;
	}
	res.ResetIter();

	long long dmUserId = -1;
	res.GetConstIter()->Get_ID(dmUserId);

	database::fencedsearchTableBase tblFence;
	tblFence.Set_CUSTOMER_ID(dmUserId);
	tblFence.Set_SECONDLEVELDOMAIN_ID(dbUrl.GetConst()->GetSecondLevelID());
	try {
		tblFence.InsertOrUpdate(db);
	}
	catch(...) {
		return false;
	}

	return true;
}

}
