/*
 * HtmlTester.cpp
 *
 *  Created on: 22.04.2012
 *      Author: Moritz Wagner
 */

#include "HtmlTester.h"

#include "URL.h"

#include <iostream>
#include <sstream>

#include <IndexerTester.h>
#include <Exception.h>

#include "UrlParser.h"
#include "HtmlSAX2Parser.h"
#include "CacheUrl.h"

namespace htmlparser {

HtmlTester::HtmlTester() {
}

HtmlTester::~HtmlTester() {
}

bool HtmlTester::ParseHtml(database::DatabaseConnection* db,const std::string& url, const std::string& htmlCode, HtmlTesterResult& result)
{
	result.url = url;

	HtmlSAX2Parser htmlParser;
	bool bSuccess = htmlParser.Parse(url,htmlCode);

	htmlParser.Content(result.contentElements);
	htmlParser.HyperLinks(result.hyperLinks);
	htmlParser.Images(result.images);
	htmlParser.Meta(result.metaElements);
	htmlParser.Warnings(result.warnings);
	htmlParser.Errors(result.errors);
	htmlParser.FatalErrors(result.fatals);

	if(!bSuccess) {
		result.warnings.push_back("parsable but invalid html");}

	return true;
}

bool HtmlTester::ParseHtmlFromFile(database::DatabaseConnection* db,const std::string& url, const std::string& htmlFile, HtmlTesterResult& result)
{
	std::string htmlCode;
	if(!tools::StringTools::ReadFile(htmlFile,htmlCode)){
		return false;}
	return ParseHtml(db,url, htmlCode, result);
}

std::string HtmlTesterResult::ToString(database::DatabaseConnection* db) const
{
	std::stringstream ssIn;
	ssIn << "======= statistics ======="                     << std::endl;
	ssIn << "\tfatal errors    : " << fatals.size()          << std::endl;
	ssIn << "\terrors          : " << errors.size()          << std::endl;
	ssIn << "\twarnings        : " << warnings.size()        << std::endl;
	ssIn << "\tcontent elements: " << contentElements.size() << std::endl;
	ssIn << "\tmeta elements   : " << metaElements.size()    << std::endl;
	ssIn << "\tlinks           : " << hyperLinks.size()      << std::endl;
	ssIn << "\timages          : " << images.size()          << std::endl;

	if(fatals.size()>0)	{
		ssIn << std::endl << "======= fatals    =======" << std::endl;
		std::vector<std::string>::const_iterator iterFatals = fatals.begin();
		for(;iterFatals != fatals.end(); ++iterFatals){
			ssIn << *iterFatals << std::endl;
		}
	}

	if(errors.size()>0)	{
		ssIn << std::endl << "======= errors    =======" << std::endl;
		std::vector<std::string>::const_iterator iterErrors = errors.begin();
		for(;iterErrors != errors.end(); ++iterErrors){
			ssIn << *iterErrors << std::endl;
		}
	}

	if(warnings.size()>0) {
		ssIn << std::endl << "======= warnings   =======" << std::endl;
		std::vector<std::string>::const_iterator iterWarnings = warnings.begin();
		for(;iterWarnings != warnings.end(); ++iterWarnings){
			ssIn << *iterWarnings << std::endl;
		}
	}

	if(hyperLinks.size()>0)	{
		ssIn << std::endl << "======= links      =======" << std::endl << std::endl;
		std::vector<std::string>::const_iterator iterLinks = hyperLinks.begin();
		for(;iterLinks != hyperLinks.end(); ++iterLinks){
			URL urlLink;
			ssIn << "\t--------------" << std::endl << std::endl;
			try {
				caching::CacheUrl::GetBy_UrlString(db,*iterLinks,urlLink);
			}
			catch(errors::Exception& e){

				ssIn  << std::endl  << std::endl << "!!! INVALID LINK !!! : " << *iterLinks << std::endl << std::endl << std::endl;
			}

			std::string fullLinkUrlDump;
			urlLink.Dump(fullLinkUrlDump);
			ssIn << "Dumping " << *iterLinks << std::endl;
			ssIn << fullLinkUrlDump << std::endl;
		}
	}

	if(metaElements.size() > 0) {
		ssIn << std::endl << "======= meta       =======" << std::endl;
		std::vector<std::pair<std::string,std::string> >::const_iterator iterMeta = metaElements.begin();
		for(;iterMeta != metaElements.end(); ++iterMeta){
			ssIn << "tag: " << iterMeta->first << ", content: " << iterMeta->second << std::endl;
		}
	}

	if(images.size() > 0) {
		ssIn << std::endl << "======= images     =======" << std::endl;
		std::vector<std::string>::const_iterator iterImages = images.begin();
		for(;iterImages != images.end(); ++iterImages){
			ssIn << *iterImages << std::endl;
		}
	}

	if(contentElements.size() > 0) {
		ssIn << std::endl << "======= content     =======" << std::endl;
		std::vector<std::pair<std::string,std::string> >::const_iterator iterContent = contentElements.begin();
		for(;iterContent != contentElements.end(); ++iterContent){
			ssIn << "tag: " << iterContent->first << ", content: " << iterContent->second << std::endl;
			//indexing::IndexerTester::Parse(database,*iterContent->second);
		}
	}

	return ssIn.str();
}

std::string HtmlTesterResult::ToXML_intern(database::DatabaseConnection* db) const
{
	std::stringstream ssIn;

	//process errors
	if(fatals.size()>0)	{
		ssIn << "<fatals>" << std::endl;
		std::vector<std::string>::const_iterator iterFatals = fatals.begin();
		for(int i=1;iterFatals != fatals.end(); i++,++iterFatals){
			std::string encoded = *iterFatals;
			UrlParser::EncodeUrl(encoded);
			ssIn << "<message id=\"" << i << "\">" << encoded <<"</message>" << std::endl;
		}
		ssIn << "</fatals>" << std::endl;
	}

	if(errors.size()>0)	{
		ssIn << "<errors>" << std::endl;
		std::vector<std::string>::const_iterator iterErrors = errors.begin();
		for(int i=1;iterErrors != errors.end(); i++,++iterErrors){
			std::string encoded = *iterErrors;
			UrlParser::EncodeUrl(encoded);
			ssIn << "<message id=\"" << i << "\">" << encoded <<"</message>" << std::endl;
		}
		ssIn << "</errors>" << std::endl;
	}

	if(warnings.size()>0) {
		ssIn << "<warnings>" << std::endl;
		std::vector<std::string>::const_iterator iterWarnings = warnings.begin();
		for(int i=1;iterWarnings != warnings.end(); i++,++iterWarnings){
			std::string encoded = *iterWarnings;
			UrlParser::EncodeUrl(encoded);
			ssIn << "<message id=\"" << i << "\">" << encoded <<"</message>" << std::endl;
		}
		ssIn << "</warnings>" << std::endl;
	}

	//process meta information
	if(metaElements.size() > 0) {
		ssIn << "<metaInfo>" << std::endl;
		std::vector<std::pair<std::string,std::string> >::const_iterator iterMeta = metaElements.begin();
		for(int i=1;iterMeta != metaElements.end(); i++,++iterMeta){
			std::string encodeFirst=iterMeta->first,encodeSecond=iterMeta->second;
			UrlParser::EncodeUrl(encodeFirst);
			UrlParser::EncodeUrl(encodeSecond);
			ssIn << "<metaTag id=\"" << i << "\">"
			"<name>"  << encodeFirst << "</name>"
			"<value>" << encodeSecond << "</value>"
			"</metaTag>" << std::endl;
		}
		ssIn << "</metaInfo>" << std::endl;
	}
	return ssIn.str();
}

std::string HtmlTesterResult::ToXML(database::DatabaseConnection* db) const
{
	std::stringstream ssIn;
	ssIn << ToXML_intern(db);

	//process links
	if(hyperLinks.size()>0)	{
		ssIn << "<urls>" << std::endl;
		std::vector<std::string>::const_iterator iterLinks = hyperLinks.begin();
		for(int i=1;iterLinks != hyperLinks.end(); i++,++iterLinks){

			ssIn <<
			"<url id=\"" << i << "\"><fullurl>";

			URL urlLink;
			try {
				caching::CacheUrl::GetBy_UrlString(db,*iterLinks,urlLink);
				std::string encodedUrl = urlLink.GetFullUrl();
				UrlParser::EncodeUrl(encodedUrl);
				ssIn << encodedUrl;
			}
			catch(errors::Exception& e){

				ssIn << "INVALID";
			}

			ssIn << "</fullurl></url>" << std::endl;
		}
		ssIn << "</urls>" << std::endl;
	}
	return ssIn.str();
}

std::string HtmlTesterResult::ToXML(database::DatabaseConnection* db,const URL& baseURL) const
{
	std::stringstream ssIn;
	ssIn << ToXML_intern(db);

	//process links
	if(hyperLinks.size()>0)	{
		ssIn << "<urls>" << std::endl;
		std::vector<std::string>::const_iterator iterLinks = hyperLinks.begin();
		for(int i=1;iterLinks != hyperLinks.end(); i++,++iterLinks){

			ssIn <<
			"<url id=\"" << i << "\"><fullurl>";

			URL urlLink;
			try {
				caching::CacheUrl::GetBy_UrlString(db,*iterLinks,urlLink);
				std::string encodedUrl = urlLink.GetFullUrl();
				UrlParser::EncodeUrl(encodedUrl);
				ssIn << encodedUrl;
			}
			catch(errors::Exception& e){

				ssIn << "INVALID";
			}

			ssIn << "</fullurl></url>" << std::endl;
		}
		ssIn << "</urls>" << std::endl;
	}

	return ssIn.str();
}

}
