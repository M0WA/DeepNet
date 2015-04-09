#include "queryresultthreadTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "queryresultthreadTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

queryresultthreadTableDefinitionCreateParam::queryresultthreadTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"queryresultthread") {

    CreateColumnDefinitions();
}

queryresultthreadTableDefinitionCreateParam::~queryresultthreadTableDefinitionCreateParam() {
}

void queryresultthreadTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(queryresultthreadTableBase::GetDefinition_ID());


	std::vector<std::string> tmpCombined;

}

std::string queryresultthreadTableDefinitionCreateParam::GetDatabaseName() {
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
