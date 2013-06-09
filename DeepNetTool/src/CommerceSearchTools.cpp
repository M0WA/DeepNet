/*
 * CommerceSearchTools.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchTools.h"

#include <DatabaseLayer.h>
#include <HashTools.h>

namespace toolbot {

CommerceSearchTools::CommerceSearchTools() {

}

CommerceSearchTools::~CommerceSearchTools() {
}

bool CommerceSearchTools::AddCustomer(database::DatabaseConnection* db,const std::string& username, const std::string& password, const std::string& domain, const long long revisitInterval)
{
	//insert into customers table
	database::customersTableBase customerTbl;
	customerTbl.Set_login(username);
	customerTbl.Set_password(tools::HashTools::GetSHA512(password));

	db->TransactionStart();
	try {
		customerTbl.Insert(db);
	} catch(...) {
		db->TransactionRollback();
		throw;
	}

	long long customerId = -1;
	if(!db->LastInsertID(customerId)){
		db->TransactionRollback();
		return false; }

	//insert into customerdomains table
	database::customerdomainsTableBase customerDomainTbl;
	customerDomainTbl.Set_CUSTOMER_ID(customerId);
	customerDomainTbl.Set_domain(domain);
	customerDomainTbl.Set_revisitInterval(revisitInterval);
	//TODO: make isDomainRegex configurable
	customerDomainTbl.Set_isDomainRegex(0);
	try {
		customerDomainTbl.Insert(db);
	} catch(...) {
		db->TransactionRollback();
		throw;
	}

	long long customerDomainID = -1;
	if(!db->LastInsertID(customerDomainID)){
		db->TransactionRollback();
		return false; }

	database::customersynccrawlerTableBase customerSyncCrawler;
	customerSyncCrawler.Set_CRAWLERSESSION_ID(0);
	customerSyncCrawler.Set_CUSTOMERDOMAIN_ID(customerDomainID);
	try {
		customerSyncCrawler.Insert(db);
	} catch(...) {
		db->TransactionRollback();
		throw;
	}

	db->TransactionCommit();
	return true;
}

}
