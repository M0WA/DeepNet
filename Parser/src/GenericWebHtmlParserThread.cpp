/*
 * GenericWebHtmlParserThread.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebHtmlParserThread.h"

#include <Logging.h>
#include <PerformanceCounter.h>
#include <Exception.h>

#include <CacheDatabaseUrl.h>
#include <CacheParsed.h>

#include <DatabaseUrl.h>
#include <TLD.h>

namespace parser {

GenericWebHtmlParserThread::GenericWebHtmlParserThread() {
}

GenericWebHtmlParserThread::~GenericWebHtmlParserThread() {
}

bool GenericWebHtmlParserThread::ParsePage(const HtmlParserEntry& entry,htmlparser::Document* parsedDoc) {

	PERFORMANCE_LOG_START;

	std::vector<htmlparser::DatabaseUrl> hyperLinks, imagesLinks, videosLinks;
	std::vector<std::string> content;
	std::vector< std::pair<std::string,std::string> > meta;
	std::vector<std::string> titles,descriptions;

	//
	//TODO:
	//

	/*
	parsedDoc->GetLinks(hyperLinks);
	parsedDoc->GetText(content);
	parsedDoc->GetImages(imagesLinks);
	//parsedDoc->GetVideos(videosLinks);
	parsedDoc->GetMeta(htmlparser::TITLE_META,titles);
	parsedDoc->GetMeta(htmlparser::DESCRIPTION_META,descriptions);
	*/

	std::vector<std::string>::const_iterator iterTmp = titles.begin();
	for(;iterTmp != titles.end();++iterTmp) {
		meta.push_back(	std::pair<std::string,std::string>("title",*iterTmp) );
	}
	iterTmp = descriptions.begin();
	for(;iterTmp != descriptions.end();++iterTmp) {
		meta.push_back(	std::pair<std::string,std::string>("description",*iterTmp) );
	}

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
	InsertImages(entry,imagesLinks);
	PERFORMANCE_LOG_STOP("inserting found images from parsed page");

	PERFORMANCE_LOG_RESTART;
	InsertMeta(entry, meta);
	PERFORMANCE_LOG_STOP("inserting metainformation from parsed page");

	return true;
}

void GenericWebHtmlParserThread::InsertImages(const HtmlParserEntry& entry, const std::vector<htmlparser::DatabaseUrl>& images)
{
	/*
	std::vector<std::string>::iterator iterImages = images.begin();
	std::vector<database::content::tbl_images> vecImages;
	for(;iterImages != images.end(); ++iterImages) {
		URL imageUrl;
		if(!UrlParser::ParseURL(iterEntries->url.domain + "." + iterEntries->url.tld, *iterImages, imageUrl)){
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"could not convert image link to url: " + *iterImages);
			continue;}

		database::content::tbl_images imageUrlTable(DB().GetContentDB());
		if(!UrlParser::ConvertURL(imageUrl,imageUrlTable)) {
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"could not convert image link to url table entry: " + *iterImages);
			continue;}
		imageUrlTable.Set_WEBPAGE_EXTRA_ID(iterEntries->webpageExtraID);
		vecImages.push_back(imageUrlTable);
	}

	if(! database::content::tbl_images::InsertMultiple(vecImages,true) ){
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"could not insert image links to database");}
	*/
}

void GenericWebHtmlParserThread::InsertLinks(const HtmlParserEntry& entry, const std::vector<htmlparser::DatabaseUrl>& hyperlinks)
{
	if(hyperlinks.size() == 0)
		return;

	//make link strings unique
	std::vector<long long> urlIDUnique;
	std::vector<htmlparser::DatabaseUrl> uniqueLinks;
	std::vector<htmlparser::DatabaseUrl>::const_iterator iterUnique = hyperlinks.begin();
	for(; iterUnique != hyperlinks.end(); ++iterUnique) {
		if(std::find(urlIDUnique.begin(),urlIDUnique.end(),iterUnique->GetUrlID()) == urlIDUnique.end()){
			uniqueLinks.push_back(*iterUnique);
		}
	}

	htmlparser::DatabaseUrl baseUrl = caching::CacheDatabaseUrl::GetByUrlString(DB().Connection(),entry.url.GetDomain() + "." + entry.url.GetTLD());

	//convert to URLs
	std::map<htmlparser::DatabaseUrl,long long> mapUrls;
	std::vector<htmlparser::DatabaseUrl>::const_iterator iterUrls = uniqueLinks.begin();
	for(;iterUrls != uniqueLinks.end();++iterUrls) {

		//insert into cache and database
		//insert into syncurls/syncdomains table done by trigger

		try {
			htmlparser::DatabaseUrl urlLink = caching::CacheDatabaseUrl::GetByUrlString(DB().Connection(),iterUrls->GetFullUrl(),baseUrl);
			mapUrls.insert(std::pair<htmlparser::DatabaseUrl,long long>(urlLink,urlLink.GetUrlID()));
		}
		catch(...) {
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
