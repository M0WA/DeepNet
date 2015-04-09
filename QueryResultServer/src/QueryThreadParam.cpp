/**
 *
 * @file QueryThreadParam.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryThreadParam.h"

namespace queryserver {

QueryThreadParam::QueryThreadParam(database::DatabaseConnection* dbConn, const Query& query)
: dbConn(dbConn)
, query(query){
}

QueryThreadParam::~QueryThreadParam() {
}

QueryDictionaryThreadParam::QueryDictionaryThreadParam(database::DatabaseConnection* dbConn, const Query& query, const DictionaryInfoThread* dictInfo)
: QueryThreadParam(dbConn,query)
, dictInfo(dictInfo){
}

}
