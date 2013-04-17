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

#include <HtmlSAX2Document.h>
#include <HttpUrlParserException.h>
#include <DatabaseUrl.h>
#include <HttpUrl.h>
#include <TLD.h>

namespace parser {

GenericWebHtmlParserThread::GenericWebHtmlParserThread() {
}

GenericWebHtmlParserThread::~GenericWebHtmlParserThread() {
}

bool GenericWebHtmlParserThread::ParsePage(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document) {

	PERFORMANCE_LOG_START;

	const std::vector<network::HttpUrl> &hyperLinks = document.HyperLinks(),
			&imagesLinks = document.Images(),
			videosLinks;

	std::vector< std::string > content;
	tools::ContainerTools::VectorPair2ToVector(document.Content(),content);

	std::vector<std::string> title, description;
	const std::vector< std::pair<std::string,std::string> >& meta = document.Meta();
	std::vector< std::pair<std::string,std::string> >::const_iterator iterTmp = meta.begin();
	for(;iterTmp != meta.end();++iterTmp) {
		if(iterTmp->first.compare("title") == 0) {
			title.push_back(iterTmp->second);
		}
		else if(iterTmp->first.compare("description") == 0) {
			description.push_back(iterTmp->second);
		}
	}

	//TODO:
	//parsedDoc->GetVideos(videosLinks);

	PERFORMANCE_LOG_RESTART;
	caching::CacheParsed::CacheParsedEntry entryCache(
		entry.urlID,
		entry.url,
		entry.urlStageID,
		content,
		meta);
	caching::CacheParsed::Add(entryCache);
	PERFORMANCE_LOG_STOP("committing parsed page to indexer cache");

	PERFORMANCE_LOG_RESTART;
	InsertLinks(entry, hyperLinks);
	PERFORMANCE_LOG_STOP("inserting found links from parsed page");

	PERFORMANCE_LOG_RESTART;
	InsertImages(entry,imagesLinks,document);
	PERFORMANCE_LOG_STOP("inserting found images from parsed page");

	PERFORMANCE_LOG_RESTART;
	InsertMeta(entry, meta);
	PERFORMANCE_LOG_STOP("inserting metainformation from parsed page");

	return true;
}

void GenericWebHtmlParserThread::InsertImages(const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& imagesIn,const htmlparser::HtmlSAX2Document& document)
{
	if(imagesIn.size() == 0)
		return;

	//make link strings unique
	std::vector<network::HttpUrl> images;
	tools::ContainerTools::MakeUniqueVector(imagesIn,images);

	std::vector<network::HttpUrl>::const_iterator iterImages = images.begin();
	for(;iterImages != images.end(); ++iterImages) {

		database::imagesTableBase imgs;
		try
		{
			const std::string& subdomain = iterImages->GetSubdomain();
			long long id = -1;
			if(!subdomain.empty()){
				caching::CacheSubdomain::GetSubdomainIDByDomain(DB().Connection(),subdomain,id);
				imgs.Set_SUBDOMAIN_ID(id);
			}
			else {
				imgs.GetColumnByName("SUBDOMAIN_ID")->SetNull();
			}

			id = -1;
			caching::CacheSecondLevelDomain::GetSecondLevelIDByDomain(DB().Connection(),iterImages->GetSecondLevelDomain(),id);
			imgs.Set_SECONDLEVELDOMAIN_ID(id);
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert domains from image url to cache: " + iterImages->GetFullUrl() );
			continue;
		}

		imgs.Set_TOPLEVELDOMAIN_ID(htmlparser::TLD::GetTLDIDByTLD(iterImages->GetTLD()));
		imgs.Set_SCHEME_ID(1);
		imgs.Set_port(80);
		imgs.Set_path_part(iterImages->GetPathPart());
		imgs.Set_search_part(iterImages->GetSearchPart());
		imgs.Set_found_date(tools::TimeTools::NowUTC());
		imgs.Set_url_md5(iterImages->GetMD5());

		try
		{
			imgs.InsertOrUpdate(DB().Connection());
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert image url to database: " + iterImages->GetFullUrl() );
			continue;
		}

		long long imageUrlID = -1;
		if(!DB().Connection()->LastInsertID(imageUrlID) || imageUrlID) {
			log::Logging::LogInfo("could not get image url id: " + iterImages->GetFullUrl() );
			continue;
		}

		database::imagelinksTableBase mapTbl;
		mapTbl.Set_IMAGE_URL_ID(imageUrlID);
		mapTbl.Set_TARGET_URL_ID(document.Url().GetUrlID());
		mapTbl.Set_URLSTAGE_ID(entry.urlStageID);

		try
		{
			mapTbl.InsertOrUpdate(DB().Connection());
		}
		catch(...)
		{
			log::Logging::LogInfo("could not insert image url to database: " + iterImages->GetFullUrl() );
			continue;
		}
	}
}

void GenericWebHtmlParserThread::InsertLinks(const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& hyperlinks)
{
	if(hyperlinks.size() == 0)
		return;

	//make link strings unique
	std::vector<network::HttpUrl> uniqueLinks;
	tools::ContainerTools::MakeUniqueVector(hyperlinks,uniqueLinks);

	//convert to URLs
	std::map<htmlparser::DatabaseUrl,long long> mapUrls;
	std::vector<network::HttpUrl>::const_iterator iterUrls = uniqueLinks.begin();
	for(;iterUrls != uniqueLinks.end();++iterUrls) {

		//insert into cache and database
		//insert into syncurls/syncdomains table done by trigger

		try {
			htmlparser::DatabaseUrl urlLink = caching::CacheDatabaseUrl::GetByUrl(DB().Connection(),*iterUrls);
			mapUrls.insert(std::pair<htmlparser::DatabaseUrl,long long>(urlLink,urlLink.GetUrlID()));
		}
		catch(const network::HttpUrlParserException& ex) {
			if(log::Logging::IsLogLevelTrace()) {
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE,
						"exception while trying to add url %s to database",iterUrls->GetFullUrl().c_str());
			}
		}
	}

	if(mapUrls.size()>0)
	{
		std::vector<database::TableBase> vecLinks;
		std::map<htmlparser::DatabaseUrl,long long>::iterator iterInsertLinks = mapUrls.begin();

		for(int i=0; iterInsertLinks != mapUrls.end(); i++,++iterInsertLinks) {

			if(entry.urlID <= 0 || entry.urlStageID <=0 || iterInsertLinks->second<=0){
				log::Logging::Log(log::Logging::LOGLEVEL_ERROR, "error while inserting links, invalid ids: \nurlID: %ll urlStageID: %ll %s",entry.urlID, entry.urlStageID, iterInsertLinks->first.GetFullUrl().c_str());
				i--;
				continue;
			}

			std::vector<database::TableColumnDefinition*> colDefsSum;
			colDefsSum.push_back(database::hyperlinksTableBase::GetDefinition_count());

			database::hyperlinksTableBase tblLinks;
			tblLinks.Set_URLSTAGE_ID(entry.urlStageID);
			tblLinks.Set_TARGET_URL_ID(iterInsertLinks->second);
			tblLinks.Set_count(1);
			tblLinks.InsertOrUpdate(DB().Connection(),colDefsSum);
		}
	}
}

void GenericWebHtmlParserThread::InsertMeta(const HtmlParserEntry& entry, const std::vector<std::pair<std::string,std::string> >& meta)
{
	std::vector<std::pair<std::string,std::string> >::const_iterator iterMeta = meta.begin();
	std::vector<database::metainfoTableBase> vecMeta;
	for(;iterMeta!=meta.end();++iterMeta) {

		database::metainfoTableBase tblMeta;
		tblMeta.Set_URLSTAGE_ID(entry.urlStageID);
		tblMeta.Set_value(iterMeta->second);

		if(iterMeta->first.compare("keywords") == 0) {
			tblMeta.Set_type(1);
			tblMeta.Insert(DB().Connection());}
		else if (iterMeta->first.compare("description") == 0){
			tblMeta.Set_type(2);
			tblMeta.Insert(DB().Connection());}
		else if (iterMeta->first.compare("title") == 0){
			tblMeta.Set_type(3);
			tblMeta.Insert(DB().Connection());}
	}
}

}
