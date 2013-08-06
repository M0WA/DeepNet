#include "urlsearchpartsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "urlsearchpartsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

urlsearchpartsTableDefinitionCreateParam::urlsearchpartsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"urlsearchparts") {

    CreateColumnDefinitions();
}

urlsearchpartsTableDefinitionCreateParam::~urlsearchpartsTableDefinitionCreateParam() {
}

void urlsearchpartsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(urlsearchpartsTableBase::GetDefinition_ID());

    //creating column definition for searchpart
    columnDefinitions.push_back(urlsearchpartsTableBase::GetDefinition_searchpart());

    //creating column definition for md5
    columnDefinitions.push_back(urlsearchpartsTableBase::GetDefinition_md5());


	std::vector<std::string> tmpCombined;

}

std::string urlsearchpartsTableDefinitionCreateParam::GetDatabaseName() {
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
