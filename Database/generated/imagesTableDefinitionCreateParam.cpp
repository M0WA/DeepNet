#include "imagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "imagesTableBase.h"

namespace database {

imagesTableDefinitionCreateParam::imagesTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","images") {

    CreateColumnDefinitions();
}

imagesTableDefinitionCreateParam::~imagesTableDefinitionCreateParam() {
}

void imagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_ID());

    //creating column definition for SCHEME_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SCHEME_ID());

    //creating column definition for TOPLEVELDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID());

    //creating column definition for SUBDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SUBDOMAIN_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for port
    columnDefinitions.push_back(imagesTableBase::GetDefinition_port());

    //creating column definition for path_part
    columnDefinitions.push_back(imagesTableBase::GetDefinition_path_part());

    //creating column definition for search_part
    columnDefinitions.push_back(imagesTableBase::GetDefinition_search_part());

    //creating column definition for url_md5
    columnDefinitions.push_back(imagesTableBase::GetDefinition_url_md5());

    //creating column definition for found_date
    columnDefinitions.push_back(imagesTableBase::GetDefinition_found_date());

}

}
