#include "customerqueriesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerqueriesTableBase.h"
#include "DatabaseHelper.h"

namespace database {

customerqueriesTableDefinitionCreateParam::customerqueriesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerqueries") {

    CreateColumnDefinitions();
}

customerqueriesTableDefinitionCreateParam::~customerqueriesTableDefinitionCreateParam() {
}

void customerqueriesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for query
    columnDefinitions.push_back(customerqueriesTableBase::GetDefinition_query());

}

std::string customerqueriesTableDefinitionCreateParam::GetDatabaseName() {
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
