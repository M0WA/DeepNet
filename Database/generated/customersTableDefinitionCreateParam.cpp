#include "customersTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customersTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customersTableDefinitionCreateParam::customersTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customers") {

    CreateColumnDefinitions();
}

customersTableDefinitionCreateParam::~customersTableDefinitionCreateParam() {
}

void customersTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customersTableBase::GetDefinition_ID());

    //creating column definition for login
    columnDefinitions.push_back(customersTableBase::GetDefinition_login());

    //creating column definition for password
    columnDefinitions.push_back(customersTableBase::GetDefinition_password());

}

std::string customersTableDefinitionCreateParam::GetDatabaseName() {
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
