#include "docmetaTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "docmetaTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

docmetaTableDefinitionCreateParam::docmetaTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"docmeta") {

    CreateColumnDefinitions();
}

docmetaTableDefinitionCreateParam::~docmetaTableDefinitionCreateParam() {
}

void docmetaTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_DICT_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for occurrence
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_occurrence());

    //creating column definition for type
    columnDefinitions.push_back(docmetaTableBase::GetDefinition_type());


	std::vector<std::string> tmpCombined;

}

std::string docmetaTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "lexicon";
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
