/*
 * HtmlSAX2Document.cpp
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Document.h"

#include <sstream>

#include <ContainerTools.h>

namespace htmlparser {

HtmlSAX2Document::HtmlSAX2Document(const htmlparser::DatabaseUrl& url)
: url(url) {
}

HtmlSAX2Document::~HtmlSAX2Document() {
}

void HtmlSAX2Document::Reset() {
	elements.clear();
	hyperlinks.clear();
	images.clear();
	content.clear();
	meta.clear();
	warnings.clear();
	errors.clear();
	fatals.clear();
}

void HtmlSAX2Document::DumpXML(std::string& xmlContent) {

	std::ostringstream xmlOut;
	xmlOut
	<< "<document>\n"
	<< "<links>\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = hyperlinks.begin(); iter != hyperlinks.end(); ++iter) {
		xmlOut << "\t<link>" << iter->GetFullUrl() << "</link>\n"; }
	xmlOut
	<< "</links>\n"
	<< "<images>\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = images.begin(); iter != images.end(); ++iter) {
		xmlOut << "\t<image>" << iter->GetFullUrl() << "</image>\n"; }
	xmlOut
	<< "</images>\n"
	<< "<elements>\n";
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = content.begin(); iter != content.end(); ++iter) {
		xmlOut << "\t<content type=\"" << iter->first << "\">" << iter->second << "</content>\n"; }
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = meta.begin(); iter != meta.end(); ++iter) {
		xmlOut << "\t<meta type=\"" << iter->first << "\">" << iter->second << "</meta>\n"; }
	xmlOut
	<< "</elements>\n"
	<< "<errors>\n";
	for(std::vector< std::string >::const_iterator iter = warnings.begin(); iter != warnings.end(); ++iter) {
		xmlOut << "\t<warnings>" << *iter << "</warnings>\n"; }
	for(std::vector< std::string >::const_iterator iter = errors.begin(); iter != errors.end(); ++iter) {
		xmlOut << "\t<errors>" << *iter << "</errors>\n"; }
	for(std::vector< std::string >::const_iterator iter = fatals.begin(); iter != fatals.end(); ++iter) {
		xmlOut << "\t<fatals>" << *iter << "</fatals>\n"; }
	xmlOut
	<< "</errors>\n"
	<< "</document>";
	xmlContent = xmlOut.str();
}

}
