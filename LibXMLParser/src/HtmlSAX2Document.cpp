/*
 * HtmlSAX2Document.cpp
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Document.h"

#include <sstream>

#include <ContainerTools.h>
#include <CharsetEncoder.h>

namespace libxmlparser {

HtmlSAX2Document::HtmlSAX2Document(const htmlparser::DatabaseUrl& url)
: result(url)
, url(url)
, wellformed(0){
}

HtmlSAX2Document::~HtmlSAX2Document() {
}

void HtmlSAX2Document::Reset() {
	elements.clear();
	result.hyperlinks.clear();
	result.images.clear();
	result.content.clear();
	result.meta.clear();
	result.warnings.clear();
	result.errors.clear();
	result.fatals.clear();
	wellformed = 0;
}

void HtmlSAX2Document::DumpXML(std::string& xmlContent) {
	std::ostringstream xmlOut;
	xmlOut <<
	"<document wellformed=\""<< wellformed <<"\" url=\""<< url.GetFullUrl() <<"\">\n"
	"<links count=\""<< result.hyperlinks.size() <<"\">\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = result.hyperlinks.begin(); iter != result.hyperlinks.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->GetFullUrl(), out);
		xmlOut << "\t<link>" << out << "</link>\n"; }
	xmlOut <<
	"</links>\n"
	"<images count=\""<< result.images.size() <<"\">\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = result.images.begin(); iter != result.images.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->GetFullUrl(), out);
		xmlOut << "\t<image>" << out << "</image>\n"; }
	xmlOut <<
	"</images>\n"
	"<elements content=\""<< result.content.size() <<"\" meta=\""<< result.meta.size() <<"\">\n";
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = result.content.begin(); iter != result.content.end(); ++iter) {
		std::string out1, out2;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->first, out1);
		tools::CharsetEncoder::EncodeHtmlEntities(iter->second, out2);
		xmlOut << "\t<content type=\"" << out1 << "\">" << out2 << "</content>\n"; }
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = result.meta.begin(); iter != result.meta.end(); ++iter) {
		std::string out1, out2;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->first, out1);
		tools::CharsetEncoder::EncodeHtmlEntities(iter->second, out2);
		xmlOut << "\t<meta type=\"" << out1 << "\">" << out2 << "</meta>\n"; }
	xmlOut <<
	"</elements>\n"
	"<errors warnings=\""<< result.warnings.size() <<"\" errors=\""<< result.errors.size() <<"\" fatals=\""<< result.fatals.size() <<"\">\n";
	for(std::vector< std::string >::const_iterator iter = result.warnings.begin(); iter != result.warnings.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<warning>" << out << "</warning>\n"; }
	for(std::vector< std::string >::const_iterator iter = result.errors.begin(); iter != result.errors.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<error>" << out << "</error>\n"; }
	for(std::vector< std::string >::const_iterator iter = result.fatals.begin(); iter != result.fatals.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<fatal>" << out << "</fatal>\n"; }
	xmlOut <<
	"</errors>\n"
	"</document>";

	xmlContent = xmlOut.str();
}

}
