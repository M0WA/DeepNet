#include "crawlersessionsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "crawlersessionsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

crawlersessionsTableDefinitionCreateParam::crawlersessionsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"crawlersessions") {

    CreateColumnDefinitions();
}

crawlersessionsTableDefinitionCreateParam::~crawlersessionsTableDefinitionCreateParam() {
}

void crawlersessionsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(crawlersessionsTableBase::GetDefinition_ID());


	std::vector<std::string> tmpCombined;

}

std::string crawlersessionsTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "sync";
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
