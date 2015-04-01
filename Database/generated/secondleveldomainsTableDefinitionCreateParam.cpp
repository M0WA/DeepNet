#include "secondleveldomainsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "secondleveldomainsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

secondleveldomainsTableDefinitionCreateParam::secondleveldomainsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"secondleveldomains") {

    CreateColumnDefinitions();
}

secondleveldomainsTableDefinitionCreateParam::~secondleveldomainsTableDefinitionCreateParam() {
}

void secondleveldomainsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(secondleveldomainsTableBase::GetDefinition_ID());

    //creating column definition for domain
    columnDefinitions.push_back(secondleveldomainsTableBase::GetDefinition_domain());


	std::vector<std::string> tmpCombined;

}

std::string secondleveldomainsTableDefinitionCreateParam::GetDatabaseName() {
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
