/**
 *
 * @file QueryThreadParam.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryThreadParam.h"

namespace queryserver {

QueryThreadParam::QueryThreadParam(const database::DatabaseConfig* config, const Query& query)
: config(config)
, query(query){
}

QueryThreadParam::~QueryThreadParam() {
}

}
