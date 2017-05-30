#include "searchqueryresultinfoTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "searchqueryresultinfoTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

searchqueryresultinfoTableDefinitionCreateParam::searchqueryresultinfoTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"searchqueryresultinfo") {

    CreateColumnDefinitions();
}

searchqueryresultinfoTableDefinitionCreateParam::~searchqueryresultinfoTableDefinitionCreateParam() {
}

void searchqueryresultinfoTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(searchqueryresultinfoTableBase::GetDefinition_ID());

    //creating column definition for SEARCHQUERYRESULT_ID
    columnDefinitions.push_back(searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID());

    //creating column definition for infotype
    columnDefinitions.push_back(searchqueryresultinfoTableBase::GetDefinition_infotype());

    //creating column definition for type
    columnDefinitions.push_back(searchqueryresultinfoTableBase::GetDefinition_type());


	std::vector<std::string> tmpCombined;

}

std::string searchqueryresultinfoTableDefinitionCreateParam::GetDatabaseName() {
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
