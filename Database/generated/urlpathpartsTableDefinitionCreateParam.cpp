#include "urlpathpartsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "urlpathpartsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

urlpathpartsTableDefinitionCreateParam::urlpathpartsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"urlpathparts") {

    CreateColumnDefinitions();
}

urlpathpartsTableDefinitionCreateParam::~urlpathpartsTableDefinitionCreateParam() {
}

void urlpathpartsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(urlpathpartsTableBase::GetDefinition_ID());

    //creating column definition for PATHPART_ID
    columnDefinitions.push_back(urlpathpartsTableBase::GetDefinition_PATHPART_ID());

    //creating column definition for URLPATHPART_ID_NEXT
    columnDefinitions.push_back(urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT());


	std::vector<std::string> tmpCombined;
	tmpCombined.clear();
	tmpCombined.push_back("PATHPART_ID");
	tmpCombined.push_back("URLPATHPART_ID_NEXT");
	combinedUniqueKeys.push_back(tmpCombined);

}

std::string urlpathpartsTableDefinitionCreateParam::GetDatabaseName() {
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
