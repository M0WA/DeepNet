/**
 *
 * @file DOMParser.cpp
 * @author Moritz Wagner
 * @date 09.06.2013
 *
 */

#include "DOMParser.h"

namespace domparser {

DOMParser::DOMParser() {
}

DOMParser::~DOMParser() {
}

bool DOMParser::Parse(const network::HtmlData& html, tools::Pointer<htmlparser::IHtmlParserResult>& result) {
	return false;
}

}
