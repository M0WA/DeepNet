#include "urlsTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "urlsTableBase.h"

namespace database {

urlsTableDefinitionCreateParam::urlsTableDefinitionCreateParam()
: TableDefinitionCreateParam("documents","urls") {

    CreateColumnDefinitions();
}

urlsTableDefinitionCreateParam::~urlsTableDefinitionCreateParam() {
}

void urlsTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(urlsTableBase::GetDefinition_ID());

    //creating column definition for SCHEME_ID
    columnDefinitions.push_back(urlsTableBase::GetDefinition_SCHEME_ID());

    //creating column definition for TOPLEVELDOMAIN_ID
    columnDefinitions.push_back(urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID());

    //creating column definition for SUBDOMAIN_ID
    columnDefinitions.push_back(urlsTableBase::GetDefinition_SUBDOMAIN_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for port
    columnDefinitions.push_back(urlsTableBase::GetDefinition_port());

    //creating column definition for path_part
    columnDefinitions.push_back(urlsTableBase::GetDefinition_path_part());

    //creating column definition for search_part
    columnDefinitions.push_back(urlsTableBase::GetDefinition_search_part());

    //creating column definition for url_md5
    columnDefinitions.push_back(urlsTableBase::GetDefinition_url_md5());

    //creating column definition for found_date
    columnDefinitions.push_back(urlsTableBase::GetDefinition_found_date());

}

}
