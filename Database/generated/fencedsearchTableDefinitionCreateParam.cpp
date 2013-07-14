#include "fencedsearchTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "fencedsearchTableBase.h"
#include "DatabaseHelper.h"

namespace database {

fencedsearchTableDefinitionCreateParam::fencedsearchTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"fencedsearch") {

    CreateColumnDefinitions();
}

fencedsearchTableDefinitionCreateParam::~fencedsearchTableDefinitionCreateParam() {
}

void fencedsearchTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMER_ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_CUSTOMER_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

}

std::string fencedsearchTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "datamining";
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
