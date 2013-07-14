#include "queryresultsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "queryresultsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

queryresultsTableDefinitionCreateParam::queryresultsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"queryresults") {

    CreateColumnDefinitions();
}

queryresultsTableDefinitionCreateParam::~queryresultsTableDefinitionCreateParam() {
}

void queryresultsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_ID());

    //creating column definition for SEARCHQUERY_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_URL_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for order_position
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_order_position());

}

std::string queryresultsTableDefinitionCreateParam::GetDatabaseName() {
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
