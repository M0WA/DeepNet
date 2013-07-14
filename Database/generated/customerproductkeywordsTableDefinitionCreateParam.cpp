#include "customerproductkeywordsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customerproductkeywordsTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customerproductkeywordsTableDefinitionCreateParam::customerproductkeywordsTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customerproductkeywords") {

    CreateColumnDefinitions();
}

customerproductkeywordsTableDefinitionCreateParam::~customerproductkeywordsTableDefinitionCreateParam() {
}

void customerproductkeywordsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_ID());

    //creating column definition for PRODUCT_ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(customerproductkeywordsTableBase::GetDefinition_DICT_ID());

}

std::string customerproductkeywordsTableDefinitionCreateParam::GetDatabaseName() {
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
