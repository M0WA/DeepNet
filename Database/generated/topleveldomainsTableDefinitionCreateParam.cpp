#include "topleveldomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "topleveldomainsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

topleveldomainsTableDefinitionCreateParam::topleveldomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"topleveldomains") {

    CreateColumnDefinitions();
}

topleveldomainsTableDefinitionCreateParam::~topleveldomainsTableDefinitionCreateParam() {
}

void topleveldomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(topleveldomainsTableBase::GetDefinition_ID());

    //creating column definition for tld
    columnDefinitions.push_back(topleveldomainsTableBase::GetDefinition_tld());


	std::vector<std::string> tmpCombined;

}

std::string topleveldomainsTableDefinitionCreateParam::GetDatabaseName() {
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
