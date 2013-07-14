#include "subdomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "subdomainsTableBase.h"
#include "DatabaseHelper.h"

namespace database {

subdomainsTableDefinitionCreateParam::subdomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"subdomains") {

    CreateColumnDefinitions();
}

subdomainsTableDefinitionCreateParam::~subdomainsTableDefinitionCreateParam() {
}

void subdomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(subdomainsTableBase::GetDefinition_ID());

    //creating column definition for subdomain
    columnDefinitions.push_back(subdomainsTableBase::GetDefinition_subdomain());

}

std::string subdomainsTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "documents";
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
