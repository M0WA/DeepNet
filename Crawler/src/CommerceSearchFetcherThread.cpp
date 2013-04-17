/**
 * @file CommerceSearchFetcherThread.cpp
 * @author Moritz Wagner
 * @date 24.07.2012
 */

//TODO: put this in config file
//TODO: handle pages where crawling lasts longer than 23 hours
#define MAX_AGE_MINUTES_SECONDLEVELDOMAIN 			60 * 23     //23 hours
#define RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN 	1  			//1 day
#define RESCHEDULE_MAX_AGE_DAYS_URL             	1  			//1 day
#define MAX_CUSTOMERDOMAINS_PER_THREAD              3           //max. 3 customer domains scanned in parallel

#include "CommerceSearchFetcherThread.h"

#include <CacheDatabaseUrl.h>

#include <TimeTools.h>
#include <Logging.h>
#include <PerformanceCounter.h>
#include <TableColumn.h>

#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace crawler {

CommerceSearchFetcherThread::CommerceSearchFetcherThread()
: UrlFetcherThread() {
}

CommerceSearchFetcherThread::~CommerceSearchFetcherThread() {
}


bool CommerceSearchFetcherThread::GetNextSecondLevelDomain()
{
	//fetch all possible customers and populate mapCustDomIdProperties and customerDomainIds
	if(mapCustDomIdProperties.size()==0) {

		database::SelectStatement selectCustDom(database::customerdomainsTableBase::CreateTableDefinition());
		selectCustDom.SelectAllColumns();

		database::SelectResultContainer<database::customerdomainsTableBase> tblCustDomains;
		DB().Connection()->Select(selectCustDom,tblCustDomains);

		std::string domainName;
		long long customerDomainId = -1, customerId = -1, revisitInterval = -1;
		std::map<htmlparser::DatabaseUrl,long long> urls;
		tblCustDomains.ResetIter();
		for(;!tblCustDomains.IsIterEnd(); tblCustDomains.Next()) {
			domainName.clear();
			urls.clear();
			customerDomainId = -1, customerId = -1, revisitInterval = -1;

			tblCustDomains.GetIter()->Get_ID(customerDomainId);
			tblCustDomains.GetIter()->Get_CUSTOMER_ID(customerId);
			tblCustDomains.GetIter()->Get_domain(domainName);
			tblCustDomains.GetIter()->Get_revisitInterval(revisitInterval);

			//TODO: domain name is a regex
			htmlparser::DatabaseUrl curUrl = caching::CacheDatabaseUrl::GetByUrlString(DB().Connection(), "http://"+domainName+"/");
			urls[curUrl] = curUrl.GetUrlID();

			CustomerDomainProperties custDomProp(urls.begin()->first);
			custDomProp.customerDomainId = customerDomainId;
			custDomProp.customerId       = customerId;
			custDomProp.revisitInterval  = revisitInterval;
			mapCustDomIdProperties.insert(std::pair<long long,CustomerDomainProperties>(customerDomainId,custDomProp));
		}
	}

	//check if some customer domains in cache are too old
	if(activeCustomerDomainIds.size() >= 0) {
		std::map<long long,time_t>::iterator iterActive;
		bool finished = false;
		while(!finished){
			iterActive = activeCustomerDomainIds.begin();
			for(;iterActive != activeCustomerDomainIds.end(); ++iterActive) {
				if(time(0) > (iterActive->second + (60*MAX_AGE_MINUTES_SECONDLEVELDOMAIN))) {
					finished = false;
					activeCustomerDomainIds.erase(iterActive);
					break;}
			}
			finished = true;
		}
	}

	//if necessary, fetch the customer domains ids for this thread and populate activeCustomerDomainIds
	if( activeCustomerDomainIds.size() == 0 ) {

		database::TableBaseUpdateParam paramSchedule;
		paramSchedule.limit = MAX_CUSTOMERDOMAINS_PER_THREAD;
		paramSchedule.onlyDirtyColumns = true;

		//set crawlersessionid for customer domains to be scheduled
		database::customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(), database::WhereCondition::InitialComp()),
			tools::TimeTools::NowUTC(),
			paramSchedule.whereCols);

		database::customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
			crawlerSessionID,
			paramSchedule.whereCols);

		database::customersynccrawlerTableBase custSync;
		custSync.Set_scheduled(tools::TimeTools::NowUTCAdd(RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN));
		custSync.Set_CRAWLERSESSION_ID(crawlerSessionID);

		custSync.Update(DB().Connection(),paramSchedule);

		//fetch reserved customerdomains
		database::SelectResultContainer<database::customersynccrawlerTableBase> syncTbls;
		database::customersynccrawlerTableBase::GetBy_CRAWLERSESSION_ID(DB().Connection(),crawlerSessionID,syncTbls);
		if(syncTbls.Size() == 0) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"no domain found for commerce search");
			OnIdle();
			return false;
		}

		//populate activeCustomerDomainIds
		syncTbls.ResetIter();
		for(;!syncTbls.IsIterEnd(); syncTbls.Next()) {
			long long customerDomainId = -1;
			syncTbls.GetIter()->Get_CUSTOMERDOMAIN_ID(customerDomainId);
			activeCustomerDomainIds[customerDomainId] = time(0); }


		database::TableBaseUpdateParam paramReschedule;
		paramReschedule.limit = -1;
		paramReschedule.onlyDirtyColumns = true;

		//release and reschedule customer domains
		database::customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(),	database::WhereCondition::InitialComp()),
			tools::TimeTools::NowUTC(),
			paramReschedule.whereCols);

		database::customersynccrawlerTableBase custSyncRelease;
		custSyncRelease.Set_scheduled(tools::TimeTools::NowUTCAdd(RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN));
		custSyncRelease.Set_CRAWLERSESSION_ID(0);

		custSyncRelease.Update(DB().Connection(),paramReschedule);
	}

	return true;
}

bool CommerceSearchFetcherThread::ReserveNextUrls(std::vector<long long>& urlIDs)
{
	urlIDs.clear();

	//fetch a new customer if neccessary
	if( activeCustomerDomainIds.size() == 0 ) {

		if(!GetNextSecondLevelDomain()) {
			OnIdle();
			if( !activeCustomerDomainIds.size() ) {
				return false; }
		}

		//fetch urls for all customers
		std::map<long long,time_t>::const_iterator iterActive = activeCustomerDomainIds.begin();
		for(;iterActive != activeCustomerDomainIds.end();++iterActive) {

			//fetch urls for each customer
			long long customerDomainId = iterActive->first;

			std::vector<htmlparser::DatabaseUrl> urlsTbls;
			caching::CacheDatabaseUrl::GetBySecondLevelIDSubdomainID(
				DB().Connection(),
				mapCustDomIdProperties.at(customerDomainId).url.GetSecondLevelID(),
				mapCustDomIdProperties.at(customerDomainId).url.GetSubdomainID(),
				fetcherThreadParam->maxPerSelect,
				urlsTbls);

			//reschedule urls
			std::vector<htmlparser::DatabaseUrl>::const_iterator iterUrlsTbls = urlsTbls.begin();
			for(; iterUrlsTbls != urlsTbls.end(); ++iterUrlsTbls) {
				database::customersyncurlTableBase syncTbl;
				syncTbl.Set_URL_ID(iterUrlsTbls->GetUrlID());
				syncTbl.Set_scheduled(tools::TimeTools::NowUTCAdd(RESCHEDULE_MAX_AGE_DAYS_URL));
				syncTbl.InsertOrUpdate(DB().Connection());
			}
		}
	}

	if(urlIDs.size() == 0){
		OnIdle(); }

	return true;
}

}
