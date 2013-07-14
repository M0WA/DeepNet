#include "keywordqueryTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "keywordqueryTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

keywordqueryTableDefinitionCreateParam::keywordqueryTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"keywordquery") {

    CreateColumnDefinitions();
}

keywordqueryTableDefinitionCreateParam::~keywordqueryTableDefinitionCreateParam() {
}

void keywordqueryTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(keywordqueryTableBase::GetDefinition_ID());

    //creating column definition for query_part
    columnDefinitions.push_back(keywordqueryTableBase::GetDefinition_query_part());

}

std::string keywordqueryTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "queryserver";
    case DB_IBM_DB2:
      return "deepnet";
    case DB_POSTGRESQL:
      return "deepnet.public";
    case DB_INVALID_TYPE:
    default:
      return "";
    }
}

}
