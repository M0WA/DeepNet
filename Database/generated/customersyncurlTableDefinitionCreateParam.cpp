#include "customersyncurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersyncurlTableBase.h"
#include "DatabaseHelper.h"

namespace database {

customersyncurlTableDefinitionCreateParam::customersyncurlTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customersyncurl") {

    CreateColumnDefinitions();
}

customersyncurlTableDefinitionCreateParam::~customersyncurlTableDefinitionCreateParam() {
}

void customersyncurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_URL_ID());

    //creating column definition for scheduled
    columnDefinitions.push_back(customersyncurlTableBase::GetDefinition_scheduled());

}

std::string customersyncurlTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "commercesearch";
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
