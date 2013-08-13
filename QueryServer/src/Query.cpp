/**
 *
 * @file Query.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "Query.h"

namespace queryserver {

Query::Query() {
}

Query::Query(const std::vector<std::string>& keywords)
: keywords(keywords) {
}

Query::~Query() {
}

}
