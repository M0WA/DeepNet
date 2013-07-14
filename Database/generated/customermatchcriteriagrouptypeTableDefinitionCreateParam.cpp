#include "customermatchcriteriagrouptypeTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "customermatchcriteriagrouptypeTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

customermatchcriteriagrouptypeTableDefinitionCreateParam::customermatchcriteriagrouptypeTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"customermatchcriteriagrouptype") {

    CreateColumnDefinitions();
}

customermatchcriteriagrouptypeTableDefinitionCreateParam::~customermatchcriteriagrouptypeTableDefinitionCreateParam() {
}

void customermatchcriteriagrouptypeTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_ID());

    //creating column definition for CUSTOMERMATCHCRITERIA_ID
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());

    //creating column definition for type
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_type());

    //creating column definition for groupPosition
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition());

    //creating column definition for isPrimaryKey
    columnDefinitions.push_back(customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey());

}

std::string customermatchcriteriagrouptypeTableDefinitionCreateParam::GetDatabaseName() {
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
