#include "customermatchcriteriaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customermatchcriteriaTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customermatchcriteriaTableDefinitionCreateParam::customermatchcriteriaTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customermatchcriteria") {

    CreateColumnDefinitions();
}

customermatchcriteriaTableDefinitionCreateParam::~customermatchcriteriaTableDefinitionCreateParam() {
}

void customermatchcriteriaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERDOMAIN_ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    //creating column definition for MATCHCRITERIA_ID
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());

    //creating column definition for type
    columnDefinitions.push_back(customermatchcriteriaTableBase::GetDefinition_type());


	std::vector<std::string> tmpCombined;

}

std::string customermatchcriteriaTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "commercesearch";
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
