/*
 * UrlInserter.cpp
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#include "UrlInserter.h"

#include <iostream>

#include <CacheDatabaseUrl.h>
#include <FileTools.h>
#include <StringTools.h>
#include <Regex.h>
#include <Exception.h>

#include "DatabaseUrl.h"

/*
#include <Logging.h>
#include <DatabaseLayer.h>
#include <Bot.h>
*/

namespace htmlparser {

UrlInserter::UrlInserter()
{
}

UrlInserter::~UrlInserter()
{
}

bool UrlInserter::InsertURLFile(database::DatabaseConnection* db,const std::multimap<std::string,std::string>& fileContent)
{
	std::multimap<std::string,std::string>::const_iterator iterUrl = fileContent.begin();
	for(;iterUrl!=fileContent.end();++iterUrl){
		if(!InsertURL(db,iterUrl->first,iterUrl->second) ){
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error while inserting url: %s",iterUrl->second.c_str());}
	}
	return true;
}

bool UrlInserter::ValidateURLFile(database::DatabaseConnection* db,const std::multimap<std::string,std::string>& fileContent)
{
	std::multimap<std::string,std::string>::const_iterator iterUrl = fileContent.begin();
	for(;iterUrl!=fileContent.end();++iterUrl){

		try {
			ValidateURL(db,iterUrl->first,iterUrl->second);
		}
		catch(...) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"url: %s is VALID", iterUrl->second.c_str());
		}
	}
	return true;
}

DatabaseUrl UrlInserter::ValidateURL(database::DatabaseConnection* db,const std::string& sDomain, const std::string& sUrl, bool dumpUrl)
{
	try {
		DatabaseUrl url = (!sDomain.empty()) ?
			caching::CacheDatabaseUrl::GetByUrlString( db, sUrl, caching::CacheDatabaseUrl::GetByUrlString( db, sDomain ) ) :
			caching::CacheDatabaseUrl::GetByUrlString( db, sUrl ) ;

		if (dumpUrl){
			std::string urlDump;
			url.Dump(urlDump);
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"dumping URL: %s  => %s\n%s",sUrl.c_str(),sDomain.c_str(),urlDump.c_str());
		}
		return url;
	}
	catch(errors::Exception& e) {

		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid url: %s",sUrl.c_str());
		throw;
	}
}

bool UrlInserter::InsertURL(database::DatabaseConnection* db,const std::string& sDomain, const std::string& sUrl){

	bool success = true;
	try {
		DatabaseUrl url = ValidateURL(db,sDomain,sUrl,false);
		url = caching::CacheDatabaseUrl::GetByUrlString(db,sUrl,sDomain);

		if(url.GetUrlID() <= 0){
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not insert url " + url.GetFullUrl());
			success = false;
		}
	}
	catch(...) {
		success = false;
	}

	return success;
}

int UrlInserter::ReadURLFile(const std::string& fileName, std::multimap<std::string,std::string>& fileContent)
{
	std::vector<std::string> lines;
	bool bSuccessReadFile = tools::FileTools::ReadFile(fileName,lines);
	if(!bSuccessReadFile)
		return 0;

	std::vector<std::string>::iterator iterLines = lines.begin();
	for(;iterLines != lines.end();++iterLines) {

		std::vector<std::string> groups;
		if(!tools::Regex::Match("^\"(.*)\".*,.*\"(.*)\".*",iterLines->c_str(),groups,true)
		 || groups.size() < 2 ) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not parse \"%s\", skipping...", iterLines->c_str());
			continue; }

		std::string domain = groups.at(0);
		std::string url    = groups.at(1);

		fileContent.insert(std::pair<std::string,std::string>(domain,url));
	}

	return lines.size();
}

}
