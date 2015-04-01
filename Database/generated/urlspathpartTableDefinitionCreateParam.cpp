#include "urlspathpartTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "urlspathpartTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

urlspathpartTableDefinitionCreateParam::urlspathpartTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"urlspathpart") {

    CreateColumnDefinitions();
}

urlspathpartTableDefinitionCreateParam::~urlspathpartTableDefinitionCreateParam() {
}

void urlspathpartTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(urlspathpartTableBase::GetDefinition_ID());

    //creating column definition for PATHPART_ID
    columnDefinitions.push_back(urlspathpartTableBase::GetDefinition_PATHPART_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(urlspathpartTableBase::GetDefinition_URL_ID());


	std::vector<std::string> tmpCombined;
	tmpCombined.clear();
	tmpCombined.push_back("PATHPART_ID");
	tmpCombined.push_back("URL_ID");
	combinedUniqueKeys.push_back(tmpCombined);

}

std::string urlspathpartTableDefinitionCreateParam::GetDatabaseName() {
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
