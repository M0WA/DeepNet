/**
 *
 * @file LibXMLParserResult.cpp
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#include "LibXMLParserResult.h"

namespace libxmlparser {

LibXMLParserResult::LibXMLParserResult(const htmlparser::DatabaseUrl& url)
: htmlparser::IHtmlParserResult(url)
{
}

LibXMLParserResult::~LibXMLParserResult() {
}


}
