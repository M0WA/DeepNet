#include "documentcodeTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "documentcodeTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

documentcodeTableDefinitionCreateParam::documentcodeTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"documentcode") {

    CreateColumnDefinitions();
}

documentcodeTableDefinitionCreateParam::~documentcodeTableDefinitionCreateParam() {
}

void documentcodeTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_ID());

    //creating column definition for URLSTAGE_ID
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_URLSTAGE_ID());

    //creating column definition for code
    columnDefinitions.push_back(documentcodeTableBase::GetDefinition_code());

}

std::string documentcodeTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "contents";
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
