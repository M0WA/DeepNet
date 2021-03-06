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

    //creating column definition for resultXML
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_resultXML());

    //creating column definition for position
    columnDefinitions.push_back(queryresultsTableBase::GetDefinition_position());


	std::vector<std::string> tmpCombined;

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
