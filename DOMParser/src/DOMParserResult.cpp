/**
 *
 * @file DOMParserResult.cpp
 * @author Moritz Wagner
 * @date 09.07.2013
 *
 */

#include "DOMParserResult.h"

namespace domparser {

DOMParserResult::DOMParserResult(const caching::DatabaseUrl& url)
: htmlparser::IHtmlParserResult(url)
{
}

DOMParserResult::~DOMParserResult() {
}

}
