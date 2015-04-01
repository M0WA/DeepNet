/**
 * @file IHtmlParser.cpp
 * @author Moritz Wagner
 * @date 02.06.2013
 */

#include "IHtmlParser.h"

#include <string>
#include <sstream>

#include <CharsetEncoder.h>

namespace htmlparser {

void IHtmlParserResult::DumpXML(std::string& xmlContent) {
	std::ostringstream xmlOut;
	xmlOut <<
	"<document wellformed=\""<< wellformed <<"\" url=\""<< url.GetFullUrl() <<"\">\n"
	"<links count=\""<< hyperlinks.size() <<"\">\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = hyperlinks.begin(); iter != hyperlinks.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->GetFullUrl(), out);
		xmlOut << "\t<link>" << out << "</link>\n"; }
	xmlOut <<
	"</links>\n"
	"<images count=\""<< images.size() <<"\">\n";
	for(std::vector<network::HttpUrl>::const_iterator iter = images.begin(); iter != images.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->GetFullUrl(), out);
		xmlOut << "\t<image>" << out << "</image>\n"; }
	xmlOut <<
	"</images>\n"
	"<elements content=\""<< content.size() <<"\" meta=\""<< meta.size() <<"\">\n";
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = content.begin(); iter != content.end(); ++iter) {
		std::string out1, out2;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->first, out1);
		tools::CharsetEncoder::EncodeHtmlEntities(iter->second, out2);
		xmlOut << "\t<content type=\"" << out1 << "\">" << out2 << "</content>\n"; }
	for(std::vector< std::pair<std::string,std::string> >::const_iterator iter = meta.begin(); iter != meta.end(); ++iter) {
		std::string out1, out2;
		tools::CharsetEncoder::EncodeHtmlEntities(iter->first, out1);
		tools::CharsetEncoder::EncodeHtmlEntities(iter->second, out2);
		xmlOut << "\t<meta type=\"" << out1 << "\">" << out2 << "</meta>\n"; }
	xmlOut <<
	"</elements>\n"
	"<errors warnings=\""<< warnings.size() <<"\" errors=\""<< errors.size() <<"\" fatals=\""<< fatals.size() <<"\">\n";
	for(std::vector< std::string >::const_iterator iter = warnings.begin(); iter != warnings.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<warning>" << out << "</warning>\n"; }
	for(std::vector< std::string >::const_iterator iter = errors.begin(); iter != errors.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<error>" << out << "</error>\n"; }
	for(std::vector< std::string >::const_iterator iter = fatals.begin(); iter != fatals.end(); ++iter) {
		std::string out;
		tools::CharsetEncoder::EncodeHtmlEntities(*iter, out);
		xmlOut << "\t<fatal>" << out << "</fatal>\n"; }
	xmlOut <<
	"</errors>\n"
	"</document>";

	xmlContent = xmlOut.str();
}

}
