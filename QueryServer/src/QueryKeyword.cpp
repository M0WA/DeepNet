/**
 *
 * @file QueryKeyword.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryKeyword.h"

#include <StringTools.h>

namespace queryserver {

QueryKeyword::QueryKeyword()
: position(-1)
, keyword("")
, keywordLowered("")
, caseSensitive(false) {
}

QueryKeyword::QueryKeyword(const long long& position,const std::string& keyword,const bool caseSensitive)
: position(position)
, keyword(keyword)
, keywordLowered(tools::StringTools::ToLowerNP(keyword))
, caseSensitive(caseSensitive){
}

QueryKeyword::~QueryKeyword() {
}

}
