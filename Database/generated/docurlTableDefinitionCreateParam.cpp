#include "docurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "docurlTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

docurlTableDefinitionCreateParam::docurlTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"docurl") {

    CreateColumnDefinitions();
}

docurlTableDefinitionCreateParam::~docurlTableDefinitionCreateParam() {
}

void docurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_DICT_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_URL_ID());

}

std::string docurlTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "lexicon";
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
