/**
 *
 * @file QueryKeyword.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryKeyword.h"

namespace queryserver {

QueryKeyword::QueryKeyword(const long long& position,const std::string& keyword,const bool caseSensitive)
: position(position)
, keyword(keyword)
, caseSensitive(caseSensitive){
}

QueryKeyword::~QueryKeyword() {
}

}
