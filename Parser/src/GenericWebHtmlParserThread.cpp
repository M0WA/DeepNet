/*
 * GenericWebHtmlParserThread.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebHtmlParserThread.h"

#include <Logging.h>
#include <ContainerTools.h>
#include <TimeTools.h>
#include <PerformanceCounter.h>
#include <Exception.h>
#include <DatabaseLayer.h>
#include <TableColumn.h>

#include <CacheDatabaseUrl.h>
#include <CacheParsed.h>
#include <CacheSubdomain.h>
#include <CacheSecondLevelDomain.h>
#include <CacheUrlPathPart.h>
#include <CacheUrlSearchPart.h>

#include <HtmlParserFactory.h>
#include <IHtmlParser.h>
#include <HttpUrlParserException.h>
#include <DatabaseUrl.h>
#include <HttpUrl.h>
#include <TLD.h>

#include "HtmlParserEntry.h"

namespace parser {

GenericWebHtmlParserThread::GenericWebHtmlParserThread() {
}

GenericWebHtmlParserThread::~GenericWebHtmlParserThread() {
}

bool GenericWebHtmlParserThread::ParsePage(const HtmlParserEntry& entry,tools::Pointer<htmlparser::IHtmlParserResult>& result) {

	const std::vector<network::HttpUrl> &hyperLinks(result.Get()->hyperlinks),
			&imagesLinks(result.Get()->images),
			videosLinks; //TODO: video links

	const std::vector< std::pair<std::string,std::string> >& meta(result.Get()->meta);

	std::vector< std::string > content;
	tools::ContainerTools::VectorPair2ToVector(result.Get()->content,content);

	//make link strings unique
	std::vector<network::HttpUrl> uniqueImages;
	tools::ContainerTools::MakeUniqueVector(imagesLinks,uniqueImages);

	//make link strings unique
	std::vector<network::HttpUrl> uniqueLinks;
	tools::ContainerTools::MakeUniqueVector(hyperLinks,uniqueLinks);

	PERFORMANCE_LOG_START;
	caching::CacheParsed::CacheParsedEntry entryCache(
		entry.urlID,
		entry.url,
		entry.urlStageID,
		content,
		meta);
	caching::CacheParsed::Add(entryCache);
	PERFORMANCE_LOG_STOP("committing parsed page to indexer cache");

	PERFORMANCE_LOG_RESTART;
	std::vector<caching::DatabaseUrl> dbLinks;
	InsertLinks(DB().Connection(),entry, uniqueLinks, dbLinks);
	PERFORMANCE_LOG_STOP("inserting found links from parsed page");

	PERFORMANCE_LOG_RESTART;
	InsertImages(DB().Connection(),entry,uniqueImages,result);
	PERFORMANCE_LOG_STOP("inserting found images from parsed page");

	PERFORMANCE_LOG_RESTART;
	InsertMeta(DB().Connection(),entry, meta);
	PERFORMANCE_LOG_STOP("inserting metainformation from parsed page");

	OnAfterParsePage(entry,result,content,dbLinks,uniqueImages);
	return true;
}

void GenericWebHtmlParserThread::InsertImages(database::DatabaseConnection* db,const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& images,tools::Pointer<htmlparser::IHtmlParserResult>& result)
{
	if(images.size() == 0)
		return;

	std::vector<network::HttpUrl>::const_iterator iterImages(images.begin());
	for(;iterImages != images.end(); ++iterImages) {

		database::imagesTableBase imgs;
		long long idSubdomain(-1),idSecondLevelDomain(-1),
		          idTLD(-1), idUrlPathPart(-1),
		          idUrlSearchPart(-1);
		try
		{
			idTLD = caching::TLD::GetTLDIDByTLD(iterImages->GetTLD());
			caching::CacheSubdomain::GetSubdomainIDByDomain(db,iterImages->GetSubdomain(),idSubdomain);
			caching::CacheSecondLevelDomain::GetSecondLevelIDByDomain(db,iterImages->GetSecondLevelDomain(),idSecondLevelDomain);
			caching::CacheUrlPathPart::GetIDByUrlPathPart(db,iterImages->GetPathPart(), idUrlPathPart);
			caching::CacheUrlSearchPart::GetIDByUrlSearchPart(db,iterImages->GetSearchPart(), idUrlSearchPart);
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert domains from image url to cache: " + iterImages->GetFullUrl() );
			continue;
		}

		imgs.Set_SUBDOMAIN_ID(idSubdomain);
		imgs.Set_SECONDLEVELDOMAIN_ID(idSecondLevelDomain);

		imgs.Set_TOPLEVELDOMAIN_ID(idTLD);
		imgs.Set_SCHEME_ID(1);
		imgs.Set_port(80);
		imgs.Set_URLPATHPART_ID(idUrlPathPart);
		imgs.Set_URLSEARCHPART_ID(idUrlSearchPart);

		imgs.Set_found_date(tools::TimeTools::NowUTC());

		try
		{
			imgs.InsertOrUpdate(db);
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert image url to database: " + iterImages->GetFullUrl() );
			continue;
		}

		long long imageUrlID(-1);
		if(!db->LastInsertID(imageUrlID) || imageUrlID == -1) {
			log::Logging::LogInfo("could not get image url id: " + iterImages->GetFullUrl() );
			continue;
		}

		database::imagelinksTableBase mapTbl;
		mapTbl.Set_IMAGE_URL_ID(imageUrlID);
		mapTbl.Set_TARGET_URL_ID(result.Get()->url.GetUrlID());
		mapTbl.Set_URLSTAGE_ID(entry.urlStageID);

		try
		{
			mapTbl.InsertOrUpdate(db);
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert image url to database: " + iterImages->GetFullUrl() );
			continue;
		}
	}
}

void GenericWebHtmlParserThread::InsertLinks(database::DatabaseConnection* db,const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& hyperlinks,std::vector<caching::DatabaseUrl>& dbLinks)
{
	if(hyperlinks.size() == 0)
		return;

	//convert to URLs
	std::map<caching::DatabaseUrl,long long> mapUrls;
	std::vector<network::HttpUrl>::const_iterator iterUrls(hyperlinks.begin());
	for(;iterUrls != hyperlinks.end();++iterUrls) {

		//insert into cache and database
		//insert into syncurls/syncdomains table done by trigger

		try {
			tools::Pointer<caching::DatabaseUrl> urlLink;
			if(caching::CacheDatabaseUrl::GetByUrl(db,*iterUrls,urlLink)) {
				dbLinks.push_back(*urlLink.Get());
				mapUrls.insert(std::pair<caching::DatabaseUrl,long long>(*urlLink.Get(),urlLink.Get()->GetUrlID()));
			}
			else {
				if(log::Logging::IsLogLevelTrace()) {
					log::Logging::LogTrace(
							"error while trying to add url %s to database",iterUrls->GetFullUrl().c_str());
				}
			}
		}
		CATCH_EXCEPTION(const network::HttpUrlParserException,ex,1)
			if(log::Logging::IsLogLevelTrace()) {
				log::Logging::LogTrace(
						"exception while trying to add url %s to database",iterUrls->GetFullUrl().c_str());
			}
		}
	}

	long long internLinks(0), externLinks(0), secondLevelID(entry.url.GetSecondLevelID());
	if(mapUrls.size()>0)
	{
		std::vector<database::TableBase> vecLinks;
		std::map<caching::DatabaseUrl,long long>::const_iterator iterInsertLinks(mapUrls.begin());
		for(int i=0; iterInsertLinks != mapUrls.end(); i++,++iterInsertLinks) {

			if(iterInsertLinks->first.GetSecondLevelID() == secondLevelID) {
				internLinks++;}
			else {
				externLinks++;}

			if(entry.urlID <= 0 || entry.urlStageID <=0 || iterInsertLinks->second<=0){
				log::Logging::LogError(
						"error while inserting links, invalid ids: \nurlID: %ll urlStageID: %ll %s",
						entry.urlID, entry.urlStageID, iterInsertLinks->first.GetFullUrl().c_str()
				);
				i--;
				continue;}

			std::vector<database::TableColumnDefinition*> colDefsSum;
			colDefsSum.push_back(database::hyperlinksTableBase::GetDefinition_count());

			database::hyperlinksTableBase tblLinks;
			tblLinks.Set_URLSTAGE_ID(entry.urlStageID);
			tblLinks.Set_TARGET_URL_ID(iterInsertLinks->second);
			tblLinks.Set_count(1);
			tblLinks.InsertOrUpdate(db,colDefsSum);
		}
	}

	UpdateUrlstageInfos(db,internLinks,externLinks,entry.urlID,entry.urlStageID);
}

void GenericWebHtmlParserThread::InsertMeta(database::DatabaseConnection* db,const HtmlParserEntry& entry, const std::vector<std::pair<std::string,std::string> >& meta)
{
	std::string tmpMeta;
	std::vector<std::pair<std::string,std::string> >::const_iterator iterMeta(meta.begin());
	std::vector<database::metainfoTableBase> vecMeta;
	for(;iterMeta!=meta.end();++iterMeta) {

		const std::string* metaValue(&iterMeta->second);
		if(metaValue->length() > 512) {
			tmpMeta.clear();
			tmpMeta.append(iterMeta->second.c_str(),512);
			metaValue = &tmpMeta; }

		database::metainfoTableBase tblMeta;
		tblMeta.Set_URLSTAGE_ID(entry.urlStageID);
		tblMeta.Set_value(*metaValue);

		if(iterMeta->first.compare("keywords") == 0) {
			tblMeta.Set_type(1);
			tblMeta.Insert(db);}
		else if (iterMeta->first.compare("description") == 0){
			tblMeta.Set_type(2);
			tblMeta.Insert(db);}
		else if (iterMeta->first.compare("title") == 0){
			tblMeta.Set_type(3);
			tblMeta.Insert(db);}
	}
}

void GenericWebHtmlParserThread::UpdateUrlstageInfos(
	database::DatabaseConnection* db,
	const long long internLinks,
	const long long externLinks,
	const long long urlID,
	const long long urlstageID)
{
	//TODO: update parameter `html_errors` here also

	std::vector<database::WhereConditionTableColumn*> container;

	database::urlstagesTableBase::GetWhereColumnsFor_URL_ID(
		database::WhereConditionTableColumnCreateParam(
			database::EQUALS,
			database::INITIAL_COMPOSITE_OPERATOR_TYPE),
		urlID,
		container);

	database::urlstagesTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(
			database::EQUALS,
			database::AND),
		urlstageID,
		container );

	database::TableBaseUpdateParam update;
	update.limit = 1;
	update.whereCols = container;
	update.onlyDirtyColumns = true;

	database::urlstagesTableBase tblUrl;
	tblUrl.Set_int_links(internLinks);
	tblUrl.Set_ext_links(externLinks);
	tblUrl.Update(db,update);
}

}
