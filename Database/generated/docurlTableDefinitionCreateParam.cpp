#include "docurlTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "docurlTableBase.h"

namespace database {

docurlTableDefinitionCreateParam::docurlTableDefinitionCreateParam()
: TableDefinitionCreateParam("lexicon","docurl") {

    CreateColumnDefinitions();
}

docurlTableDefinitionCreateParam::~docurlTableDefinitionCreateParam() {
}

void docurlTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_ID());

    //creating column definition for DICT_ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_DICT_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(docurlTableBase::GetDefinition_URL_ID());

}

}
